#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2
 
#define I1 8   // Control pin 1 for motor 1
#define I2 9   // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

#define L1 A0  //LDR pin 1 for input
#define L2 A1  //LDR pin 2 for input
#define L3 A2  //LDR Pin 3 for input

#define white 0 //LDR threshold value for white
#define black 100 //LDR threshold value for black

void setup() {
    Serial.begin(9600);
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    
    pinMode(L1, INPUT);
    pinMode(L2, INPUT);
    pinMode(L3, INPUT);
}
int getLDR(int LDR) {
    return analogRead(LDR);
}
void dWrite (int dir[4], int speed1, int speed2){
  analogWrite(E1, speed1); // Run in full speed
  analogWrite(E2, speed1);
  digitalWrite(I1, dir[0]);
  digitalWrite(I2, dir[1]);
  digitalWrite(I3, dir[2]);
  digitalWrite(I4, dir[3]);
}
void turnRightSharp(int speed1){
    int dir [4] = {1,0,0,1};
    dWrite (dir, speed1, speed1);
}
void turnLeftSharp(int speed1){
    int dir [4] = {0,1,1,0};
    dWrite (dir, speed1, speed1);
}
void backwards(int speed1){
    int dir [4] = {1,0,1,0};
    dWrite (dir, speed1, speed1);
}
void forwards(int speed1){
    int dir [4] = {0,1,0,1};
    dWrite (dir, speed1, speed1);
}
void turn(int speed1, int speed2){
    int dir [4] = {1,0,0,1};
    dWrite (dir, speed1, speed2);

}
   
void loop() {
    int LDR1 = getLDR(L1);
    int LDR2 = getLDR(L2);
    int LDR3 = getLDR(L3);
    //Serial.println(LDR1);
    Serial.println(LDR2);
    if (LDR2 > (LDR1 + 5) && LDR2 > (LDR3 + 5)){
      forwards(70);
    }
    //General
    if (abs(LDR1 - LDR2) <= 10 &&  abs(LDR1 - LDR3) <= 10 && abs(LDR2 - LDR3) <= 10){
      turnRightShapr(70);
    }
    // Forwards adjustments
    //Right
    else if (LDR3 < 20 && LDR1 > 20 && LDR3 > 20){
      turn(30,50);
    }
    //Left
    else if (LDR3 < 20 && LDR1 > 20 && LDR3 > 20){
      turn(50,30);
    }  
    // 90 Degree turns, might work for 45.
    //Right
    else if (LDR2 <= (LDR1 - 15) && 15 < abs(LDR3 - LDR2)){
      turn(70,50);
    }
    //Left
    else if (LDR2 <= (LDR3 - 15) && 15 < abs(LDR1 - LDR2)){
      turn(50,70);
    }
    
    //Test directions
    //turn (left, right);
    //turn (100, 0);
    
    //Sample Test 1 code.
    /*forwards(70);
    delay(4000);
    turnRight(70,50);
    delay(3000);
    backwards(70);
    delay(4000);
    turnLeft(50,70);
    delay(3000);*/
}
