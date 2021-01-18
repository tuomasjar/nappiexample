#define nappula 5  //nappipinni
#define maxViive 1000 //maksimiviive viimeisen painalluksen jälkeen
#define debounce 250  //debounceviive

double aika;
int laskuri;
void setup() {
  pinMode(nappula, INPUT_PULLUP); //Käytä ylösvetovastusta kytke pinnistä napin kautta maahan
  aika=millis();
  laskuri=0; //nollaa laskuri
}

void loop() {
  bool nappi = !(digitalRead(nappula)); //Päinvastoin koska input_pullup
  if(nappi && millis()-aika>debounce){ //250 millisekunnin debounce
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
