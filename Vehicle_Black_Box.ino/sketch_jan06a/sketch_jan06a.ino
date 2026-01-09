#include <Wire.h>
#include <MPU6050.h>
#include <TinyGPSPlus.h>
#include <SD.h>
#include <SPI.h>

#define SD_CS 5
#define BUZZER_PIN 18
#define CRASH_THRESHOLD 2.5

MPU6050 mpu;
TinyGPSPlus gps;

HardwareSerial gpsSerial(2); // UART2

File logFile;

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin(21, 22);

  // MPU6050 Init
  Serial.println("Initializing MPU6050...");
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection FAILED");
    while (1);
  }
  Serial.println("MPU6050 connected");

  // SD Card Init
  Serial.println("Initializing SD Card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card FAILED");
    while (1);
  }
  Serial.println("SD Card Ready");

  logFile = SD.open("/vehicle_log.csv", FILE_APPEND);
  if (logFile.size() == 0) {
    logFile.println("Lat,Lng,Ax,Ay,Az,Event");
  }
  logFile.close();

  Serial.println("System Ready");
}

void loop() {
  // Read GPS
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  float latitude = 0.0;
  float longitude = 0.0;

  if (gps.location.isValid()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
  }

  // Read MPU6050
  int16_t axRaw, ayRaw, azRaw;
  mpu.getAcceleration(&axRaw, &ayRaw, &azRaw);

  float ax = axRaw / 16384.0;
  float ay = ayRaw / 16384.0;
  float az = azRaw / 16384.0;

  float totalAccel = sqrt(ax * ax + ay * ay + az * az);

  bool crashDetected = totalAccel > CRASH_THRESHOLD;

  // Log Data
  logFile = SD.open("/vehicle_log.csv", FILE_APPEND);
  if (logFile) {
    logFile.print(latitude, 6);
    logFile.print(",");
    logFile.print(longitude, 6);
    logFile.print(",");
    logFile.print(ax);
    logFile.print(",");
    logFile.print(ay);
    logFile.print(",");
    logFile.print(az);
    logFile.print(",");
    logFile.println(crashDetected ? "CRASH" : "NORMAL");
    logFile.close();
  }

  // Crash Alert
  if (crashDetected) {
    Serial.println("🚨 ACCIDENT DETECTED!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2000);
    digitalWrite(BUZZER_PIN, LOW);

    // GSM code can be added here later
  }

  Serial.print("Lat: "); Serial.print(latitude, 6);
  Serial.print(" Lng: "); Serial.print(longitude, 6);
  Serial.print(" Accel: "); Serial.println(totalAccel);

  delay(1000);
}
