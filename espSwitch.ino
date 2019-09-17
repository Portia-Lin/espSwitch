/*************
  ESP8266
  WIFI SWITCH
*************/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

const int outputPin = 2;

ESP8266WebServer server(80);

void(* resetFunc) (void) = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println("Waiting for reset wifi!");
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.println(".");
  delay(1000);
  
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  Serial.println("Set output to LOW");

  WiFiManager wifiManager;

  if(digitalRead(0) == LOW) {
    wifiManager.resetSettings();
    Serial.println("Reset saved settings!");
    }

  wifiManager.autoConnect("espSwitch");
  server.on("/", index_page);
  server.on("/toggle", toggle);
  server.on("/reset", sendReset);
  server.begin();
}

void loop() {
  server.handleClient();
}

<<<<<<< Updated upstream
void sendOn() {
  digitalWrite(output, HIGH);
  Serial.println("Set output to HIGH");
  server.sendHeader("Location","/");
  server.send(303); 
=======
void index_page() {
  String indexStart = INDEX_START;
  String indexState;
  if(digitalRead(outputPin) == LOW) {
    indexState = ("<h1 class='center'>= OFF =</h1>");
  }
  else {
    indexState = ("<h1 class='center'>= ON =</h1>");
  }
  String indexEnd = INDEX_END;
  String page = (indexStart + indexState + indexEnd);
  server.send(200, "text/html", page);
>>>>>>> Stashed changes
}

void toggle() {
  digitalWrite(outputPin, !digitalRead(outputPin));
  Serial.print("Set output to: ");
  Serial.println(digitalRead(outputPin));
  server.sendHeader("Location","/");
  server.send(303); 
}

void sendReset() {
  server.sendHeader("Location","/");
  server.send(303);
  Serial.println("Reboot...");
  resetFunc();
}

void index_page() {
 String mainPage = ("<!DOCTYPE html><head><title>Main page</title><meta charset='UTF-8'><meta name='viewport' content='width = device-width, initial-scale = 1.0, maximum-scale = 1.0'><link href='all.css' rel='stylesheet'><style>body{ background-color:#F7F9FD; } .container{ width:20rem; margin-left:auto; margin-right:auto; } .center{ text-align:center; } .m_left{ margin-left:1rem; } .m_bottom{ margin-bottom:3rem; } .link{ display:block; width:100%; padding:1rem 0rem; border-radius:0.5rem; background-color:#DA5868; font-family:'Montserrat',sans-serif; font-size:11pt; letter-spacing:0.05rem; text-align:center; font-weight:bold; text-decoration:none; outline:none; color:white; } .link:hover{ background-color:#CD3341; } </style></head><body><div class='container'><div class='header'><h1 class='center'><font color='#DA5868'>Hello!</font></h1><h3 class='center'>[ Hostname ]</h3><h3 class='center'>Main page</h3></div><div class='menu'><a class='link' href='on'>Send ON</a><br><a class='link' href='off'>Send OFF</a><br><br><a class='link' href='reset'>Reboot module</a><br><br><p><font color='#6D6D6D'>Якщо ви натиснули кнопку <font color='#DA5868'>Reboot module</font>, ви повинні самостійно перейти на головну сторінку!</font></p></div></div></body></html>");
 server.send(200, "text/html", mainPage);
}
