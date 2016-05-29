#include <LiquidCrystal.h>
#include <DHT.h>


int SENSOR = 2;

int VO = 3;
int RS = 4;
int E = 5;
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;

int temp;
int humedad;

DHT dht (SENSOR, DHT11);
LiquidCrystal lcd (RS, E, D4, D5 ,D6, D7);

void setup(){
  dht.begin();
  
  lcd.begin(16, 2); 
  analogWrite(VO, 50); //contraste
}

void loop(){
    humedad = dht.readHumidity();
    temp = dht.readTemperature();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperatura: ");
    lcd.print(temp);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humedad: ");
    lcd.print(humedad);
    lcd.print("%");

    delay(15000);
}









