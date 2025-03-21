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
  int lecPot = analogRead (pA);
  Serial.println (lecPot);
  Serial.println (calcularValor (lecPot));
  delay (2000); 

  if (lecPot >= 60) {
  digitalWrite (pin,1); 
}

else {
 digitalWrite (pin,0);
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

float calcularValor (int x) {
float m = (vmax-vmin) / (posmax-posmin);
float b = vmax -m*posmax; 
float y = m*x+b; 
return y;  


}
