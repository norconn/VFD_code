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

bool dots[6] = {0, 1, 0, 1, 0, 0};
bool commas[6] = {0};
bool colons[2][2] = {
  {0, 0},
  {0, 0}};

char matrixL0val = ' ';
char matrixL1val = ' ';
char matrixL2val = ' ';
char matrixL3val = ' ';
bool percent = 0;

int digit0val = 0;
int digit1val = 0;
int digit2val = 0;

bool responseval = 0;
bool fast = 0;
bool mid = 0;
bool slow = 0;

int digit3val = 0; 
int digit4val = 0; 
int digit5val = 0;
int digit6val = ' ';

bool animal = 0;
bool HI = 0;
bool OKval = 0;
bool LO = 0;

bool d6barL = 0;
bool d6barR = 0;

char matrixR0val = ' ';
char matrixR1val = ' ';
char matrixR2val = ' ';

unsigned long millislast = 0;
unsigned long millislasttemp = 0;

int temperature;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 3600000);

void sendData();
void assemblePayload();

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(blankPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  Serial.begin(115200);
  Serial.println();

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

  timeClient.begin();
}

void loop()
{
  // Get the time, keep trying if error. Probably still a problem here?
  
    while(!timeClient.update())
    {
      timeClient.forceUpdate();
    }

  // Get the temperature
  if((millis() - millislasttemp) > (3600000) || millislasttemp == 0)
  {
    HTTPClient http;
    String serverPath = "http://wttr.in/Bourges?format=\"%t\"";
    http.begin(serverPath);
    
    int httpResponse = http.GET();
    String httpPayload;

    if(httpResponse != 200)
    {
      Serial.print("Error: HTTP Response = ");
      Serial.println(httpResponse);
    }
    else
    {
      httpPayload = http.getString();
      Serial.println(httpPayload);
    }
  
    matrixL0val = httpPayload[1];
    matrixL1val = httpPayload[2];
    matrixL2val = httpPayload[3];
    matrixL3val = '$';

    millislasttemp = millis();
    Serial.println(temperature);
  }
 
  timeDisplay[0] = timeClient.getHours() / 10;
  timeDisplay[1] = timeClient.getHours() % 10;
  timeDisplay[2] = timeClient.getMinutes() / 10;
  timeDisplay[3] = timeClient.getMinutes() % 10;
  timeDisplay[4] = timeClient.getSeconds() / 10;
  timeDisplay[5] = timeClient.getSeconds() % 10;

  digit0val = timeDisplay[0];
  digit1val = timeDisplay[1];
  digit2val = timeDisplay[2];
  digit3val = timeDisplay[3];
  digit4val = timeDisplay[4];
  digit5val = timeDisplay[5];

  grid = 0;
  while (grid < 14)
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