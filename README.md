### ✅ Summary
📁 Arduino LAN File Server with SD Card Storage
This project demonstrates how to build a LAN-based File Server using an Arduino with an Ethernet Shield and a microSD card (up to 64GB, formatted as FAT32). The device connects to a local network via an Ethernet cable and exposes a simple HTTP API for uploading and retrieving files from the SD card. Ideal for low-cost, embedded, or offline file storage applications.

📦 Use Cases
Local file storage in sensor-based or data-logging projects

Embedded file sharing without internet dependency

Offline data capture and upload systems (e.g., for kiosks or machines)

Teaching embedded networking and low-level HTTP processing

### Setup 
```text
🛠️ 1. Stack the Ethernet Shield
Plug the Ethernet Shield directly on top of your Arduino Uno/Mega.

It uses SPI pins: D10-D13 for Uno, or ICSP header for Mega.

🛠️ 2. Insert the microSD Card
Plug your microSD card into the SD card slot on the Ethernet Shield.

⚠️ Important: The card must be formatted to FAT32.

Some 64GB cards come preformatted as exFAT which is unsupported by the SD library.

Use a tool like SD Formatter or format via PC to FAT32.

🛠️ 3. Connect the LAN Cable
Connect one end of an Ethernet cable to the RJ45 port on the shield.

Connect the other end to a LAN port on your router or switch (not WAN).

🛠️ 4. Power Up the Arduino
Connect via USB to your PC or use a 9V adapter for standalone use.
```

### Send POST Request to Upload file
```text
POST /upload
Content-Type: multipart/form-data
```
```ssh
curl -X POST -d "This is a test file upload" http://192.168.1.177/upload
```
