#include <RH_ASK.h>
#undef int()
#include <stdlib.h>
#include <SPI.h> // Not actually used but needed to compile


int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
char value1=" ";
char value2=" ";
char value3=" ";
char value4=" ";
long int value11;
long int value22;
long int value33;
long int value44;
int timesTosend=1;
int count;
char* values;
char buf1[8];
char buf2[8];
char buf3[8];
char buf4[8];


RH_ASK driver;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);    // Debugging only
  pinMode(6, OUTPUT); 
 driver.init(); 
  if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  // put your main code here, to run repeatedly:
  count = 0;
  //reading the values:
  value11 = analogRead(flexPin1);
  value22 = analogRead(flexPin2);
  value33 = analogRead(flexPin3);
  value44 = analogRead(flexPin4);

  //map function:
  value11 = map(value11, 25000, 125000, 0, 255);
  value22 = map(value22, 25000, 125000, 0, 255);
  value33 = map(value33, 25000, 125000, 0, 255);
  value44 = map(value44, 25000, 125000, 0, 255);

  itoa(value11,buf1,10);
  itoa(value22,buf2,10);
  itoa(value33,buf3,10);
  itoa(value44,buf4,10);

  values=strcat(buf1,",");
  values=strcat(values,buf2);
  values=strcat(values,",");
  values=strcat(values,buf3);
  values=strcat(values,",");
  values=strcat(values,buf4);

  driver.send((uint8_t*)values,strlen(values));
  driver.waitPacketSent();
  delay(1000);
}
  
