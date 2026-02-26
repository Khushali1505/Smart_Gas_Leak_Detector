#define BLYNK_TEMPLATE_ID "TMPL3ZaFsLJLK"
#define BLYNK_TEMPLATE_NAME "Smart Gas Detector"
#define BLYNK_AUTH_TOKEN "RwEc8jQCBig2xLUucotubLZAgOqYqtpM"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define MQ2_ANALOG 4
#define RED_PIN 12
#define GREEN_PIN 13
#define BLUE_PIN 14
#define BUZZER_PIN 5

char ssid[] = "Vivo Y200";
char pass[] = "ritu2005";

int analogValue = 0;
int baseline = 0;
int threshold = 0;
bool gasNotified = false;  

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(MQ2_ANALOG, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("\nConnecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  Serial.println(WiFi.localIP());

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connected to Blynk!");

  Serial.println("\n💨 MQ-2 Gas Sensor Self-Calibration Mode");
  Serial.println("-------------------------------------------");
  Serial.println("Keep the area clean (no smoke/gas) for 5 seconds...");
  delay(5000);

  long sum = 0;
  for (int i = 0; i < 50; i++) {
    sum += analogRead(MQ2_ANALOG);
    delay(50);
  }
  baseline = sum / 50;
  threshold = baseline + 200;

  Serial.print("Initial Baseline: ");
  Serial.println(baseline);
  Serial.println("System ready!");
  Serial.println("-------------------------------------------");
}

void loop() {
  Blynk.run();  // keeps Blynk connection alive

  analogValue = analogRead(MQ2_ANALOG);

  static unsigned long lastAdjust = 0;
  if (millis() - lastAdjust > 5000 && analogValue < (baseline + 50)) {
    baseline = (baseline * 9 + analogValue) / 10;
    threshold = baseline + 200;
    lastAdjust = millis();
  }

  bool gasDetected = analogValue > threshold;
  bool warningLevel = analogValue > (baseline + (threshold - baseline) / 2) && analogValue <= threshold;

  if (gasDetected) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    Serial.print("⚠️ Gas Detected! 🚨  ");

    if (!gasNotified) {
      Blynk.logEvent("gas_alert", "⚠️ Gas Leak Detected! Please Check Immediately!");
      gasNotified = true;
    }
  }
  else if (warningLevel) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    Serial.print("⚠️ Gas Warning!  ");
    gasNotified = false;
  }
  else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.print("✅ Air Safe  ");
    gasNotified = false;
  }

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" | Baseline: ");
  Serial.print(baseline);
  Serial.print(" | Threshold: ");
  Serial.println(threshold);

  Blynk.virtualWrite(V0, analogValue);  // Send sensor value to Blynk
  Blynk.virtualWrite(V2, threshold);  // Display threshold value

  if (gasDetected) {
    Blynk.virtualWrite(V1, "🚨 Danger: Gas Leak Detected!");
  }
  else if (warningLevel) {
    Blynk.virtualWrite(V1, "⚠️ Warning: Gas Level Rising");
  }
  else {
    Blynk.virtualWrite(V1, "✅ Air Safe");
  }

  delay(3000);  // safe delay - doesn’t affect Blynk too much
}
