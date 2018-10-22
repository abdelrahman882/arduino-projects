
void setup() {
  Serial.begin(9600);
}
int getNum(){
  int sign = 1;
  int res=0;
  int count=0;
  char c=' ';
  do{
    while(!Serial.available());
     c  =Serial.read();
     if(c=='\n'&&count>0){
      break;
     }else if(c=='-'&&count==0){
      sign=-1;
      continue;
    }else if(c<='9'&&c>='0'){
    res= (res*10)+(c-'0');
    }else{
      continue;
    }

    count++;
  }while(count<4);
    return res*sign;
  }

void loop() {
  int num1=0,num2=0;
  num1= getNum();
  Serial.print("Num1 : ");
  Serial.println(num1);
  num2= getNum();
  Serial.print("Num2 : ");
  Serial.println(num2);
  Serial.print("Num1 + Num2 : ");
  Serial.println((num1+num2));
}
