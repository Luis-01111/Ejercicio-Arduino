

#define pin 2


void setup() {
  // put your setup code here, to run once:
pinMode (pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (pin,1);
  delay (2000);
  digitalWrite (pin,0);
  delay (2000); 

}
