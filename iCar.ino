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
void traverse (int dir[4], int speed1, int speed2){
  analogWrite(E1, speed1); // Run in full speed
  analogWrite(E2, speed2);
  digitalWrite(I1, dir[0]);
  digitalWrite(I2, dir[1]);
  digitalWrite(I3, dir[2]);
  digitalWrite(I4, dir[3]);
}
void turnRightSharp(int speed1){
    int dir[4] = {1,0,0,1};
    traverse (dir, speed1, speed1);
}
void turnLeftSharp(int speed1){
    int dir[4] = {0,1,1,0}; 
    traverse (dir, speed1, speed1);
}
void backwards(int speed1, int speed2){
    int dir[4] = {0,1,0,1};
    traverse (dir, speed1, speed2);
}
void forwards(int speed1, int speed2){
    int dir [4] = {1,0,1,0};
    traverse (dir, speed1, speed2);
}
/*
void turn(int speed1, int speed2){
    int dir [4] = {1,0,1,0};
    traverse (dir, speed1, speed2);
}
*/   
void loop() {
    int LDR1 = getLDR(L1);//16-25
    int LDR2 = getLDR(L2);//0-10
    int LDR3 = getLDR(L3);//30-45
    //Serial.println(LDR1);
    Serial.print(LDR1);
    Serial.print("     ");
    Serial.print(LDR2);
    Serial.print("     ");
    Serial.println(LDR3);
    //Left = white middle = black right = white : Forward
    if (LDR1 > 13 && LDR2 < 20 && LDR3 > 13){
      Serial.println("Forwards");  
      forwards(70,75);
    }
    //Left = white middle = white right = black : Right
    else if ((LDR1 > 13 && LDR2 > 17 && LDR3 < 17) || (LDR1 > 13 && LDR2 < 17 && LDR3 < 17)){
      forwards (50,10);
    } 
    //Left = black middle = white right = white : Left
    else if ((LDR1 < 13 && LDR2 > 17 && LDR3 > 17) || (LDR1 < 13 && LDR2 < 17 && LDR3 > 17)){
      forwards (10,50);
    }
    // || (
    //Left = white middle = white right = white OR Left = black middle = black right = black: Sharp Right
    else if ((LDR1 > 50 && LDR2 > 50 && LDR3 > 6 0) || (LDR1 < 17 && LDR2 < 17 && LDR3 < 20) ){
      turnRightSharp(60);
    }
  
    //General
    //if (abs(LDR1 - LDR2) <= 10 &&  abs(LDR1 - LDR3) <= 10 && abs(LDR2 - LDR3) <= 10){
    //Serial.println("Sharp right"); 
      //turnRightSharp(70);
    //}
   
    /*// Forwards adjustments
    //Right
    else if (LDR3 < 10 && LDR1 > 10 && LDR3 > 10){
     // Serial.println("Gradual right"); 
     forwards(30,50);
    }
    //Left
    else if (LDR3 < 10 && LDR1 > 10 && LDR3 > 10){
//      Serial.println("Gradual left");
      forwards(50,30);
    }  
    // 90 Degree turns, might work for 45.
    //Rightx
    else if (LDR2 <= (LDR1 - 15) && 30 < abs(LDR3 - LDR2)){
  //    Serial.println("Faster right");
      forwards(70,50);
    }
    //Left
    else if (LDR2 <= (LDR3 - 15) && 30 < abs(LDR1 - LDR2)){
    //  Serial.println("Faster left");
      forwads(50,70);
    }*/
    
    //Test directions
    //turn (left, right);
    //forwards(70, 75);
    
    /*//Sample Test 1 code.
    turn(70,75);
    delay(4000);
    turn(70,10);
    delay(3000);
    backwards(70,75);
    delay(4000);
    turn(10,70);
    delay(3000);*/
}
