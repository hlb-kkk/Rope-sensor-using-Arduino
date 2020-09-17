# Rope-sensor-using-Arduino
Using Arduino to get the Rope Sensor‘s data 


#Essential Information about the Rope Sensor

Brand: MILONT
Parameters: 
   Type: MPS-S
   Working Voltage: 5V
   Range: 0~2000mm
   Pulse Frequency: 2500/R
   Resolution: 0.064mm/P
   
 This type of rope sensor have to work under 5V, one pulse corresponding to 0.064mm. It means, the distance 
 corresponding to one circle is about 2500*0.064=160mm.
   
 And here using <three phase output> rope sensor. A,B,Z. Phase A and Phase B have 90 degree phase difference 
 which can help us to distinguish the clockwise and counterclockwise rotation. 
 If digitalRead PinA is LOW and the digitalRead PinB is HIGH, it means conterclockwise. 
 If digitalRead PinA is LOW and the digitalRead PinB is LOW, it means clockwise. 
 Also this can be used to divided into quadruple frequency.
 And the Phase Z is used to count the number of turns.
  
  
 The distance can be measured by corresponding the number of turns and of the pulse. 
 Using two interrupt to reset the pulse number and to count the time. Function "millis()" is used to be the timekeeper. 
 The details of this function can be seen in the follow link https://www.arduino.cc/reference/en/language/functions/time/millis/
 The maximun time can be recorded is about 50 days. 
 
 
 Here we use board Arduino Uno to get the data. The code is shown in the <ropesensor.ino>.
 If there are some problems, please contact me!
 
 
