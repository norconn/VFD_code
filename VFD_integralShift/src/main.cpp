#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>

#include <chars.h>
#include <digit.h>

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600, 1000);

// Pin definitions

const int dataPin = D3;   // D6 = DI
const int blankPin = D4;   // D7 = STB
const int clockPin = D5;  // D8 = CLK

// Grid Numbers

const int matrixL0 = 3;   // 1G
const int matrixL1 = 4;   // 2G
const int matrixL2 = 5;   // 3G
const int matrixL3 = 6;   // 4G

const int digit0 = 2;     // 5G - digits 1 - 3
const int digit1 = 1;
const int digit2 = 0;

const int response = 7;   // 6G-1

const int digit3 = 8;     // 6G-2
const int digit4 = 9;     // 6G-3
const int digit5 = 10;    // 6G-4
const int digit6 = 11;    // 7G

const int matrixR0 = 12;  // 8G
const int matrixR1 = 13;  // 9G
const int matrixR2 = 14;  // 10G

// VFD grid Count variable

int grid = 0;

// Display data variables

int payload[12] = {0};
int timeDisplay[6];
int digits[7] = {0, 1, 2, 3, 4, 5, 6};

bool dots[6] = {0, 0, 1, 0, 1, 0};
bool commas[6] = {0};
bool colons[2][2] = {
  {0, 0},
  {0, 0}};

char matrixL0val = ' ';
char matrixL1val = ' ';
char matrixL2val = ' ';
char matrixL3val = ' ';
bool percent = 0;

int digit0val = ' ';
int digit1val = ' ';
int digit2val = ' ';

bool responseval = 0;
bool fast = 0;
bool mid = 0;
bool slow = 0;

int digit3val = ' '; 
int digit4val = ' '; 
int digit5val = ' ';
int digit6val = ' ';

bool animal = 0;
bool HI = 0;
bool OKval = 0;
bool LO = 0;

bool d6barL = 1;
bool d6barR = 1;

char matrixR0val = 'A';
char matrixR1val = 'B';
char matrixR2val = 'C';

unsigned long millislast = 0;
unsigned long millislasttemp = 0;

int temperature;
String location;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 3600000);

void sendData();
void assemblePayload();

void setup()
{
  // Pin modes
  pinMode(dataPin, OUTPUT);
  pinMode(blankPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Start serial link for debugging
  Serial.begin(115200);
  Serial.println();

  // Start WiFi and wait for connection
  WiFi.begin("WongKei_FreeDialUp", "elpsycongroo");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  // Start the NTP client
  timeClient.begin();

  // Get local location
  HTTPClient http;
  http.begin("http://ip-api.com/line/?fields=city");
  
  int httpResponse = http.GET();

  if(httpResponse != 200)
     Serial.print("Error: HTTP Response = ");
  else
  {
    location = http.getString();
    location.replace("\n","");
  }
  http.end();
}

void loop()
{
  // Get the time, keep trying if error. Probably still a problem here?
  while(!timeClient.update())
  {
    timeClient.forceUpdate();
  }

  if(Serial.available())
  {
    matrixR0val = matrixR1val;
    matrixR1val = matrixR2val;
    matrixR2val = Serial.read();
  }

  // Get the weather
  if((millis() - millislasttemp) > (3600000) || millislasttemp == 0)
  {
    HTTPClient http;
    String serverPath = "http://wttr.in/" + location + "?format=\"%t+%C\"";
    Serial.println(serverPath);
    http.begin(serverPath);
    
    int httpResponse = http.GET();
    String httpPayload;
    int conditionLocation;

    if(httpResponse != 200)
    {
      Serial.print("Error: HTTP Response = ");
      Serial.println(httpResponse);
    }
    else
    {
      httpPayload = http.getString();
      Serial.println(httpPayload);

      if(httpPayload[7] == ' ')
      {
        matrixL0val = httpPayload[1];
        matrixL1val = httpPayload[2];
        matrixL2val = httpPayload[3];
        matrixL3val = '$';
        conditionLocation = 8;
      }
      else
      {
        matrixL0val = httpPayload[1];
        matrixL1val = httpPayload[2];
        matrixL2val = '$';
        conditionLocation = 7;
      }
      
      String weatherCondition = "";
      for(int i = conditionLocation; httpPayload[i] != '\"'; ++i)
      {
        weatherCondition += httpPayload[i];
      }
      Serial.println(weatherCondition);
    }

    millislasttemp = millis();
    http.end();
  }
 
  timeDisplay[0] = timeClient.getHours() / 10;
  timeDisplay[1] = timeClient.getHours() % 10;
  timeDisplay[2] = timeClient.getMinutes() / 10;
  timeDisplay[3] = timeClient.getMinutes() % 10;
  timeDisplay[4] = timeClient.getSeconds() / 10;
  timeDisplay[5] = timeClient.getSeconds() % 10;

  digit1val = timeDisplay[0];
  digit2val = timeDisplay[1];
  digit3val = timeDisplay[2];
  digit4val = timeDisplay[3];
  digit5val = timeDisplay[4];
  digit6val = timeDisplay[5];

  grid = 0;
  while (grid <= 14)
  {
    assemblePayload();
    sendData();
    for(int i = 0; i < 12; ++i)   // make sure the payload is empty
      payload[i] = 0;
    
    ++grid;
  }
}

void sendData()
{
  digitalWrite(blankPin, LOW);

  for(int i = 0; i < 11; ++i)
    shiftOut(dataPin,clockPin, MSBFIRST, payload[i]);

  digitalWrite(blankPin, HIGH);
}

void assemblePayload()
{
  switch(grid)
  {
    case matrixL0:
      fillmatrix(matrixL0val);
      break;

    case matrixL1:
      fillmatrix(matrixL1val);
      break;

    case matrixL2:
      fillmatrix(matrixL2val);
      break;

    case matrixL3:
      fillmatrix(matrixL3val);
      if(percent)
        payload[10] |= 0b10;
      break;

    case digit0:      // Grid 5G-1
      filldigit(0, digit0val, dots, commas, colons);
      break;

    case digit1:        // Grids 5G-2, -3
      filldigit(1, digit1val, dots, commas, colons);
      break;
    case digit2:
      filldigit(2, digit2val, dots, commas, colons);   
      break;

    case response:    // Grid 6G-1
      if(responseval)
        payload[10] |= 0b00000010;
      if(fast)
        payload[10] |= 0b00010000;
      if(mid)
        payload[10] |= 0b00001000;
      if(slow)
        payload[10] |= 0b00000100;
      break;

    case digit3:    // 6G-2
      filldigit(3, digit3val, dots, commas, colons);   
      break;

    case digit4:    // 6G-2
      filldigit(4, digit4val, dots, commas, colons);   
      break;

    case digit5:    // 6G-3
      filldigit(5, digit5val, dots, commas, colons);   
      break;

    case digit6:    // 7G
      filldigit(6, digit6val, dots, commas, colons);

      if(animal)
        payload[10] |= 0b00010000;
      if(HI)
        payload[10] |= 0b00001000;
      if(OKval)
        payload[10] |= 0b00000100;
      if(LO)
        payload[10] |= 0b00000010;

      if(d6barL)
        payload[9] |= 0b00000001;
      if(d6barR)
        payload[9] |= 0b00000010;
      break;

    case matrixR0:
      fillmatrix(matrixR0val);
      break;

    case matrixR1:
      fillmatrix(matrixR1val);
      break;

    case matrixR2:
      fillmatrix(matrixR2val);
      break;

    default:
      Serial.println("Something's gone wrong...continuing regardless!");
      break;
  }
  
  if(grid < 7)
    payload[4] = 0b01000000 >> grid;
  else
    payload[5] = 0b10000000 >> (grid - 7);


}