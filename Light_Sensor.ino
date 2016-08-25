int sensorValue, 
    calibration,
    quickCalibration,
    triggerPoint,
    setButtonState = 0,
    smartButtonState = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
 sensorValue = analogRead(A0); // ADC value from LDR
 calibration = analogRead(A1); // ADC value from potentiometer
 setButtonState = digitalRead(7);
 smartButtonState = digitalRead(4);


 if (setButtonState == HIGH) {
     triggerPoint = calibration; // Manual calibration
 }

 if (smartButtonState == HIGH) {
     triggerPoint = sensorValue+25; // Smart calibration
 }
 
 if (sensorValue < triggerPoint){
     digitalWrite(8, HIGH); // Output to relay
  } else {
     digitalWrite(8, LOW); // Output to relay
  }
  
 Serial.println(sensorValue);
 Serial.println(calibration);
 delay(5); 
}
