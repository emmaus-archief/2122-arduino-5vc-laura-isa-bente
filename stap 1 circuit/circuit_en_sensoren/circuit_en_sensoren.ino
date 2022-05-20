const int PWMA = 6;           //Left Motor Speed pin (ENA)
const int AIN2 = A0;          //Motor-L forward (IN2).
const int AIN1 = A1;          //Motor-L backward (IN1)
const int PWMB = 5;           //Right Motor Speed pin (ENB)
const int BIN1 = A2;          //Motor-R forward (IN3)
const int BIN2 = A3;          //Motor-R backward (IN4)
int TOESTAND = 1;
const int LIJN_VOLGEN = 1; // toestand is lijn volgen
const int REMMEN = 2; // toestand is remmen
const int DRAAIEN_ZOEKEN = 3; // toestand is draaien of zoeken
int remtijd = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);  
  analogWrite(PWMA,25);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMB,25);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
}
