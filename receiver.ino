// include libraries
#include <RH_ASK.h>
#include <LiquidCrystal.h>

// initialise variables
LiquidCrystal lcd(12,11,10,9,8,7);
int value1;
int value2;
int value3;
int value4;
int timesTosend=1;
int count;
RH_ASK driver;
char* values;

void setup()
{
    // put your setup code here, to run once:
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Welcome");
    Serial.println("AT+CMGF=1");  //set GSM to text mode
    pinMode(6, OUTPUT);
    digitalWrite(6, LOW); // buzzer
}


void loop()
{
  
  count = 0;
  //to receive:
  uint8_t buf[32];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
    int value1;
int value2;
int value3;
int value4;
char* values[4];
    // Message with a good checksum received, dump it.  
    value1 = int(values[0]);
    value2 = int(values[1]);
    value3 = int(values[2]);
    value4 = int(values[3]);
  }
  
  if(value1 >80 && value1<180 && value2>80 && value2<180 && value3>80 && value3< 180 && value4>80 && value4<180)
  {
    Serial.print("Food");
    lcd.clear();
    lcd.print("Food");
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    while(count<timesTosend)
    {
          delay(1500);
          Serial.print("AT+CMGS=\"");
          Serial.print("90690461xx");
          Serial.println("\"");
          while (Serial.read()!='>');
          {
            Serial.print("Food Requirement by patient");  //SMS body
            delay(500);
            Serial.write(0x1A);  // sends ctrl+z end of message
            Serial.write(0x0D);  // Carriage Return in Hex
            Serial.write(0x0A);  // Line feed in Hex
            //The 0D0A pair of characters is the signal for the end of a line and beginning of another.
            delay(5000);
          }
          count++;
    }
  }
    else if(value1 >80 && value1<180 && value2<30 && value3<30 && value4<30)
    {
        lcd.clear();
        lcd.print("Medicine");
        Serial.print("Medicine");
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        while(count < timesTosend)
        {
              delay(1500);
              Serial.print("AT+CMGS=\"");
              Serial.print("80105595xx");
              Serial.println("\"");
              while (Serial.read() != '>');
              {
                Serial.print("Medicine Requirement by patient");  //SMS body
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z end of message
                Serial.write(0x0D);  // Carriage Return in Hex
                Serial.write(0x0A);  // Line feed in Hex

                //The 0D0A pair of characters is the signal for the end of a line and beginning of another.
                delay(5000);
              }
              count++;
        }
      }
  else if(value1 > 200 && value2 > 200 && value3 > 200 && value4 < 30)
  {
     lcd.clear();
    lcd.print("Wheelchair");
    Serial.print("Wheelchair");
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    while(count<timesTosend)
    {
        delay(1500);
        Serial.print("AT+CMGS=\"");
        Serial.print("90690461xx");
        Serial.println("\"");
        while (Serial.read()!='>');
        {
            Serial.print("Wheelchair Requirement by patient");  //SMS body
            delay(500);
            Serial.write(0x1A);  // sends ctrl+z end of message
            Serial.write(0x0D);  // Carriage Return in Hex
            Serial.write(0x0A);  // Line feed in Hex
            //The 0D0A pair of characters is the signal for the end of a line and beginning of another.
            delay(5000);
        }
        count++;
        }
  }
  else if(value1 < 30 && value2<30 && value3 < 30 && value4 < 30)
  {
    lcd.clear();
    lcd.print("Normal Condition");
    Serial.print("Nothing Condition");
  }
  else if(value1 > 200 && value2 > 200 && value3 > 200 && value4 > 200)
  {
      lcd.clear();
      lcd.print("Critical");
      Serial.print("Critical");
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      Serial.print("ATD + +9190690461xx;");
          delay(100);
          Serial.println();
          delay(30000);            // wait for 30 seconds...
          Serial.println("ATH");   // hang up
          while(count<timesTosend){
          delay(1500);
          Serial.print("AT+CMGS=\"");
          Serial.print("80105595xx");
          Serial.println("\"");
          while (Serial.read()!='>');
          {
            Serial.print("Emergency Call");  //SMS body
            delay(500);
            Serial.write(0x1A);  // sends ctrl+z end of message
            Serial.write(0x0D);  // Carriage Return in Hex
            Serial.write(0x0A);  // Line feed in Hex
            //The 0D0A pair of characters is the signal for the end of a line and beginning of another.
            delay(5000);
          }
          count++;
          }
  }
  else if(value1 < 30 && value2 < 30 && value3 < 30 && value4 > 200)
  {
     lcd.clear();
    lcd.print("Water");
    Serial.print("Water");
   
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
          while(count<timesTosend)
          {
          delay(1500);
          Serial.print("AT+CMGS=\"");
          Serial.print("90690461xx");
          Serial.println("\"");
          while (Serial.read()!='>');
          {
            Serial.print("Water Requirement by patient");  //SMS body
            delay(500);
            Serial.write(0x1A);  // sends ctrl+z end of message
            Serial.write(0x0D);  // Carriage Return in Hex
            Serial.write(0x0A);  // Line feed in Hex
            //The 0D0A pair of characters is the signal for the end of a line and beginning of another.
            delay(5000);
          }
          }
  }
  delay(10000);
}
