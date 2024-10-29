int sensor = 35;
int sensorValue = 0;
volatile int rotationCount = 0; // Counts the rotations
bool lastState = LOW; // Keeps track of the last state
unsigned long lastTime = 0; // Time when the last rotation was detected
float circumference = 2 * PI * 0.215; // Circumference in meters (radius =
32cm)
void setup() {
Serial.begin(9600);
pinMode(sensor, INPUT);
lastTime = millis(); // Initialize lastTime with the current time
}
void loop() {
sensorValue = digitalRead(sensor);
if (sensorValue && !lastState) {
rotationCount++; // Increment rotation count
}
lastState = sensorValue;
unsigned long currentTime = millis();
float elapsedTime = (currentTime - lastTime) / 1000.0; // Elapsed time in
seconds
if (elapsedTime >= 5.0) { // Check every 5 seconds
float distance = rotationCount * circumference; // Total distance traveled in
meters
float velocity = distance / elapsedTime; // Velocity in m/s
Serial.print("Total Rotations: ");
Serial.println(rotationCount);
Serial.print("Average Wind Velocity: ");
Serial.print(velocity);
Serial.println(" m/s");
// Reset for the next period
rotationCount = 0;
lastTime = currentTime;
}
delay(1); // Short delay to reduce bouncing
}
