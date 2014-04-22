#include <wiringPi.h>
#include <stdio.h>
int TimePin(int Pin){
    int reading =0;
    pinMode(Pin,OUTPUT);
    digitalWrite(Pin,LOW);
    delay(10);
    pinMode(Pin,INPUT);
    int value = digitalRead(Pin);
    while (value==LOW ){
        reading++;
        value = digitalRead(Pin);
    }
    return reading;
}
volatile int Flag= 0;
volatile int   Count =0;
void Trig (){
    piLock(0);{
        Flag = 1;

    }piUnlock(0);
}
int main (void)
{
    wiringPiSetup () ;
    wiringPiISR(1,INT_EDGE_RISING,Trig);
    piHiPri(50);
  int Pin =1;
    while (2){
        if (Flag ==1 ){
            piLock(0);{

            printf ("triggered %i %i \n",digitalRead(Pin),Count);
            pinMode(1,OUTPUT);
            digitalWrite(1,LOW);
            delay(100);

            Count=0;
            Flag= 0;
            }piUnlock(0);
            pinMode(Pin,INPUT);

        }
        Count++;
    }
    return 0;
 }

