#include <Wire.h>

int currentData = 0;
char *sentence = "HELLO";
float actual_num = 1.2;
const int Address = 0x50;

void setup()
{
  Serial.begin(9600);
  Wire.begin(Address);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendDouble);
}

void receiveEvent(int bytes) {
  int data = Wire.read();
  Serial.print("Receive Data: ");
  Serial.println(data);
}

void loop()
{
  delay(100);
  //currentData += 1;
}

void sendInt(){
  Wire.write(currentData);
}

void sendStr(){
  for(int i=0; i<strlen(sentence);i++)
  {
    Wire.write(sentence[i]);
  }
}

void sendDouble(){
  String temp = String(actual_num,1);
  Serial.println(temp);
  for(int i=0; i<temp.length();i++)
  {
     Wire.write(temp[i]);
  }
}
