#define RED_PIN 8
#define YELLOW_PIN 10
#define GREEN_PIN 12

int red_on = 3000;
int red_yellow_on = 1000; 
int green_on = 3000;
int green_blink = 500;
int yellow_on = 1000;

int delay_timer(int milliseconds)
{
int count = 0;
while(1)
{
  if(TCNT0 >= 16) 
  {
    TCNT0=0;
    count++;
  if (count == milliseconds)
  {
    count=0;
    break; 
    }
  }
}
return 0;
}
void setup() {
  // put your setup code here, to run once:
pinMode(RED_PIN, OUTPUT);
pinMode(YELLOW_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);

TCCR0A = 0b00000000;
TCCR0B = 0b00000101;
TCNT0=0;
}

void loop() {
  digitalWrite(RED_PIN, HIGH);
  delay_timer(red_on);

  digitalWrite(YELLOW_PIN, HIGH);
  delay_timer(red_yellow_on);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay_timer(green_on);
  digitalWrite(GREEN_PIN, LOW);

for(int i = 0; i < 3; i = i+1)
{
  delay_timer(green_blink);
  digitalWrite(GREEN_PIN, HIGH);
  delay_timer(green_blink);
  digitalWrite(GREEN_PIN, LOW);
}

  digitalWrite(YELLOW_PIN, HIGH);
  delay_timer(yellow_on);
  digitalWrite(YELLOW_PIN, LOW);
}
