#include <set>
#include <vector>
#include <multiwii-firmware/MultiWii.h>
#include <Timer.h>
#include <Observable.h>
#include <sys/socket.h>
#include <pthread.h>
#include <iostream>

extern std::set<Serializable*> vars;

using namespace std;

#include "def.h"
#include "Arduino.h"

int main() {
    long s=Timer::getMicros();
    std::vector<int> a;
    int motor[4]={1337,7331,3317,1733};
    vector<int> motorVec(4);
    int si=4;
    double d=3.1f;

    ev("motors", motorVec, si);
    ev("motors", motor, si);
    ev("NUMBER_MOTORS", si);
    ev("alt.estalt", alt.EstAlt);
    ev("pi_estimation", d);

    d=3.14;
#if defined(PTHREAD)
    pthread_t tid;

    //setup();
    ::pthread_create(&tid, (const pthread_attr_t*)NULL, printEach5Seconds, (void *)cout);
#else

	#endif
    while(1) {
        usleep(1000);
        d+=0.01;
#if _WIN32
		printEach5Seconds((void*)&cout);
		#endif // _WIN32
    }

    vector<Serializable*> varss(vars.begin(), vars.end());
    for(int i=0; i<varss.size(); ++i) {
        delete varss[i];
        varss[i]=0;
    }
    vars.clear();
    return 0;
}
