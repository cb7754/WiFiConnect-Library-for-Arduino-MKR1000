#include <WiFi101.h>

class WiFiConnect {
private:
  String _ssid;
  String _passwd;
  bool _connected;
  int _status = WL_IDLE_STATUS;

public:
  WiFiConnect(String ssid, String passwd);
  bool connect();
  IPAddress ip();
  void mac(byte(&buf)[6]);
  int rssi();
  bool connected;
};
