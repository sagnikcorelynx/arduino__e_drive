#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);

void setup() {
  Serial.begin(9600);

  Ethernet.begin(mac, ip);
  server.begin();

  if (!SD.begin(4)) {
    Serial.println("SD init failed!");
    return;
  }
  Serial.println("Ready");
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    String request = "";

    // Read HTTP request headers
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;

        if (c == '\n' && currentLineIsBlank) {
          if (request.indexOf("POST /upload") != -1) {
            File file = SD.open("upload.txt", FILE_WRITE);

            // Write rest of payload (limited support)
            int contentLength = 100;  // Optional: extract from headers
            for (int i = 0; i < contentLength; i++) {
              if (client.available()) {
                file.write(client.read());
              }
            }
            file.close();

            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/plain");
            client.println("Connection: close");
            client.println();
            client.println("File uploaded.");
          } else {
            client.println("HTTP/1.1 404 Not Found");
            client.println();
          }
          break;
        }

        if (c == '\n') currentLineIsBlank = true;
        else if (c != '\r') currentLineIsBlank = false;
      }
    }
    delay(1);
    client.stop();
  }
}