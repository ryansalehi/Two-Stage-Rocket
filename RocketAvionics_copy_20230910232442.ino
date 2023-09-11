// Ryan Salehi
// Rocket Avionics
// July 31, 2023

//Declare variables
const int redPin=6,greenPin=8,bluePin=9; //RGB LED
const int relay1=4, relay2=5;
const int switchpin=10;
int switchvalue;
int count=0;

void setup() {
  //Relay and switch pins
  pinMode(relay1,OUTPUT);
  digitalWrite(relay1,LOW);//turn relay OFF
  pinMode(relay2,OUTPUT);
  digitalWrite(relay2,LOW);//turn relay OFF
  pinMode(switchpin,INPUT); 

  //RGB LED Outputs
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  delay(500);
  setLED(0,255,0);//set to green to signify ready for launch
}

void loop() {

  switchvalue = digitalRead(switchpin);
  if(switchvalue == HIGH && count<1){
    startLaunch();
  }

}

//helper function used to set the color of the LED
void setLED(int red,int green,int blue){
  analogWrite(redPin,red);
  analogWrite(greenPin,green);
  analogWrite(bluePin,blue);
}

//helper function that starts the launch sequence when called
void startLaunch(){
    //blink LED in blue to signify sequence has started
    setTimer(10,1000);

    //Ignite rocket engine 1
    setLED(255,0,0);//set to red to signify ignition started
    digitalWrite(relay2,HIGH);
    delay(3500);//Wait until the first engine is done
    digitalWrite(relay2,LOW);

    //Ignite rocket engine 2
    digitalWrite(relay1,HIGH);
    delay(5000);
    digitalWrite(relay1,LOW);

    count++;
}

//helper function that makes the LED blink for a certain time
void setTimer(int blinks, int timeBetweenBlinks){
  for (int i=0;i<blinks;i++){
    setLED(0,0,255);
    delay(timeBetweenBlinks/2);
    setLED(0,0,0);
    delay(timeBetweenBlinks/2);
  }
}