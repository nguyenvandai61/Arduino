/*
  SD card read/write
  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10 (for MKRZero SD: SDCARD_SS_PIN)
   DHT
*/
#include <SPI.h>
#include <SD.h>
#include <DHT.h>
const int DHTPIN = 2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  dht.begin();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  
  
    
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("DHT.txt", FILE_WRITE);
  if (isnan(t) || isnan(h)) {
    Serial.println("READING error");

  }
  else
  {
    
    // if the file opened okay, write to it:
    if (myFile) {
      Serial.print("Writing to DHT.txt...");
      myFile.println("Nhiet do: ");
      myFile.print(round(t));
      myFile.println("Do am: ");
      myFile.print(round(h));
      myFile.print(" %");
      myFile.println();
      // close the file:
      myFile.close();
      Serial.println("done.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening DHT.txt");
    }

  }
  // re-open the file for reading:
  myFile = SD.open("DHT.txt");
  if (myFile) {
    Serial.println("<------------------------------------------------------------->");
    Serial.println("DHT.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening DHT.txt");
  }
}

void loop() {
  // nothing happens after setup
}
