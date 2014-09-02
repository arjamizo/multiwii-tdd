#include <stdint.h>
#include <iostream>
#include <pthread.h>
#include "MultiWii.h"

#include "include/Timer.hpp"
#include "include/EvExpr.hpp"

#include <unistd.h>
#include "def.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <set>
#include <list>
#include <vector>
using namespace std;

int min(int a, int b) {return a<b?a:b;}
int max(int a, int b) {return a>b?a:b;}

#ifdef _WIN32
void sleep(int millis) {
    for(int i=0; i<millis*1000; ++i)
        usleep((useconds_t)(1e3));
}
#endif // _WIN32

#if not defined (PTHREADS)
typedef int pthread_t;
typedef const int pthread_attr_t;
void* pthread_create(int*, pthread_attr_t*, void* (*f)(void*), void*p) {
    return f(p);
}
#endif // PTHRAEDS

int _led;
uint8_t PWM_PIN[8];

void delay(int ms) {
    usleep(ms*1000);
}
long _rxport;
long _rxmask;
int _icr;
int SREG;
int TWSR,TWBR,TWCR,TWEN,TWINT,TWSTA,TWDR,TWSTO,TWEA;
int pin_buzzpin;

void sei() {
    //some magic with interrupt  enabling.
}

long millis()
#ifndef _MILLIS
#define _MILLIS
{
	return 0;
}
#endif
;

long micros()
#ifndef _MICROS
#define _MICROS
{
	return 0;
}
#endif
;

void cli(){};

extern void setup();
extern void loop();

int main() {
	long s=Timer::getMicros();
	std::vector<int> a;a.size();
	//for(int i=0; i<10000000; ++i) printf("");
//	cout<<"ELO "<<  (Timer::getMicros()-s);
	//cout<<
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
	#if !defined(PTHREADS)
	#else
    pthread_t tid;

	//setup();
	cout<<"Running..."<<endl;
	::pthread_create(&tid, (const pthread_attr_t*)NULL, printEach5Seconds, (void *)cout);//requires -lpthread
	#endif
	while(1) {
		usleep(1000);
		d+=0.01;
		#if not defined(PTHREADS)
		1/0;
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
