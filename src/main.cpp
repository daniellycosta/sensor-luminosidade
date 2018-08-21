#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h>
#include <WiFiManager.h>
#include <EEPROM.h>
#include<SaIoTDeviceLib.h>

#define serial "sensor-luminosidade"
#define HOST "10.7.227.121"
#define POSTDISPOSITIVO "/manager/post/device/"
#define PORT 3002 //WS

#define SENSOR_PIN A0

String serialSensor = "sensorLum";
String token = "QwrC79NKZOjmgHTeb2qY";

SocketIOClient socket;
//int sensorValue = analogRead(SENSOR_PIN);

void setup(){
    Serial.begin(115200);
    WiFiManager wifi;
    wifi.autoConnect(serial);

    String JSON;
    JSON += "{\"token\":\""+token+ "\",\"data\":{\"name\": \"sensorLuminosidade\",  \"serial\": \""+ serialSensor +"\",\"protocol\":\"ws\",\"controllers\":[{\"key\":\"ON\",\"class\":\"onoff\",\"tag\":\"on/off\"}],\"sensors\":[{\"key\": \"LUM\",\"unit\": \"percentual\",\"type\":\"number\",\"tag\":\"SensorLuminosidade\"}]}}";
}

void loop(){

}