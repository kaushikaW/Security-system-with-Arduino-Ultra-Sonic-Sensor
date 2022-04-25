#define trig 2
#define echo 4
#define buzzer 7
#define led 5

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

void loop()
{

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long t = pulseIn(echo, HIGH);

    long inch = t / 74 / 2; // Ultrasonic distance in inches
    long cm = t / 29 / 2;   // Ultrasonic distance in inches

    long safeDistance = cm; // Safe distance

    // go to the serial monitor to see the distance result

    Serial.print(inch);
    Serial.print("in \t ");
    Serial.print(cm);
    Serial.println("cm");

    // Condition to start security alerts

    if (safeDistance > 0 && safeDistance < 12)
    {
        digitalWrite(led, HIGH);

        // Alert sound pattern
        for (int i = 0; i < 50; i++)
        {
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(10);
        }
    }
    else
    // LED Blink
    {
        digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
    }
}
