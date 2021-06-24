 /*
  Board : MKR WIFI 1010 Board
  App.  : DFR Touch sensor testing
 */
 int ledPin = 13;                // Connect LED on pin 13, or use the onboard one
 int KEY = 2;                 // Connect Touch sensor on Digital Pin 2

 void setup()
 {
   pinMode(ledPin, OUTPUT);      // Set ledPin to output mode
   pinMode(KEY, INPUT);       //Set touch sensor pin to input mode

   Serial.begin(9600);
   
 }
 void loop()
 {
    if(digitalRead(KEY)==HIGH)       //Read Touch sensor signal
        {
          digitalWrite(ledPin, HIGH);   // if Touch sensor is HIGH, then turn on
          //Serial.write("Touch On"); //send the string "Touch On" and return the length of the string.
          Serial.println("Touch On"); //send the string "Touch On" and return the length of the string.
      }
    else
     {
         digitalWrite(ledPin, LOW);    // if Touch sensor is LOW, then turn off the led
         //Serial.write("Touch Off"); //send the string "Touch Off" and return the length of the string.
         Serial.println("Touch Off"); //send the string "Touch Off" and return the length of the string.
      }
 }
