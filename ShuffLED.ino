#include <FastLED.h>
/*

*/
#define NUMLED 12
#define DATA_PIN 3
CRGB leds[NUMLED];
int indexArray[NUMLED];

void setup() {
  //remplir le tableau avec nombres de 0 à NUMLED
  for(int i=0;i<NUMLED;i++) indexArray[i]=i;
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUMLED); 
}

void shuffle(int shufArray[], int arrLength, int numPass) {
  /* 
    shufArray : c'est le tableau à mélanger
    arrLength : le nombre d'élément dans le tableau
    numPass   : le nombre de passes (combien de fois on coupe)
  //*/
  //Initialisation module random
  randomSeed(analogRead(A0));
  
  for(int i=0; i<numPass; i++) { 
   int n = random(0, arrLength);  // on prend un nb aleatoire entre 0 et NUMLED
   int temp = shufArray[n];  // on sauve la valeur d'une case prise au hasard (n) dans temp
   shufArray[n] =  shufArray[i%arrLength]; // on remplace la valeur de la case n par la valeur de la case i
   shufArray[i%arrLength] = temp;  // on remet la valeur initiale de n dans i
   /*
      j'ai appliqué un modulo du nombre d'élément du tableau sur i,
      de telle sorte qu'on puisse faire plus de passes qu'il d'élément dans le tableau.
      En ce cas le mélange repart de la première case du tableau.
   //*/
  }
}

void loop() {
    FastLED.clear(); 
    FastLED.setBrightness(128);
    //on commence par mélanger le tableau / cartes / whatever
    shuffle(indexArray, NUMLED, 60);
    //on affiche le tableau (qui contient maintenant les élément dans le desordre)
    for(int i=0 ; i<NUMLED ; i++) {
      /*
        là on peux bloquer la boucle avec un "while bouton not pressed, ne rien faire"
        une fois le bouton pressé on diminue l'intensité de toutes les LEDS
        puis ensuite seulement on allume la led dont le numéro est noté dans la case i
        (ici pour la simulation on affiche le num de la led qui s'allumerait)
      */
      while (Serial.available() == 0) {};
      while (Serial.available() > 0) Serial.read();
      leds[indexArray[i]] = CRGB::Red;
      FastLED.show();
      Serial.println(indexArray[i]); 
    }
    
    Serial.println("Tout le tableau a été affiché! Appuyer sur entrée pour relancer la séquence");
    while (Serial.available() == 0) {};
    while (Serial.available() > 0) Serial.read();
    FastLED.setBrightness(128);
    for( int i = 127; i >= 0 ; i-- ) {
      FastLED.setBrightness(i);
      FastLED.show();
      delay(50);
    }
    /*
      ici (simu) on attend une entrée sur le port série pour réinitialiser la séquence.
      Sinon c'est là qu'on mettrai une boucle for qui passerai par toutes les LEDS pour fade out.
    */
}

