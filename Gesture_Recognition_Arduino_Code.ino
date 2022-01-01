
/* Author: Alia Azadi

   Code for Summer 2021 Internship at San Francisco State University at ICE Lab http://www.sfsu-icelab.org/
   Reads electromyography signals on forarms and preforms gesture recognition
   Prints senor and voltage values on Serial Plotter
   
   Hardware: Sparkfun Myoware Muscle Sensor Kit https://www.sparkfun.com/products/14409, Arduino Uno
   
  */
  
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  cli();
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  TIMSK1 |= (1 << OCIE1A);

  sei();
}

ISR(TIMER1_COMPA_vect){
}
void loop(){
 float sensorValue = analogRead(A0);
 float millivolt = (sensorValue/1023)*5;
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  Serial.print("Voltage: ");
  Serial.print(millivolt*1000);
  Serial.println(" mV");
  Serial.println("");


if (sensorValue <= 400) {
  digitalWrite(LED_BUILTIN, LOW);   
}
if (sensorValue > 400) {
  digitalWrite(LED_BUILTIN, HIGH);   
}
}
