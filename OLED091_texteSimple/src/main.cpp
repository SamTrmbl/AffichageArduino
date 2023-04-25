//Inspiration : https://lastminuteengineers.com/oled-display-arduino-tutorial/
//Il faut suivre les consignes pour un écran I2C

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>//SSD1306 c'est la puce qui gère les écrans OLED

// Pour le modèle 0.91', la résolution est de 128 x 32
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

 // Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {


  Serial.begin(9600);
  
    // Permet de valider que l'écran est bien initialiser
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }


  // Clear the buffer
  display.clearDisplay();



  display.setTextSize(1); //Choisir la taille du texte

  
}

void loop() {

    display.setCursor(0,15); //Choisir le point de départ à écrire
    display.setTextColor(WHITE); //Choisir la couleur blanc
    display.print("Hello World !"); //Inscrire le texte dans la RAM de la chip
    display.display(); //Envoyer l'information de la RAM dans la chip
  
    delay(1000); //Attendre une seconde

    display.clearDisplay(); //Vider le contenue de la RAM

    display.setCursor(0,15); //Choisir le point de départ à écrire
    display.setTextColor(BLACK,WHITE);//Choisir noir avec fond blanc
    display.print("Hello World !");//Inscrire le texte dans la RAM de la chip
    display.display();//on envoit l'image à l'écran.

    delay(1000); //Attendre une seconde

    display.clearDisplay(); //Vider le contenue de la RAM
  
  
}