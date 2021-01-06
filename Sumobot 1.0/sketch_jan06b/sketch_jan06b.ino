int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

const int ProxSensor=A0;
int inputVal = 0;

#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);//direction

  pinMode(6, OUTPUT); //speed
  pinMode(7, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(13,OUTPUT);//LED
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
}

void loop() {
  // put your main code here, to run repeatedly:   
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(6, 255); //ENA pin
  analogWrite(7, 255); //ENB pin

  //Ultrasonic sensor:
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Read the IR sensor value
  inputVal = analogRead(ProxSensor);
  Serial.println("IR:");
  Serial.println(inputVal);

  if(inputVal<=100){
  digitalWrite(motor1pin1, LOW);//hit the edge and go backward
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);  
  }
  else{
    digitalWrite(motor1pin1, HIGH);//spin
    digitalWrite(motor1pin2, LOW);
  
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    //if detected go forward for 5 sec
    while(distance<=100){
    digitalWrite(motor1pin1, HIGH);//forward
    digitalWrite(motor1pin2, LOW);
  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    }
  }
  





}
