const int ACPin = A2;    
#define ACTectionRange 20;    
#define VREF 5.0
float readACCurrentValue()
{
  float ACCurrtntValue = 0;
  float peakVoltage = 0;
  float voltageVirtualValue = 0;   
  for (int i = 0; i < 5; i++)
  {
    peakVoltage += analogRead(ACPin);   
    delay(1);
  }
  peakVoltage = peakVoltage / 5;
  voltageVirtualValue = peakVoltage * 0.707;   
  voltageVirtualValue = (voltageVirtualValue / 1024 * VREF ) / 2;
  ACCurrtntValue = voltageVirtualValue * ACTectionRange;
  return ACCurrtntValue;
}
void setup() 
{
  Serial.begin(115200);
  pinMode(13, OUTPUT);

}
void loop() 
{
  float ACCurrentValue = readACCurrentValue();  
  Serial.print(ACCurrentValue);
  Serial.println(" A");
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}