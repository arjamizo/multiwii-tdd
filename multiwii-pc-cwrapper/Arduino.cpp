#include <stdint.h>
#include <iostream>
#include "../MultiWii.h"
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
extern void setup();
extern void loop();
#include <sstream>

template <typename STR, typename T> //str template allows accepting both std::string and char[]
class EvaluableExpression {
	string variableName;
	T &ref;
	public:
	EvaluableExpression(STR str, T &ref):ref(ref) {
		variableName=str;
	}
	operator std::string() {
		stringstream ss;
		ss<<variableName<<" "<<ref;
		return ss.str();
	}
};

template <typename STR, typename T, typename SIZE> //str template allows accepting both std::string and char[]
class EvaluableExpressionArray {
	string variableName;
	SIZE &size;
	T &ref;
	public:
	EvaluableExpressionArray(STR str, T &ref, SIZE &size):size(size),ref(ref) {
		variableName=str;
	}
	//TODO: allow accepting sixe (num parameter) as a pointer to empty-argument list, so expression like EvaluableArrayExpression("MOTORS", vectorOfMotors, vectorOfMotors.size) is acceptable
	operator std::string() {
		stringstream ss;
		ss<<variableName;
		for(int i=0; i<size; i++) ss<<" "<<ref[i];
		return ss.str();
	}
};

#include <vector>

template <typename STR, typename T>
void ev(STR str, T (&ref)) {
	cout<<string(EvaluableExpression<STR, T>(str, ref))<<endl;
	//cout<<str<<endl;
}
template <typename STR, typename T, typename SIZE>
void ev(STR str, T (&ref), SIZE &num) {
	cout<<string(EvaluableExpressionArray<STR, T, SIZE>(str, ref, num))<<endl;
	//cout<<str<<endl;
}
template <typename STR, typename T, typename SIZE>
void ev(STR str, T *(ref), const SIZE &num) {
//	cout<<EvaluableExpressionArray<STR, T, SIZE>(str, ref, num)<<endl;
	cout<<str<<endl;
}

//void evarray(char str[]) {
	//cout<<EvaluableExpressionArray<char[], uint16_t, int>(str, ref, num)<<endl;
//}


#include "../def.h"
int main() {
	long s=Timer::getMicros();
	std::vector<int> a;a.size();
	//setup();
	//for(int i=0; i<10000000; ++i) printf("");
//	cout<<"ELO "<<  (Timer::getMicros()-s);
	//cout<<
	int motor[4];
	vector<int> motorVec(4);
	int si=4;
	ev("motors", motorVec, si);
	ev("motors", motor, si);
	ev("NUMBER_MOTORS",  si);
	return 0;
}
