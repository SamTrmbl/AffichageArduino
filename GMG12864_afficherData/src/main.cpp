#include <Arduino.h>
#include <U8g2lib.h>

//Créer l'écran en spécifiant les bonnes connexions
U8G2_ST7565_ERC12864_ALT_F_4W_SW_SPI u8g2(U8G2_R0, /*SCL*/ 13, /*SI*/ 11, /*CS*/ 10, /*RS*/ 9, /*RES*/ 8);

int counter = 0;

void setup() {
    u8g2.begin();
    u8g2.setContrast(100); //valeur entre 0 et 255
    u8g2.enableUTF8Print(); //Permet d'afficher des accents

  
}

void loop() {
    u8g2.clearBuffer();					//Vider la mémoire interne

    u8g2.setFont(u8g2_font_helvB12_tf); //Police Helvetica Bold 12 
    u8g2.setCursor(0,20);               //On va écrire à partir du pixel 5,20
    u8g2.print("Valeur affichée");     //Écrire le texte

    u8g2.setFont(u8g2_font_timR24_tf);  //Police Times New Roman Régulier 24
    u8g2.setCursor(56, 50);             //Déplacer le curseur
    u8g2.print(counter);                //Affiche la valeur d'une variable. Ça pourrait être le signal d'un capteur !
    
    u8g2.sendBuffer();					//On envoit la mémoire interne à l'écran pour affichage
    
    counter ++;                         //Incrémente la valeur à afficher
   
    delay(1000); 


    
}