    #include <Stepper.h>
     
    // change this to the number of steps on your motor
    #define STEPS 48
     
    // create an instance of the stepper class, specifying
    // the number of steps of the motor and the pins it's
    // attached to
    Stepper stepper(STEPS, 4, 5, 6, 7);
    int analogPin = 3;
    float val = 0;
    float adj_val = 0;
     
     
    void setup()
    {
      Serial.begin(9600);
      Serial.println("Stepper test!");
      // set the speed of the motor to 30 RPMs
      stepper.setSpeed(60);
    }
     
    void loop()
    {
      //Serial.println("Forward");
      //stepper.step(STEPS);
      //Serial.println("Backward");
      val = analogRead(analogPin);
      adj_val = (val/885)*255;
      int result = adj_val;
      Serial.println(result);
      stepper.setSpeed(result);
      stepper.step(-STEPS);
    }
