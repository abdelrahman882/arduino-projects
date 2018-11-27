
float led=13,buzzer=12,threshold =3.0;
float stoppingVal =2.5;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
   digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
}
void loop() {
  int val = analogRead(A0);
  float realVal = val * 5.0/1024.0;
  if(realVal<stoppingVal){
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
  }if(realVal>=threshold){
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
  }
  Serial.println(realVal);
  delay(2);
}
