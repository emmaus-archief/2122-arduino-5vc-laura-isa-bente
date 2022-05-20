
/*
   Alphabot Startcode line-tracking
   met toestansdiagrammen
   Emmauscollege
   v20201114GEE
*/

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

void loop() {
  // lees sensorwaarden

  // bepaal toestand
  bool geenLijnGedetecteerd = false;
  if (TOESTAND == LIJN_VOLGEN) {
    if (geenLijnGedetecteerd == true) {
      TOESTAND = REMMEN;
   
      Serial.println("Nieuwe toestand: REMMEN");
    }
    
    if (TOESTAND == REMMEN) {
      ;
      Serial.println("Nieuwe toestand: DRAAIEN_ZOEKEN");
    }
  }

  bool remtijdVoorbij = true;
  if (TOESTAND == REMMEN) {
    if (remtijd > 1000) {
      TOESTAND = DRAAIEN_ZOEKEN;
     
      Serial.println("Nieuwe toestand: DRAAIEN_ZOEKEN");
    }
  }

  bool lijnGedetecteerd = true;
  if (TOESTAND == LIJN_VOLGEN) {
    if (lijnGedetecteerd == false) { 
      TOESTAND == DRAAIEN_ZOEKEN;
    if (lijnGedetecteerd == true)
      TOESTAND == LIJN_VOLGEN;
      
      Serial.println("Nieuwe toestand: LIJN_VOLGEN");
    }
  }

  // vertraging om te zorgen dat berichten op de seriele monitor leesbaar blijven
  delay(100);
}
