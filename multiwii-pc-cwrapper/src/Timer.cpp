#include <stdint.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <set>
#include <list>
#include <vector>

#ifndef _TIMER
#define _TIMER
struct Timer {
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
} Timer;
#endif
