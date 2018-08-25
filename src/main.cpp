#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h>
#include <WiFiManager.h>
#include <EEPROM.h>


#define serial "sensor-luminosidade"
#define timeout 3000

#define HOST "10.7.227.121"
#define POSTDISPOSITIVO "/manager/post/device/"
#define PORT 3002 //WS

#define SENSOR_PIN A0

String serialSensor = "sensorLum";
String token = "QwrC79NKZOjmgHTeb2qY";

SocketIOClient socket;
unsigned long int lastTime = millis();

void sendValue();

void setup(){
    pinMode(SENSOR_PIN, OUTPUT);
    Serial.begin(115200);
    WiFiManager wifi;
    wifi.autoConnect(serial);

    String JSON;
    JSON += "{\"token\":\""+token+ "\",\"data\":{\"name\": \"sensorLuminosidade\", \"serial\": \""+ serialSensor +"\",\"protocol\":\"ws\",\"sensors\":[{\"key\": \"LUM\",\"unit\": \"percentual\",\"type\":\"number\",\"tag\":\"SensorLuminosidade\"}]}}";
    
    if (!socket.connect(HOST, PORT)){
    return;
    Serial.println("!socket.connect");
  }
  else if (socket.connected()){
    socket.emit(POSTDISPOSITIVO, JSON);
    Serial.println("connect");
  }

}

void loop(){
    socket.monitor();
    if((millis()-lastTime) < timeout){
        sendValue();
        lastTime = millis();
    }
}

void sendValue(){
    String sensorValue = String(analogRead(SENSOR_PIN));
    Serial.print(sensorValue);
    socket.emit(POSTDISPOSITIVO, sensorValue);
};