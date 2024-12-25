// // Receive a NDEF message from a Peer and
// // display the payload of the first record on a LCD
// //
// // SeeedStudio NFC shield http://www.seeedstudio.com/depot/NFC-Shield-V20-p-1370.html
// // LCD using the Adafruit backpack http://adafru.it/292
// // Adafruit Liquid Crystal library https://github.com/adafruit/LiquidCrystal
// // Use a Android of BlackBerry phone to send a message to the NFC shield

// #include "SPI.h"
// #include "PN532/PN532/snep.h"
// #include "PN532/PN532_SPI/PN532_SPI.h"

// #include "NdefMessage.h"

// #include "Wire.h"
// #include "LiquidCrystal.h"

// // PN532_SPI pn532spi(SPI, 10);
// // SNEP nfc(pn532spi);
// // uint8_t ndefBuf[128];

// // // Connect via i2c, default address #0 (A0-A2 not jumpered)
// // LiquidCrystal lcd(0);

// void setup() {
//     // SERIAL.begin(9600);
//     // // set up the LCD's number of rows and columns:
//     // lcd.begin(16, 2);
//     // SERIAL.println("NFC Peer to Peer Example - Receive Message");
// }

// void loop() {
// //     SERIAL.println("Waiting for message from a peer");
// //     int msgSize = nfc.read(ndefBuf, sizeof(ndefBuf));
// //     if (msgSize > 0) {
// //         NdefMessage msg  = NdefMessage(ndefBuf, msgSize);
// //         msg.print();

// //         NdefRecord record = msg.getRecord(0);

// //         int payloadLength = record.getPayloadLength();
// //         byte payload[payloadLength];
// //         record.getPayload(payload);

// //         // The TNF and Type are used to determine how your application processes the payload
// //         // There's no generic processing for the payload, it's returned as a byte[]
// //         int startChar = 0;
// //         if (record.getTnf() == TNF_WELL_KNOWN && record.getType() == "T") { // text message
// //             // skip the language code
// //             startChar = payload[0] + 1;
// //         } else if (record.getTnf() == TNF_WELL_KNOWN && record.getType() == "U") { // URI
// //             // skip the url prefix (future versions should decode)
// //             startChar = 1;
// //         }

// //         // Force the data into a String (might fail for some content)
// //         // Real code should use smarter processing
// //         String payloadAsString = "";
// //         for (int c = startChar; c < payloadLength; c++) {
// //             payloadAsString += (char)payload[c];
// //         }

// //         // print on the LCD display
// //         lcd.setCursor(0, 0);
// //         lcd.print(payloadAsString);

// //         SERIAL.println("\nSuccess");
// //     } else {
// //         SERIAL.println("Failed");
// //     }
// //     delay(3000);
// }


// Sends a NDEF Message to a Peer
// Requires SPI. Tested with Seeed Studio NFC Shield v2
#include <NfcAdapter.h>
#include <PN532/PN532/PN532.h>
#include "SPI.h"
#include "PN532/PN532_SPI/PN532_SPI.h"
#include "PN532/PN532/snep.h"
#include "NdefMessage.h"

PN532_SPI pn532spi(SPI, 10);
SNEP nfc(pn532spi);
uint8_t ndefBuf[128];

void setup() {
    SERIAL.begin(9600);
    SERIAL.println("NFC Peer to Peer Example - Send Message");
}

void loop() {
    SERIAL.println("Send a message to Peer");

    NdefMessage message = NdefMessage();
    message.addUriRecord("http://shop.oreilly.com/product/mobile/0636920021193.do");
    //message.addUriRecord("http://arduino.cc");
    //message.addUriRecord("https://github.com/don/NDEF");


    int messageSize = message.getEncodedSize();
    if (messageSize > sizeof(ndefBuf)) {
        SERIAL.println("ndefBuf is too small");
        while (1) {
        }
    }

    message.encode(ndefBuf);
    if (0 >= nfc.write(ndefBuf, messageSize)) {
        SERIAL.println("Failed");
    } else {
        SERIAL.println("Success");
    }

    delay(3000);
}
