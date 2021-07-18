#include <WiFiConnect.h>

String ssid = "your_ssid";
String passwd = "your_passwd";

WiFiConnect wifi(ssid, passwd);

void setup(){
  Serial.begin(9600);
  while (!Serial) {}

  Serial.println("Connecting ...");
  int i;
  // Try 3 times to connect with the wifi
  for (i = 0; i < 3; i++) {
    if (wifi.connect() ) {
      break;
    }
  }

  if (!wifi.connected) {
    Serial.println("Connection Fail!");
      while (true) {}
  }
  else {
    Serial.println("Connected!");
    Serial.print("IP: ");Serial.println(wifi.ip());
    byte buf[6];
    wifi.mac(buf);
    Serial.print("Mac: ");Serial.print(buf[5]);Serial.print(":");
    Serial.print(buf[4]);Serial.print(":");Serial.print(buf[3]);Serial.print(":");
    Serial.print(buf[2]);Serial.print(":");Serial.println(buf[1]);
    Serial.print("RSSI: ");Serial.println(wifi.rssi());
  }
}

void loop(){
}
