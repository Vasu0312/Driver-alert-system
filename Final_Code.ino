const int sensor = 7;
int buzz=8;
int count = 0;
int state = LOW;
int laststate= LOW;
float ton_1;
float toff_1;
float ton_2;
float toff_2;
float T1;
float T2;
float N1;
float N2;
int N;
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(8,OUTPUT);
  //state = digitalRead(sensor);
 }

void loop() {
  ton_1=millis();
  while (count<5){
    
  if (state == HIGH && laststate == LOW){
    count++;
   }
  laststate=state;
  state=digitalRead(7);
  }
  toff_1=millis();
  
  count = 0;
  
  ton_2=millis();
  while (count<5){
    
  if (state == HIGH && laststate == LOW){
    count++;
  }
  laststate=state;
  state=digitalRead(7);
  }
  toff_2 = millis();

  count = 0;

  T1=(toff_1-ton_1)/1000;
  N1 = (5*60)/(T1);
  
  T2=(toff_2-ton_2)/1000;
  N2 = (5*60)/T2;
  
  N=N1-N2;
  Serial.println((N1));
  Serial.println((N2));
  Serial.println(abs(N));
 
  }
}

