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
  
}

void loop() {


  display.drawRect(10, 7, 100, 25, WHITE); //Rectangle commençant un point (10,7), large de 100 pixel et haut de 25 pixel
  display.display();//Envoyer le contenue de la RAM dans l'écran
  delay(2000);
  display.clearDisplay();//on efface la RAM afin de placer la prochaine forme
  

  
  display.fillRoundRect(10, 7, 100, 25, 8, WHITE);//Rectange au coin arrondie et remplie
  display.display();                              //Comme à (10,7), 100 pixel de large et 25 de haut
  delay(2000);                                    //Les coins ont un rayon de 8 pixel
  display.clearDisplay();

  
  display.drawCircle(64, 16, 10, WHITE); //Cercle de rayon 10 pixels, centre à (64,16)
  display.display();
  delay(2000);
  display.clearDisplay();
  
  
}