### ✅ Summary
Feature	Arduino + Ethernet Shield
Max SD card size	32GB FAT32 (64GB if FAT32)
File Serving	Basic HTML or text, no uploads
Network Interface	LAN via W5100/W5500
Speed	Slow (not suitable for large files)

### Setup 


### Send POST Request to Upload file
```text
POST /upload
Content-Type: multipart/form-data
```
```ssh
curl -X POST -d "This is a test file upload" http://192.168.1.177/upload
```
