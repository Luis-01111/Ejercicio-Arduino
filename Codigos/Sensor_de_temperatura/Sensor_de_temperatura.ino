#include <HTTPClient.h>
#include <WiFi.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 23
#define DHTTYPE DHT22

float h=0.0, t=0.0, f=0.0; 

//cREDENCIALES DE ACCESO A WIFI
const char* ssid = "Redmi Note 13";
const char* cont = "Cat-sup131004";

DHT dht (DHTPIN, DHTTYPE); 

TaskHandle_t Task1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600); 
  crearTareas ();
  dht.begin (); 
  conexionWifi (); 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print ("La humedad relativa es: "); 
  Serial.println (h);
  Serial.print ("La temperatura relativa en C es: "); 
  Serial.println (t);
  Serial.print ("La temperatura relativa en F es: "); 
  Serial.println (f);
  vTaskDelay (pdMS_TO_TICKS (2000) );
}

void leerSensor (void * parameter){
 for (;;) {
  delay (2000); 
  h = dht.readHumidity (); 
  t = dht.readTemperature ();
  f = dht.readTemperature (true); 
 }
}

void crearTareas () {
  // put your setup code here, to run once:
  xTaskCreatePinnedToCore (
    leerSensor,  //Funcion que implementa la tarea
    "Task1", // Nombre de la tarea 
    1000, //Tamaño de bytes en memoria (pila de memoria) 
    NULL, //Parametros de entrada de la funcion 
    0, // Prioridad de la tarea en el programa 
    &Task1, //Puntero en memoria 
    0); // Nucleo en el que se ejecuta la tarea  
}

void conexionWifi () {
  Serial.println ( "Wifi Desconectado"); 
  while (WiFi.status() != WL_CONNECTED){
    WiFi.begin (ssid,cont); 
    Serial.print (".");
    delay (500);
    
  }
  Serial.println (":");
}
