#include <Servo.h>

Servo esc;

// Ultrasonic sensor pins
const int trigPin1 = 2;
const int echoPin1 = 3;   // Front

const int trigPin2 = 4;
const int echoPin2 = 5;   // Right

const int trigPin3 = 6;
const int echoPin3 = 7;   // Left

const int irPin = 8;

// Motor driver pins
const int IN1 = 9;
const int IN2 = 10;
const int IN3 = 11;
const int IN4 = 12;

long duration1, duration2, duration3;
int distanceFront, distanceRight, distanceLeft;

void setup()
{
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);

    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);

    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);

    pinMode(irPin, INPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    Serial.begin(9600);

    esc.attach(13);
    esc.writeMicroseconds(1000);
    delay(2000);
}

void forward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void left()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void right()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void stopMotor()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop()
{
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);

    duration1 = pulseIn(echoPin1, HIGH);
    distanceFront = duration1 * 0.034 / 2;

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);

    duration2 = pulseIn(echoPin2, HIGH);
    distanceRight = duration2 * 0.034 / 2;

    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);

    duration3 = pulseIn(echoPin3, HIGH);
    distanceLeft = duration3 * 0.034 / 2;

    Serial.print("F: ");
    Serial.print(distanceFront);
    Serial.print(" R: ");
    Serial.print(distanceRight);
    Serial.print(" L: ");
    Serial.println(distanceLeft);

    if (distanceFront > 15)
    {
        forward();
    }
    else
    {
        stopMotor();
        delay(200);

        if (distanceLeft > distanceRight)
        {
            right();
            delay(400);
        }
        else
        {
            left();
            delay(400);
        }
    }

    delay(100);
}
