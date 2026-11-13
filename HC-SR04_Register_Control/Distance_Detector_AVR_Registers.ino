
long duree;
float distance;

 
long mesurerDistance() {

  // TRIG = PD6 
  PORTD &= ~(1 << PD6);
  delayMicroseconds(2);

  PORTD |= (1 << PD6);
  delayMicroseconds(10);

  PORTD &= ~(1 << PD6);

  //  ECHO = HIGH
  unsigned long debutAttente = micros();

  while (!(PIND & (1 << PD7))) {
    if (micros() - debutAttente > 30000)
      return 0;
  }

 
  unsigned long debutEcho = micros();

  while (PIND & (1 << PD7)) {
    if (micros() - debutEcho > 30000)
      return 0;
  }

  return micros() - debutEcho;
}

void setup() {

  
  DDRD |= 0b01111100;

  // PD7 = INPUT
  DDRD &= ~(1 << PD7);

 
  PORTD &= ~(0b01111100);

  Serial.begin(9600);
}

void loop() {


  duree = mesurerDistance();


  if (duree == 0) {

    
    PORTD |= (1 << PD4);

   
    PORTD &= ~(1 << PD2);
    PORTD &= ~(1 << PD3);

   
    tone(5, 1000);

    Serial.println("ALERTE : aucun echo !");
  }

  else {

    
    distance = duree * 0.0343 / 2;

    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 30) {

    
      PORTD |= (1 << PD2);

      
      PORTD &= ~(1 << PD3);
      PORTD &= ~(1 << PD4);

      noTone(5);
    }

    else if (distance > 15) {

     
      PORTD |= (1 << PD3);

      PORTD &= ~(1 << PD2);
      PORTD &= ~(1 << PD4);

      noTone(5);
    }

    else {

     
      PORTD |= (1 << PD4);

      PORTD &= ~(1 << PD2);
      PORTD &= ~(1 << PD3);

      // Buzzer ON
      tone(5, 1000);
    }
  }

  delay(100);
}
