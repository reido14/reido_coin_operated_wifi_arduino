#include <SPI.h>
#include "SdFat.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
const uint8_t chipSelect = SS;
String b="";
int counter=0;
int usedcounter=0;
int wrtcounter=0;
int coincounter=0;
int coinwrtcounter=0;
int coinusedcounter=0;
String inString;
String b2="";
int counter2=0;
int usedcounter2=0;
int wrtcounter2=0;
String inString2;
int screensaver=0;
SdFat SD;
File myFile;
ArduinoOutStream cout(Serial);
int a =0;
int e = 6; 
int r = 8;
int i = 7;
int o =0;
int o1=0; 
int led1hr = 3;
int led1d = 4;
int buttoncounter=0;
#define error(s) SD.errorHalt(F(s))
void r1hr_get_code() {  
  char line[25];
  int n;
  SdFile rdfile("code1hr.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading code1hr.txt file");}
  Serial.println(F("Selecting Specific Voucher For 1hr"));
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
              counter++;
          if (counter == usedcounter){
               b=line;}    }}
    counter = 0;
    Serial.println(b);
  rdfile.close(); }
void r1hr_get_counter() {  
   char line[25];
  int n;
  Serial.println(F("Getting Counter For 1hr"));
  SdFile rdfile("counter1hr.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading counter1hr.txt");}
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
 usedcounter=0;
inString = line;
usedcounter = (inString.toInt());
    } }
   counter = 0;
   rdfile.close();  }
void r1hr_write_counter(){
  Serial.println(F("Writing Counter For 1hr"));
  myFile = SD.open("counter1hr.txt", FILE_WRITE);
  if (myFile) {
    wrtcounter = usedcounter+1;
  myFile.println(wrtcounter);
    myFile.close(); } }
void r3hr_get_code() {  
  char line[25];
  int n;
  SdFile rdfile("code3hr.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading code3hr.txt file");}
  Serial.println(F("Selecting Specific Voucher For 3hr"));
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
              counter++;
          if (counter == usedcounter){
               b=line;                 }    }}
    counter = 0;
     Serial.println(b);
  rdfile.close(); }
void r3hr_get_counter() {  
   char line[25];
  int n;
  Serial.println(F("Getting Counter For 3hr"));
  SdFile rdfile("counter3hr.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading counter3hr.txt"); }
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
 usedcounter=0;
inString = line;
usedcounter = (inString.toInt());    }  }
   counter = 0;
   Serial.println(usedcounter);
   rdfile.close();  }
void r3hr_write_counter(){
  Serial.println(F("Writing Counter For 3hr"));
  myFile = SD.open("counter3hr.txt", FILE_WRITE);
  if (myFile) {
    wrtcounter = usedcounter+1;
  myFile.println(wrtcounter);
    myFile.close();} 
    Serial.println(wrtcounter);}
void r12hr_get_code() {  
  char line[25];
  int n;
  SdFile rdfile("code12hr.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading code1hr.txt file"); }
  Serial.println(F("Selecting Specific Voucher For 12hr"));
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
              counter++;
          if (counter == usedcounter){
               b=line;                }    } }
    counter = 0;
     Serial.println(b);
  rdfile.close(); }
void r12hr_get_counter() {  
   char line[25];
  int n;
  Serial.println(F("Getting Counter For 12hr"));
  SdFile rdfile("counter12hr.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading counter12hr.txt"); }
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
 usedcounter=0;
inString = line;
usedcounter = (inString.toInt());    } }
   counter = 0;
      Serial.println(usedcounter);
   rdfile.close();  }
void r12hr_write_counter(){
  Serial.println(F("Writing Counter For 12hr"));
  myFile = SD.open("counter12hr.txt", FILE_WRITE);
  if (myFile) {
    wrtcounter = usedcounter+1;
  myFile.println(wrtcounter);
    myFile.close();} 
    Serial.println(wrtcounter);}
void r1day_get_code() {  
  char line[25];
  int n;
  SdFile rdfile("code1day.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading code1day.txt file");}
  Serial.println(F("Selecting Specific Voucher For 1day"));
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
              counter++;
          if (counter == usedcounter){
               b=line;}    }}
    counter = 0;
     Serial.println(b);
  rdfile.close(); }
void r1day_get_counter() {  
   char line[25];
  int n;
  Serial.println(F("Getting Counter For 1day"));
  SdFile rdfile("counter1day.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading counter1day.txt"); }
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
 usedcounter=0;
inString = line;
usedcounter = (inString.toInt());    } }
   counter = 0;
      Serial.println(usedcounter);
   rdfile.close();  }
void r1day_write_counter(){
  Serial.println(F("Writing Counter For 1day"));
  myFile = SD.open("counter1day.txt", FILE_WRITE);
  if (myFile) {
    wrtcounter = usedcounter+1;
  myFile.println(wrtcounter);
    myFile.close();} 
  Serial.println(wrtcounter);}
void coin_get_counter() {  
   char line[25];
  int n;
  Serial.println(F("Getting Counter for insertedcoin.txt"));
  SdFile rdfile("insertedcoin.txt", O_READ);
  if (!rdfile.isOpen()) {
    error("error reading insertedcoin.txt");}
  while ((n = rdfile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
 coinusedcounter=0;
inString = line;
coinusedcounter = (inString.toInt());     } }
   coincounter = 0;
      Serial.println(usedcounter);
   rdfile.close();  }
void coin_write_counter(){
  Serial.println(F("Writing Counter For insertedcoin.txt"));
  myFile = SD.open("insertedcoin.txt", FILE_WRITE);
  if (myFile) {
    coinwrtcounter = coinusedcounter+5;
    Serial.println(F("TOTAL COIN"));
   Serial.println(coinwrtcounter);
  myFile.println(coinwrtcounter);
    myFile.close();  } }
void setup(void) {    
  Serial.begin(9600);
  while (!Serial) {
    SysCall::yield();}
  if (!SD.begin(chipSelect, SD_SCK_MHZ(50))) {
    SD.initErrorHalt();}
 lcd.init();
  lcd.backlight();
          lcd.begin(16, 2);
  lcd.setCursor(0,0);
     lcd.print(F("     Welcome "));
     lcd.setCursor(0, 1);
     lcd.print(F(" Insert P5 Coin"));
}
void loop() {       
   int button = digitalRead(r);
        int button3 = digitalRead(i);           
    if (button == LOW) {
        coin_get_counter();
    coin_write_counter();
      Serial.println(F("5 peso detected"));
      screensaver=0;
      a = a +5;
      lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print(F("CODE  FOR  1hr"));
          lcd.setCursor(0, 1);
        lcd.print(F("Coin ="));
        lcd.setCursor(12, 1);
    lcd.print(a); 
   if (a >= 15){
     lcd.setCursor(0, 0);
      lcd.print(F("CODE    FOR   3hrs"));
       lcd.setCursor(0, 1);
         lcd.print(F("Coins ="));
        lcd.setCursor(12, 1);
    lcd.print(a); }
     if (a >= 20){
     lcd.setCursor(0, 0);
      lcd.print(F("CODE    FOR  12hrs"));
       lcd.setCursor(0, 1);
         lcd.print(F("Coins ="));
        lcd.setCursor(12, 1);
    lcd.print(a); }
     if (a >= 40){
     lcd.setCursor(0, 0);
      lcd.print(F("CODE    FOR   1day"));
       lcd.setCursor(0, 1);
       lcd.print(F("Coins ="));
        lcd.setCursor(12, 1);
    lcd.print(a); 
   }    }
if (buttoncounter == 0){
    if (button3 == LOW) {
      Serial.println(F("show code button pressed"));
        screensaver=0;
         lcd.clear();  
  if (a==0){
        lcd.setCursor(0, 0);
        lcd.print(F("  Please Insert"));
        lcd.setCursor(0, 1);
        lcd.print(F("   5 Peso Coin"));
      }
      if(a >=5 and a <=14){
    r1hr_get_counter();
    r1hr_write_counter();
    r1hr_get_code();
        a= a - 5;
        lcd.setCursor(0, 0);
  lcd.print(F("CODE :"));
         lcd.setCursor(8, 0);
  lcd.print(b);
      lcd.setCursor(0, 1);
      lcd.print(F("Copy and Sign-in"));
  delay(5000);
  buttoncounter=2;
   lcd.setCursor(0, 1);
      lcd.print(F("Press CLR Button"));
      }
            if(a >=15 and a <=19){
    r3hr_get_counter();
    r3hr_write_counter();
    r3hr_get_code();
        a= a - 15;
        lcd.setCursor(0, 0);
  lcd.print(F("CODE :"));
         lcd.setCursor(8, 0);
  lcd.print(b);
      lcd.setCursor(0, 1);
      lcd.print(F("Copy and Sign-in"));
  delay(5000);
  buttoncounter=2;
     lcd.setCursor(0, 1);
      lcd.print(F("Press CLR Button"));}
            if(a >=20 and a <=39 ){
    r12hr_get_counter();
    r12hr_write_counter();
    r12hr_get_code(); 
        a= a - 20;
        lcd.setCursor(0, 0);
  lcd.print(F("CODE :"));
         lcd.setCursor(8, 0);
  lcd.print(b);
      lcd.setCursor(0, 1);
      lcd.print(F("Copy and Sign-in"));
    delay(5000);
  buttoncounter=2;
     lcd.setCursor(0, 1);
      lcd.print(F("Press CLR Button"));}
            if(a >=40 and a <=50 ){
 r1day_get_counter();
    r1day_write_counter();
    r1day_get_code(); 
        a= a - 40;
        lcd.setCursor(0, 0);
  lcd.print(F("CODE :"));
         lcd.setCursor(8, 0);
  lcd.print(b);
      lcd.setCursor(0, 1);
      lcd.print(F("Copy and Sign-in"));
  delay(5000);
  buttoncounter=2;
     lcd.setCursor(0, 1);
      lcd.print(F("Press CLR Button"));     }
if(a>51){
lcd.setCursor(0, 0);
        lcd.print(F("!!!ERROR COIN!!!"));
        lcd.setCursor(0, 1);
        lcd.print(F("    ACCEPTOR"));} 
      a=0;
      b="";    }}
else if(buttoncounter ==2){
   if (button3 == LOW) {
  buttoncounter= 0;
lcd.print(F("CODE     CLEARED"));
     Serial.println(F("clear button pressed"));
delay(1000);
      lcd.clear();
  lcd.setCursor(0,0);
lcd.print(F(" Insert P5 Coin"));
     lcd.setCursor(0, 1);
      lcd.print(F(" P5/1hr P35/day"));   } }
else{
}
 if (button == HIGH) {
  screensaver++;
    delay(5);
  if (screensaver > 24000){
    screensaver = 25005;
o++;
      lcd.setCursor(16, 1); 
   lcd.print(o);
  if (o>500){
    o1++;
    o=0;
if (o1 >= 5){
  lcd.clear();
    lcd.setCursor(0, 0);
 lcd.print(F("Insert  P5  Coin"));
     lcd.setCursor(0, 1);
     lcd.print(F(" Select 1hr/1day"));
   o=0;}
   if(o1 >= 10){
  lcd.clear();
      lcd.setCursor(0, 0);
 lcd.print(F(" Copy   Voucher "));
     lcd.setCursor(0, 1);
     lcd.print(F(" FOR 15 SECONDS "));
   o=0;}
if(o1>=15){
  lcd.clear();
      lcd.setCursor(0, 0);
  lcd.print(F("     SIGN IN"));
     lcd.setCursor(0, 1);
   lcd.print(F("      DONE  "));
   o=0;}
if(o1>=20){
  lcd.clear();
      lcd.setCursor(0, 0);
  lcd.print(F(" WITH LIVE CHAT"));
     lcd.setCursor(0, 1);
   lcd.print(F("    SUPPORT"));
   o=0;}
if(o1>=25){
  lcd.clear();
      lcd.setCursor(0, 0);
 lcd.print(F("    Call/Text"));
     lcd.setCursor(0, 1);
    lcd.print(F("   0929------- "));
   o=0;}
if(o1>=30){
  lcd.clear();
      lcd.setCursor(0, 0);
        lcd.print(F(" P5/1hr P35/day "));
     lcd.setCursor(0, 1);
   lcd.print(F("________________"));
   o=0;}
if(o1>=35){
   o1=0;
}}}}}
