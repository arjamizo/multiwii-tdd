#include <stdint.h>
#include <iostream>
#include <vector>
#include <set>
#include <unistd.h>
#include <Observable.h>
#include "MultiWii.h"

int min(int a, int b) {return a<b?a:b;}
int max(int a, int b) {return a>b?a:b;}

#ifdef _WIN32
void sleep(int millis) {
    for(int i=0; i<3e8; ++i);
}

typedef int pthread_t;
typedef const int pthread_attr_t;
void* pthread_create(int*, pthread_attr_t*, void* (*f)(void*), void*p) {
    return f(p);
}
#endif // _WIN32

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

extern std::set<Serializable*> vars;

using namespace std;

void *printEach5Seconds(void *cout_ptr) {
	do {
		//std::ostream &cout=*(std::ostream*)cout_ptr;
		cout<<"vars.size"<<vars.size()<<endl;
        std::vector<Serializable*> varss(vars.begin(), vars.end());
		for(int i=0; i<varss.size(); ++i) {
			cout<<"serializing ";
			cout<<std::string(*varss[i])<<endl;
		}
		sleep(1);
	}
    #ifdef PTHREAD
    while(1);
    #else
    while(0);
    #endif
	return 0;
}
