
/*
hsj
20200917
ropesensor device test 
*/

#include <Wire.h>


//define the pin
#define PinA 2
#define PinZ 3
#define PinB 8

//define the varible
double distance;//the real distance of the ropesensor
double num = 0; // to count the num of circle
long count = 0; //define the paluse, the range is [-2500,2500], one paluse implies 0.064mm
float time_cw;
float time_ccw;
double t; //the past time
const float d = 160; // one circle is 160mm

double distance1;

unsigned long time1 = 0;
double time3;

void setup() {
  
  //每一个都是上拉
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);
  pinMode(PinZ, INPUT_PULLUP);
  
  attachInterrupt(0, Encode, FALLING);
  attachInterrupt(1, Set_state, FALLING);
  
  Serial.begin(9600);
  
  
    
}

void loop() {



  if (count == 2500)
  {
    
    time_cw = millis();

    
  }
  
  if (count == -2500)
  
  {
    //num = num-1;
    time_ccw = millis();
  
  }

  if (num == 0)
  {
    distance1 = count*0.064;
    Serial.println(count);
    Serial.print("The distance is:"); Serial.println(distance1);
  }

  else
  {
    distance1 = count*0.064;
    Serial.println(count);
    //Serial.print("distance1 is "); Serial.print(distance1);Serial.println("mm.");
    //Serial.print("the number of circle is: "); Serial.println(num);
    distance = distance1+num*160;
    Serial.print("the real distance is: "); Serial.print(distance); Serial.println("mm.");
    
  }
}


void Encode()
{
  if (millis()-time1>5)
  {
    if((digitalRead(PinA) == LOW) && (digitalRead(PinB) == HIGH))
    {
      count--;
      if(count == -2500)
      {
        num = num-1;
      }
    }
    else
    {
       count++;
       if (count == 2500)
       {
        num = num+1;
       }
    }
  }
  
  time1 == millis();
}

void Set_state(){
  
  count = 0;
  time3 = millis();
}
