# WiFiConnect-Library-for-Arduino-MKR1000
Library to connect to wifi with a Arduino MKR1000

How To Use:
1) Install the library in your arduino libraries folder
2) Include in your sketch: #include "WiFiConnect.h"
3) declare WiFiConnect wifi(your_ssid, your_passwd)
4) then in setup() do: 

`if (!wifi.connected) {`

    Serial.println("Connection Fail!");
  
    while (true) {}
    
`}`

`else {`

    Serial.println("Connected!");
  
`}`



wifi.ip() returns a IPAddress with the local IP

byte mac[6]
wifi.mac(mac) returns the MAC Address in mac array

wifi.rssi() returns the signal strenght

wifi.connect is true when connected

See example.
