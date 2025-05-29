### ✅ Summary
Feature	Arduino + Ethernet Shield
Max SD card size	32GB FAT32 (64GB if FAT32)
File Serving	Basic HTML or text, no uploads
Network Interface	LAN via W5100/W5500
Speed	Slow (not suitable for large files)

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
