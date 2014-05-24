#include <stdint.h>
#include <iostream>
int min(int a, int b) {return a<b?a:b;}
int max(int a, int b) {return a>b?a:b;}

int _led;
uint8_t PWM_PIN[8];
#include <unistd.h>
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


#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
typedef struct Timer
#ifndef _TIMER
#define _TIMER
{
    struct timeval start, end;
    long mtime, seconds, useconds;
    Timer *begin() {
        gettimeofday(&start, NULL);
        return this;
    }
    static long getMicros() {
		struct timeval time;
        gettimeofday(&time, NULL);
        return time.tv_sec*1000000+time.tv_usec;
    }
    static long getMillis() {
		struct timeval time;
        gettimeofday(&time, NULL);
        return time.tv_sec*1000+time.tv_usec/1000;
    }
    Timer *finish() {
        gettimeofday(&end, NULL);
        seconds  = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
        return this;
    }
    long getMs() {
        return mtime;
    }
} Timer
#endif
;

using namespace std;
int main() {
	long s=Timer::getMicros();
	//for(int i=0; i<10000000; ++i) printf("");
	cout<<"ELO "<<  (Timer::getMicros()-s);
	return 0;
}
