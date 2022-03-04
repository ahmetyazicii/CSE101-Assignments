
void setup() {

  Serial.begin(9600);
  pinMode(8, OUTPUT); 

}

void loop() {
  
  int gg = 0,sum=0;
  
  
  if (Serial.available() > 0) {

    gg = Serial.read(); /* to read data which sent from c program */

    switch (gg) {
      
      case 'x': /* to turn on led */
       
        digitalWrite(8, HIGH);
        break;
      
      case 'y': /* to turn off led */
        
        digitalWrite(8, LOW); 
        break;
      
      case 'z': /* to flash led 3 times */
        
        digitalWrite(8,HIGH);
        delay(400);
        digitalWrite(8,LOW);
        delay(400);
        digitalWrite(8,HIGH);
        delay(400);    
        digitalWrite(8,LOW);
        delay(400);
        digitalWrite(8,HIGH);
        delay(400);
        digitalWrite(8,LOW);
        break;
     
      default: /* to calculate square of number */
        gg=gg-100;
        sum=gg*gg;
        
        Serial.print(sum); /* to send data to c program */
        break;
        
    }  
  }
}
