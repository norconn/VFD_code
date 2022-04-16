#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiUdp.h>
#include <WiFiClientSecureBearSSL.h>

#include <chars.h>
#include <digit.h>

ESP8266WiFiMulti WiFiMulti;

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
int timeDisplay[6] = {8, 8, 8, 8, 8, 8, };
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

char matrixR0val = ' ';
char matrixR1val = ' ';
char matrixR2val = ' ';

unsigned long millislast = 0;
unsigned long millislasttemp = 0;

int temperature;
String location;

int day;

int pwmon = 0;
int pwmoff = 0;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 7200, 3600000);

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

  // Start WiFi
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("WongKei_FreeDialUp", "elpsycongroo");
  // WiFi.begin("WongKei_FreeDialUp", "elpsycongroo");
  Serial.print("Connecting");

  // Start the NTP client
  timeClient.begin();

  // Get local location
  // HTTPClient http;
  // http.begin("http://ip-api.com/line/?fields=city");
  
  // int httpResponse = http.GET();

  // if(httpResponse != 200)
  //    Serial.print("IP Error: HTTP Response = ");
  // else
  // {
  //   location = http.getString();
  //   location.replace("\n","");
  // }
  // http.end();
  location = "Bourges";
}

void loop()
{
  // HTTPClient http;
  String serverPath = "http://wttr.in/" + location + "?format=\"%t+%C\"/";
  String httpPayload;
  int httpResponse;
  String weatherCondition = "";
  int conditionLocation;

  if ((WiFiMulti.run() == WL_CONNECTED))
  {

    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

    client->setInsecure();

    HTTPClient https;


    // Get the time, keep trying if error. Probably still a problem here?
    while(!timeClient.update())
    {
      timeClient.forceUpdate();
    }

    // Get the weather
    if((millis() - millislasttemp) > (3600000) || millislasttemp == 0)
    {
      if (https.begin(*client, "https://wttr.in/Bourges?format=%22%t+%C%22"))
      {  // HTTPS
        Serial.print("[HTTPS] GET...\n");
        // start connection and send HTTP header
        httpResponse = https.GET();

        // httpCode will be negative on error
        if (httpResponse > 0)
        {
          // HTTP header has been send and Server response header has been handled
          Serial.printf("[HTTPS] GET... code: %d\n", httpResponse);

          // file found at server
          if (httpResponse == HTTP_CODE_OK || httpResponse == HTTP_CODE_MOVED_PERMANENTLY)
          {
            httpPayload = https.getString();
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
              matrixL3val = ' ';
              conditionLocation = 7;
            }
          
            for(int i = conditionLocation; httpPayload[i] != '\"'; ++i)
            {
              weatherCondition += httpPayload[i];
            }
          }
        
        millislasttemp = millis();
      }
      else
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpResponse).c_str());

      https.end();
    }
    else
      Serial.printf("[HTTPS] Unable to connect\n");
  }
  https.end();
}
 
  if (timeDisplay[0] != timeClient.getHours() / 10)
  {
    day = timeClient.getDay();
    switch (day)
    {
    case 1:
      matrixR0val = 'M';
      matrixR1val = 'O';
      matrixR2val = 'N';
      break;
    case 2:
      matrixR0val = 'T';
      matrixR1val = 'U';
      matrixR2val = 'E';
      break;
    case 3:
      matrixR0val = 'W';
      matrixR1val = 'E';
      matrixR2val = 'D';
      break;
    case 4:
      matrixR0val = 'T';
      matrixR1val = 'H';
      matrixR2val = 'U';
      break;
    case 5:
      matrixR0val = 'F';
      matrixR1val = 'R';
      matrixR2val = 'I';
      break;
    case 6:
      matrixR0val = 'S';
      matrixR1val = 'A';
      matrixR2val = 'T';
      break;
    case 0:
      matrixR0val = 'S';
      matrixR1val = 'U';
      matrixR2val = 'N';
      break;
    default:
      break;
    }
  }

  timeDisplay[0] = timeClient.getHours() / 10;
  timeDisplay[1] = timeClient.getHours() % 10;
  timeDisplay[2] = timeClient.getMinutes() / 10;
  timeDisplay[3] = timeClient.getMinutes() % 10;
  timeDisplay[4] = timeClient.getSeconds() / 10;
  timeDisplay[5] = timeClient.getSeconds() % 10;

  if ((pwmon > 0) || (pwmoff < 0))
  {
    digit1val = ' ';
    digit2val = ' ';
    digit3val = ' ';
    digit4val = ' ';
    digit5val = ' ';
    digit6val = ' ';
    
    ++pwmoff;
    pwmon = 0;
    // Serial.print("off ");
    // Serial.println(pwmoff, DEC);
  }
  else
  {
    digit1val = timeDisplay[0];
    digit2val = timeDisplay[1];
    digit3val = timeDisplay[2];
    digit4val = timeDisplay[3];
    digit5val = timeDisplay[4];
    digit6val = timeDisplay[5];

    ++pwmon;
    pwmoff = 0;
    // Serial.print("on ");
    // Serial.println(pwmon, DEC);
  }
  
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
      // Serial.println("Something's gone wrong...continuing regardless!");
      break;
  }
  
  if(grid < 7)
    payload[4] = 0b01000000 >> grid;
  else
    payload[5] = 0b10000000 >> (grid - 7);


}