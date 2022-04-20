
   Stoplicht Startcode
   met toestansdiagrammen
   Emmauscollege
   v20201114GEE

const int LIJN VOLGEN = 1; // toestand is lijn volgen
const int REMMEN = 2; // toestand is remmen
const int DRAAIEN/ZOEKEN = 3; // toestand is draaien of zoeken
int toestand = DRAAIEN/ZOEKEN;

void loop() {
  // lees sensorwaarden
  /*knop7 = digitalRead(pin7Knop);
  knop8 = digitalRead(pin8Knop);*/

  // bepaal toestand
  if (toestand == LIJN VOLGEN) {
    if (lijn is gedetecteerd {
      blijven rijden;
   
      Serial.println("Nieuwe toestand: REMMEN");
    }
    if (toestand == REMMEN) {
      ;
      Serial.println("Nieuwe toestand: DRAAIEN/ZOEKEN");
    }
  }
  if (toestand == REMMEN) {
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = LIJN VOLGEN;
      Serial.println("Nieuwe toestand: LIJN VOLGEN");
    }
    if (knop7 == HIGH || knop8 == HIGH) {
      toestand = DRAAIEN/ZOEKEN;
      Serial.println("Nieuwe toestand:DRAAIEN/ZOEKEN");
    }
  }
  if (toestand == DRAAIEN/ZOEKEN) {
    if (knop7 == LOW && knop8 == LOW) { // beide knoppen niet ingedrukt
      toestandStartTijd = millis();
      toestand = LIJN VOLGEN;
      Serial.println("Nieuwe toestand: LIJN VOLGEN");
    }
  }

  // zet stoplichten conform toestand
  if (toestand == LIJN VOLGEN) {
    for (int i = 1; i <= 8; i = i + 1) {
      stoplicht(i, ROOD);
    }
  }
  if (toestand == REMMEN) {
    for (int i = 1; i <= 8; i = i + 1) {
      stoplicht(i, GROEN);
    }
  }
  if (toestand == DRAAIEN/ZOEKEN) {
    for (int i = 1; i <= 6; i = i + 1) {
      stoplicht(i, ORANJE);
    }
  }

  // vertraging om te zorgen dat berichten op de seriele monitor leesbaar blijven
  delay(100);
}
