/*

 * RST/Reset   RST          4             
 * SPI SS      SDA(SS)      5            
 * SPI MOSI    MOSI         11 
 * SPI MISO    MISO         12 
 * SPI SCK     SCK          13 
 *
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         4          
#define SS_PIN          5         

MFRC522 mfrc522(SS_PIN, RST_PIN);  

void setup() {
	Serial.begin(9600);		
	while (!Serial);		
	SPI.begin();			
	mfrc522.PCD_Init();		
	delay(4);			
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
