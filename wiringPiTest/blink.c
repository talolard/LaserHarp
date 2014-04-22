#include <wiringPi.h>
#include <stdio.h>
int main (void)
{
   int Pin;
    int Count=0;Count =  wiringPiSetup ();
 if (Count ==-1) return 0; ;
 printf ("\n%i",Count);
 for (Pin=0;Pin<21; Pin++){
     pinMode (1, OUTPUT) ;
    }
  for (;;)
  {
    Pin=1;
    for (Pin=0; Pin<21; Pin++){
        if (Count%2){
            digitalWrite (Pin, HIGH) ;
        }else{
           digitalWrite (Pin,  LOW) ;
        }
Count++;
delay (5);
    }
  }
  return 0 ;
}
