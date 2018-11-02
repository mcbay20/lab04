#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"


int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1)
    {    
    wiringPiSetup () ;
     pinMode (2, OUTPUT) ;
 
     digitalWrite (2, HIGH); delay (250) ;  /* flash Red light*/ 
     digitalWrite (2, LOW); delay (250) ;  /* flash Red light*/ 
      printf("ONE \n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "Status: Alarm TRIGGERED", "7:05:57pm Saturday, September 29, 2018", "Backyard");          
    }
    printf("Waiting for event\n");
    while(digitalRead(0) == 0)
    {
     wiringPiSetup () ;
     pinMode (1, OUTPUT) ;
 
     digitalWrite (1, HIGH); delay (250) ;  /* flash green light*/ 
     digitalWrite (1, LOW); delay (250) ;  /* flash green light*/ 
     printf("ZERO \n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "Status: OK", " 6:05:57pm Saturday, September 29, 2018", "Backyard");      
    }
    printf("Alarm\n");
  }
  /*NOTREACHED*/
  return 0 ;
}
