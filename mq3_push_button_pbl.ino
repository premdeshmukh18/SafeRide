
int sensorval;
int data_button;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorval = digitalRead(13);
  data_button=digitalRead(12);
  Serial.println(sensorval);
  Serial.println(data_button);
  delay(1000);
  if(sensorval==1 && data_button==1){
    Serial.println("SAFE TO RIDE");}
  else{
    if (sensorval==0 and data_button==1){
      Serial.println("ALCOHOL DETECTED");}
     else{
      Serial.println("WEAR HELMET");}
    Serial.println("NOT SAFE TO RIDE");
    }  
}
//alcohol not present : 1
//alcohol present : 0
