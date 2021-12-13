#define EN 10
#define IN1 9
#define IN2 8

int motor_speed = 0;
int pedal = A0;

void setup()
{
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2
  pinMode(EN, OUTPUT); // motor PWM pin
  pinMode(pedal,INPUT); // potentiometer pin
  
  Serial.begin(9600); 
}

void loop()
{
  int pedalValue = analogRead(pedal);
  delay(1000);
  
  
  motor_speed = map(pedalValue, 0, 1024, 0, 255);
 
  Serial.print("RPM: ");
  Serial.println(motor_speed);
  
  if(motor_speed >= 0 && motor_speed <= 255)
       {
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       analogWrite(EN,motor_speed);
       }
}
