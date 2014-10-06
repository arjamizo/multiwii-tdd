#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef int16_t T;

template<class R, class S>
const T& constrain(const T& x, const R& a, const S& b)
#ifndef _CONSTRAIN
#define _CONSTRAIN
{
    if(x < a) {
        return a;
    }
    else if(b < x) {
        return b;
    }
    else
        return x;
}
#else
;
#endif

#define PROGMEM
extern int _led;
#define LEDPIN_TOGGLE {_led=!_led;}
#define LEDPIN_OFF {_led=0;}
#define LEDPIN_ON {_led=1;}

#define LEDPIN_PINMODE
#define POWERPIN_PINMODE
#define BUZZERPIN_PINMODE
#define STABLEPIN_PINMODE
#define POWERPIN_OFF

#define OUTPUT 0

#define pinMode(a,b) //this is just a fake def  so there are no errors

void delay(int ms);

//progmem mock implementation

//http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&t=38003
#include <cstring>
#define PGM_P const char *
#define strlen_P(ptr) (strlen((char*)ptr))
#define pgm_read_byte(p) (*((char*)p))

#define ROLLPIN 0
#define PITCHPIN 1
#define YAWPIN 2
#define THROTTLEPIN 3
#define AUX1PIN 4
#define AUX2PIN 5
#define AUX3PIN 6
#define AUX4PIN 7
#define PCINT_PIN_COUNT 8
#define PCINT_RX_BITS 8
extern long _rxport;
extern long _rxmask;
extern int _icr;
extern int pin_buzzpin;

#define BUZZERPIN_TOGGLE {pin_buzzpin=!pin_buzzpin;}
#define BUZZERPIN_OFF {pin_buzzpin=0;}
#define BUZZERPIN_ON {pin_buzzpin=1;}

#define PCINT_RX_PORT _rxport
#define PCINT_RX_MASK _rxmask
#define PCICR _icr
#define PCIR_PORT_BIT 1

#define MAKE_FN_NAME(x) void  ISR_ ## x (void)
#define ISR(signal) MAKE_FN_NAME(signal)
#define RX_PCINT_PIN_PORT 0
void sei();
void cli();
extern int SREG;
extern int TWSR,TWBR,TWCR,TWEN,TWINT,TWSTA,TWDR,TWSTO,TWEA;
#define I2C_PULLUPS_DISABLE
#define F_CPU 160000
#define POWERPIN_ON
//#define
#include <cmath> //for fabs
int min(int a, int b);
int max(int a, int b);

#define RC_CHANS 8

long millis();

long micros();

void *printEach5Seconds(void *cout_ptr);
