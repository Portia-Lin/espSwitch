/*********
  ESP8266
  WIFI SWITCH
*********/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include "index.h"

const int output = 2;

ESP8266WebServer server(80);

void(* resetFunc) (void) = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Waiting for reset wifi!");
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.println(".");
  delay(1000);
  
  pinMode(output, OUTPUT);
  digitalWrite(output, LOW);

  WiFiManager wifiManager;

  if(digitalRead(0) == LOW) {
    wifiManager.resetSettings();
    Serial.println("Reset saved settings!");
    }

  wifiManager.autoConnect("AutoConnectAP");
  server.on("/", index_page);
  server.on("/on", sendOn);
  server.on("/off", sendOff);
  server.on("/reset", sendReset);
  server.begin();
}

void loop() {
  server.handleClient();
}

void index_page() {
 String s = INDEX_PAGE;
 server.send(200, "text/html", s);
}

void sendOn() {
  digitalWrite(output, HIGH);
  server.sendHeader("Location","/");
  server.send(303); 
}

void sendOff() {
  digitalWrite(output, LOW);
  server.sendHeader("Location","/");
  server.send(303); 
}

void sendReset() {
  server.sendHeader("Location","/");
  server.send(303);
  resetFunc();
}
