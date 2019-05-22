#include <HX711.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 


const int DOUT = 13;  // Arduino pin 6 connect to HX711 DOUT
const int CLK = 12;  //  Arduino pin 5 connect to HX711 CLK
const int led = 5;

float sure,mesafe,deger;
int hareket;
int i;


//SoftwareSerial BTserial(10, 11);        //RX   TX
LiquidCrystal_I2C lcd(0x27, 16, 2);

//-------------------------------------------------------------
HX711 scale;
float birim;
float parca;
char mesaj;
//-------------------------------------------------------------
void setup() {
  
Serial.begin(9600);
lcd.begin();
scale.begin(DOUT, CLK);
scale.set_scale(2235);  // Start scale
scale.tare();       // Reset scale to zero


pinMode(4,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9, INPUT);
pinMode(led, OUTPUT);

}

void loop() {

digitalWrite(8, HIGH);
delay(10);
digitalWrite(8, LOW);
deger=10.0;
sure= pulseIn(9, HIGH);
mesafe = (sure/2) / 28.5;


//---------------------------------------------------------
  birim = scale.get_units(), 10;
  if (birim < 0)
  {
    birim = 0.00;
    Serial.println("Markete gitmelisin            :-)");
    Serial.print("Gram:");
    
  }
  else
  Serial.print("Gram: "); 
  Serial.print(birim);
  


 
  delay(10);
  
  

//---------------------------------------------------------


hareket = digitalRead(7);
if(hareket == HIGH)
{
  if (mesafe > deger)
{
digitalWrite(led,HIGH);
digitalWrite(4, HIGH);
delay(1000); 
digitalWrite(4, LOW);
digitalWrite(led,LOW);

}
else
{
  digitalWrite(4, LOW);
  }
  
}
if(hareket == LOW)
{
digitalWrite(4, LOW);
}
delay(1000);
   lcd.setCursor(i,0);
   
   if(mesafe > deger)
   {
    lcd.print("tabak az:");
    }
    else
    {
   lcd.print("tabak dolu:");
    }
   lcd.print(mesafe);
   delay(1000);
   lcd.print(" ");
   lcd.clear();
  }
