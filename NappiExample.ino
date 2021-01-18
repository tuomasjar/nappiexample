#define nappula 5
#define maxViive 1000

double aika;
int laskuri=0;
void setup() {
  pinMode(nappula, INPUT_PULLUP);
  aika=millis();
}

void loop() {
  bool nappi = !(digitalRead(nappula)); //Päinvasrtoin koska input_pullup
  if(nappi && millis()-aika>250){ //250 millisekunnin debounce
    laskuri++;
    aika=millis();
  }
  if(millis()-aika>maxViive && laskuri){ //viimeisen painalluksen jälkeen maxViiveen verran millisekunteja
    switch(laskuri){
      case 1:
        //nappia painettu kerran
        break;
      case 2: 
        //nappia painettu kahdesti
        break;
      case 3:
        //nappia painettu kolmesti
        break;
      default:
        //Jotain muuta
    }
    aika = millis();
    laskuri = 0;
    
  }
}
