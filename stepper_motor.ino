
    #include <Stepper.h>
    #include <Servo.h>
     
    // change this to the number of steps on your motor
    #define STEPS 48
     
    // create an instance of the stepper class, specifying
    // the number of steps of the motor and the pins it's
    // attached to
    Stepper stepper(STEPS, 4, 5, 6, 7);
    int analogPin = 3;
    float val = 0;
    float adj_val = 0;

    Servo myservo;  // create servo object to control a servo
    // twelve servo objects can be created on most boards

    int pos = 0;    // variable to store the servo position

    void setup()
    {
      Serial.begin(9600);
      Serial.println("Stepper test!");
      myservo.attach(9);  // attaches the servo on pin 9 to the servo object
      // set the speed of the motor to 30 RPMs
      stepper.setSpeed(60);
    }
     
    void loop()
    {
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      
      }
      val = analogRead(analogPin);
      adj_val = (val/885)*255;
      int result = adj_val;
      Serial.println(result);
      stepper.setSpeed(result);
      stepper.step(STEPS);
    }
