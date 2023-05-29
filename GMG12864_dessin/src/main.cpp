#include <Arduino.h>
#include <U8g2lib.h>

//Créer l'écran en spécifiant les bonnes connexions
U8G2_ST7565_ERC12864_ALT_F_4W_SW_SPI u8g2(U8G2_R0, /*SCL*/ 13, /*SI*/ 11, /*CS*/ 10, /*RS*/ 9, /*RES*/ 8);



void setup() {
    u8g2.begin();
    u8g2.setContrast(100); //valeur entre 0 et 255

  
}

void loop() {
    u8g2.clearBuffer();					// Vide la mémoire interne
    u8g2.setDrawColor(1);               //1 = foncé
    u8g2.drawBox(8,8,112,48);           //Dessine un rectangle qui commence au coin 8,8 et fait 112x48 pixels
    u8g2.setDrawColor(0);               //0 = blanc
    u8g2.drawCircle(44,32,10);          //Seulement le périmètre d'un rond centré à 44,32 et de 10 pixels de rayon
    u8g2.drawDisc(84,32,10);            //Un disque rempli centré à 84,32 et de 10 pixels de rayon
    u8g2.sendBuffer();					// on envoit la mémoire interne à l'écran pour affichage
    delay(1000);  


    
}