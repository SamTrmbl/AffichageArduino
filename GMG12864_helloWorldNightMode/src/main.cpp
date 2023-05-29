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

    u8g2.setFont(u8g2_font_ncenB08_tr);	//Choisir une police, voir le wiki pour les choix

    u8g2.setCursor(5,32);               //Placer le curseur au pixel 5,32 (Sur un total de 128x64)
    u8g2.print("Hello World!");     	//On met le texte dans la mémoire interne
    
    u8g2.sendBuffer();					//On envoit la mémoire interne à l'écran pour affichage
    delay(1000);  


    
}