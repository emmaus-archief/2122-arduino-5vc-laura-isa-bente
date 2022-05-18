/*
Stoplicht Startcode
   met toestansdiagrammen
   Emmauscollege
   v20201114GEE
*/

#define PWMA   6           //Left Motor Speed pin (ENA)
#define AIN2   A0          //Motor-L forward (IN2).
#define AIN1   A1          //Motor-L backward (IN1)
#define PWMB   5           //Right Motor Speed pin (ENB)
#define BIN1   A2          //Motor-R forward (IN3)
#define BIN2   A3          //Motor-R backward (IN4)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("TRSensor example!!");
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);  
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);  

const int LIJN_VOLGEN = 1; // toestand is lijn volgen
const int REMMEN = 2; // toestand is remmen
const int DRAAIEN/ZOEKEN = 3; // toestand is draaien of zoeken
int toestand = DRAAIEN_ZOEKEN;
int remtijd = 1000;

void loop() {
  // lees sensorwaarden
  /*knop7 = digitalRead(pin7Knop);
  knop8 = digitalRead(pin8Knop);*/

  // bepaal toestand
  bool geenLijnGedetecteerd = false;
  if (toestand == LIJN_VOLGEN) {
    if (geenLijnGedetecteerd == true) {
      toestand = REMMEN;
   
      Serial.println("Nieuwe toestand: REMMEN");
    }
    
    if (toestand == REMMEN) {
      ;
      Serial.println("Nieuwe toestand: DRAAIEN_ZOEKEN");
    }
  }

  bool remtijdVoorbij = true;
  if (toestand == REMMEN) {
    if (remtijd > 1000) {
      toestand = DRAAIEN_ZOEKEN;
     
      Serial.println("Nieuwe toestand: DRAAIEN_ZOEKEN");
    }
  /*  if (knop7 == HIGH || knop8 == HIGH) {
      toestand = DRAAIEN_ZOEKEN;
      Serial.println("Nieuwe toestand:DRAAIEN_ZOEKEN");
    }
    */ 
  }

  bool lijnGedetecteerd = true;
  if (toestand == LIJN_VOLGEN) {
    if (lijnGedetecteerd == false) { 
      toestand == DRAAIEN_ZOEKEN;
    if (lijnGedetecteerd == true)
      toestand == LIJN_VOLGEN;
      
      Serial.println("Nieuwe toestand: LIJN_VOLGEN");
    }
  }

  // zet stoplichten conform toestand
  if (toestand == LIJN_VOLGEN) {
    for (int i = 1; i <= 8; i = i + 1) {
      stoplicht(i, ROOD);
    }
  }
  if (toestand == REMMEN) {
    for (int i = 1; i <= 8; i = i + 1) {
      stoplicht(i, GROEN);
    }
  }
  if (toestand == DRAAIEN_ZOEKEN) {
    for (int i = 1; i <= 6; i = i + 1) {
      stoplicht(i, ORANJE);
    }
  }

  // vertraging om te zorgen dat berichten op de seriele monitor leesbaar blijven
  delay(100);
}
