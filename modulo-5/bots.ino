//globales de pines
short ledTest = 13;
short ledVerde = 7;
short ledAmarillo = 8;
short ledRojo = 9;
short entradaLDR = 2;


//variables
float lecturaLDR;

//constantes
short delayS = 200;
short delayM = 500;
short delayL = 1000;

float limiteAlto = 200.0;
float limiteBajo = 600.0;

void setup() {
  //pines de los leds:
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledTest, OUTPUT);
  
  Serial.begin(9600);
  
  //variables a inicializar
  lecturaLDR = 0.0;

  parpadear(ledTest, 3, delayS);
}

void loop() {
  lecturaLDR = analogRead(entradaLDR);
  Serial.println(lecturaLDR);
  //inserten su código a continuación
  //el sensor oscila entre 1023 (oscuridad total) y 0 (luz directa)
  if (lecturaLDR>limiteBajo){
    parpadear(ledRojo, 1, delayS);
  }else if (lecturaLDR<=limiteBajo && lecturaLDR>limiteAlto){
    parpadear(ledAmarillo, 1, delayM);
  }else if (lecturaLDR<limiteAlto){
    parpadear(ledVerde, 1, delayL);
  }
}

//comandos de leds
void parpadear(short pin, short times, short espera){
  for(int i = 0; i < times ; i++){
    digitalWrite(pin, HIGH);
    delay(espera);
    digitalWrite(pin, LOW);
    delay(espera);
  }
}
