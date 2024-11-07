#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);
  
  int ledverde=13;
  int ledamarelo=12;
  int ledvermelho=9; 
  
void setup(){
  lcd.init();
  pinMode (ledverde, OUTPUT);
  pinMode (ledamarelo, OUTPUT);
  pinMode (ledvermelho, OUTPUT);

}
void loop()
{
  int ValorPot=analogRead (A0);

  digitalWrite (ledverde, LOW);
  digitalWrite (ledamarelo, LOW);
  digitalWrite (ledvermelho, LOW);
  
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Potencia: " + String (ValorPot));
  lcd.setCursor(0,1);

  if (ValorPot > 0 && ValorPot <= 333) {
    lcd.print("LED Verde.......");
    digitalWrite (ledverde, HIGH);
    }
    
  if (ValorPot > 334 && ValorPot <= 777) {
    lcd.print("LED Amarelo......");
    digitalWrite (ledamarelo, HIGH);
    }

  if (ValorPot > 778 && ValorPot <= 1024) {
    lcd.print("LED Vermelho.....");
    digitalWrite (ledvermelho, HIGH);
    }
    delay(500);
}
