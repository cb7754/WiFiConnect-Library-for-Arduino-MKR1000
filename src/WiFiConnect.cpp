#include "WiFiConnect.h"


void WiFiConnect::mac(byte(&buf)[6]) {
  WiFi.macAddress(buf);
}

int WiFiConnect::rssi() {
  return WiFi.RSSI();
}

IPAddress WiFiConnect::ip() {
  return WiFi.localIP();
}

WiFiConnect::WiFiConnect(String ssid, String passwd)
{
  _ssid = ssid;
  _passwd = passwd;
}

bool WiFiConnect::connect() {
  int startTime = millis();
  int timeout = 10 * 1000;
  int i, mil;
  // check for the presence of the shield :
  if (WiFi.status() == WL_NO_SHIELD) {
    return false;
  }

  // attempt to connect to Wifi network:
  mil = millis();
  while (_status != WL_CONNECTED && (mil - startTime) < timeout) {
    _status = WiFi.begin(_ssid, _passwd);
    delay(10 * 1000);
    mil = millis();
    i = 1;
  }

  if (_status == WL_CONNECTED) {
    connected = true;
    return true;
  }
  else {
    connected = false;
    return false;
  }
}
