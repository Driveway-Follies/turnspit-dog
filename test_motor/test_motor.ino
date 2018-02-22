//motor A connected between A01 and A02
//motor B connected between B01 and B02

int STBY = 10; //standby

//Motor B
int PWMB = 3; //Speed control
int BIN1 = 7; //Direction
int BIN2 = 8; //Direction

int analogPin = 3; 
float val = 0;
float adj_val = 0;

void setup(){
  //Serial.begin(9600);              //  setup serial
  
  pinMode(STBY, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop(){
  val = analogRead(analogPin);     // read the input pin
  adj_val = (val/885)*255;
  //Serial.println(adj_val);
  int result = adj_val;
  move(1, result, 0); //motor 1, full speed, left
  //move(2, 255, 1); //motor 2, full speed, left
  
  //delay(1000); //go for 1 second
  //stop(); //stop
  //delay(250); //hold for 250ms until move again
  
  //move(1, 128, 0); //motor 1, half speed, right
  //move(2, 128, 0); //motor 2, half speed, right
  
  //delay(1000);
  //stop();
  //delay(250);
}

void move(int motor, int speed, int direction){
  //Move specific motor at speed and direction
  //motor: 0 for B 1 for A
  //speed: 0 is off, and 255 is full speed
  //direction: 0 clockwise, 1 counter-clockwise
  
  digitalWrite(STBY, HIGH); //disable standby
  
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;
  
  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  digitalWrite(BIN1, inPin1);
  digitalWrite(BIN2, inPin2);
  analogWrite(PWMB, speed);
}

/*void stop(){
  //enable standby
  digitalWrite(STBY, LOW);
}*/
