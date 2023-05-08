#define Push_button 12
#define LedPin 9
void setup() {
  Serial.begin(9600);
  pinMode(Push_button,INPUT);
  pinMode(LedPin,OUTPUT);
  digitalWrite(LedPin,LOW);
}

void loop() {
int button_data=digitalRead(Push_button);
Serial.print(button_data);
  if(button_data==0){
    digitalWrite(LedPin,LOW);}
   else{
    digitalWrite(LedPin,HIGH);
    }
  
}
