#include <BluetoothSerial.h>

#define pin 2

#define pA 34

String nombretarjeta = "Dafne y Luis 19", lecaux= " ";

int cont = 0; 

const float vmax =100 , vmin=0 , posmax=4095 , posmin=0; 

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT; 


void setup() {
  // put your setup code here, to run once:
Serial.begin (9600); 
SerialBT.begin (nombretarjeta);   
pinMode (pin, OUTPUT);

}

void loop() {
  int lecPot = 0; 
  Serial.println (lecPot);
  Serial.println (valorpotenciometro (lecPot));
  delay (3000);  
 
  int lectura = 0; 
  if (SerialBT.available ()){
  lectura = leerBT();
  lectura.trim (); 
    Serial.println (lectura); 
  }

  else {
  }

  if (lectura >= 60){
    digitalWrite (pin,1); 
  }

  else if (lectura <= 60){
    digitalWrite (pin,0); 
  }

  else {
    Serial.println ("Valor no valido"); 
  }
  
}


String leerBT () {
  lecaux = " "; 
 char a = SerialBT.read();
 lecaux = lecaux + a; 
  while (SerialBT. available ()){
    a = SerialBT.read();
 lecaux = lecaux + a;     
  }
return lecaux; 
}

/*
float valorpotenciometro (int x) {
float m = (vmax-vmin) / (posmax-posmin);
float b = vmax -m*posmax; 
float y = m*x+b; 
return y;  
}
*/
