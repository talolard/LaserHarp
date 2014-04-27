#include<stdlib.h>
#include<pthread.h>

#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
typedef int TimeType;
void Proc(int Pin);
volatile int Flag[3] = {0,0,0};

TimeType   Count[3] ={1,1};
void ResetPin(int Pin);
void Trig1 ()
{ 
piLock(0);// Make sure other thread isnt working
    int  Val = Flag[0];
piUnlock(0);
   if(Val!=1){  // If we have finished prodessing previsous trigerrs/ 
    Proc(4);
    }// Otherwise we need to reset the pin
    else{
    }
}
void Trig2 (){
piLock(1);// Make sure other thread isnt working
        int  Val = Flag[1];
piUnlock(1);
   if(Val!=1){  // If we have finished prodessing previsous trigerrs/ 
      Proc(5);
    }else{
    }
}
void Trig3 (){
piLock(2);// Make sure other thread isnt working
        int  Val = Flag[2];
piUnlock(2);
   if(Val!=1){  // If we have finished prodessing previsous trigerrs/ 
      Proc(6);
    }else{
    }
}
void Proc(int Pin)
{
    int  Place=Pin-4;
    TimeType Dif = Count[Place];
//    if (Flag[Place] ==0 && Dif!=0){
    {
        switch (Place){
            case (0):break;
            case (1):printf("\t");break;
            case (2):printf("\t\t\t");break;
            default:break;
        }
        if (Place) printf("\t\t");
        if (Place%3) if (Place) printf("\t\t");
        printf ("\x1b[3%im %i triggered %i\n",Pin,Pin,Dif);
    }
    delay(0.1);
    piLock(Place);

		Flag[Place]=1;
    piUnlock(Place);

}
void ResetPin(int Pin)
{
    int Place = Pin-4;
    pinMode(Pin,OUTPUT);
    digitalWrite(Pin,LOW);
    pinMode(Pin,INPUT);

}
void* Check (void* P)
{
	int Pin = *((int *) P);
	int Place = Pin-4;
	ResetPin(Pin);
	while (1){
		delay(0.51);
		if (Flag[Place] ==1){
			piLock(Place);{
				Count[Place]=0;
				pinMode(Pin,OUTPUT);
				digitalWrite(Pin,LOW);
				pinMode(Pin,INPUT);
				Flag[Place]=0;

			}
			piUnlock(Place);
		}

	}
}
int main (void)
{
    wiringPiSetup () ;

    wiringPiISR(4,INT_EDGE_RISING,Trig1);
    wiringPiISR(5,INT_EDGE_RISING,Trig2);
    wiringPiISR(6,INT_EDGE_RISING,Trig3);
    delay(10);
   /* ResetPin(4);
    ResetPin(5);
    ResetPin(6);
  printf ("Done waiting \n" );
    int Pin =0;
    while (Pin<100000000){
        int Place;
        for (Pin=6; Pin>=4; Pin--){
            Place = Pin-4;
            if (Flag[Place] ==1){
            piLock(Place);
            	pinMode(Pin,INPUT);
                    Flag[Place]=0;
                    Count[Place]=0;
            piUnlock(Place);
            }

            { // No else so that it clease even if flag is off
               Count[Place]++;
            }
       }
    }*/
int Pin;
    for (Pin=6; Pin>=4; Pin--){
    	pthread_t thread;
    	int* arg =malloc(sizeof(*arg));
    	*arg=Pin;
    	pthread_create(&thread, 0, Check, arg);
    }
    int i;
    while(1){
    	for( i=0; i<3; i++){
    		Count[i]++;
    	}
    }

    return 0;
 }
