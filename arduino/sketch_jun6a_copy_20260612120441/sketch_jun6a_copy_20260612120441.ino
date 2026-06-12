/*
 * ═══════════════════════════════════════════
 *   SMART HOME - 4 RELAY CONTROLLER
 *   Hardware : ESP8266 NodeMCU
 *   Database : Firebase Realtime DB
 *   Author   : Your Project
 * ═══════════════════════════════════════════
 */

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// ─── WiFi Credentials ────────────────────
#define WIFI_SSID      "YOUR_WIFI_SSID"      // ← blank
#define WIFI_PASSWORD  "YOUR_WIFI_PASSWORD"  // ← blank

// ─── Firebase Credentials ────────────────
#define FIREBASE_HOST  "YOUR_PROJECT.firebaseio.com" // ← blank
#define FIREBASE_AUTH  "YOUR_API_KEY"        // 

// ─── Relay Pins ──────────────────────────
#define RELAY_1  D1   // Socket 1
#define RELAY_2  D2   // Socket 2
#define RELAY_3  D5   // Socket 3
#define RELAY_4  D6   // Socket 4

// ─── Firebase Objects ────────────────────
FirebaseData    firebaseData;
FirebaseAuth    auth;
FirebaseConfig  config;

// ─── Variables ───────────────────────────
int relay1State = 0;
int relay2State = 0;
int relay3State = 0;
int relay4State = 0;

// ─────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  Serial.println("\n\n");
  Serial.println("==============================");
  Serial.println("   Smart Home Starting...     ");
  Serial.println("==============================");

  // Setup relay pins
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  // All relays OFF at start
  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, LOW);
  digitalWrite(RELAY_3, LOW);
  digitalWrite(RELAY_4, LOW);
  Serial.println("All Relays → OFF");

  // Connect to WiFi
  Serial.println("------------------------------");
  Serial.print("Connecting to WiFi: ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  int wifiAttempts = 0;

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    wifiAttempts++;
    if (wifiAttempts > 30) {
      Serial.println("\nWiFi Failed! Restarting...");
      ESP.restart(); // auto restart if wifi fails
    }
  }

  Serial.println("\nWiFi Connected ✓");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Connect to Firebase
  Serial.println("------------------------------");
  Serial.println("Connecting to Firebase...");

  config.host                          = FIREBASE_HOST;
  config.signer.tokens.legacy_token    = FIREBASE_AUTH;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Set initial values in Firebase
  Firebase.setInt(firebaseData, "/relay1", 0);
  Firebase.setInt(firebaseData, "/relay2", 0);
  Firebase.setInt(firebaseData, "/relay3", 0);
  Firebase.setInt(firebaseData, "/relay4", 0);

  Serial.println("Firebase Connected ✓");
  Serial.println("==============================");
  Serial.println("   System Ready!              ");
  Serial.println("==============================\n");
}

// ─────────────────────────────────────────
void loop() {

  // Check WiFi — reconnect if dropped
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi Lost! Reconnecting...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(3000);
    return;
  }

  // ── Read Relay 1 ──────────────────────
  if (Firebase.getInt(firebaseData, "/relay1")) {
    int newState = firebaseData.intData();
    if (newState != relay1State) {
      relay1State = newState;
      digitalWrite(RELAY_1, relay1State == 1 ? HIGH : LOW);
      Serial.print("Relay 1 (Socket 1): ");
      Serial.println(relay1State == 1 ? "ON  ✓" : "OFF ✗");
    }
  } else {
    Serial.print("Relay1 Error: ");
    Serial.println(firebaseData.errorReason());
  }

  // ── Read Relay 2 ──────────────────────
  if (Firebase.getInt(firebaseData, "/relay2")) {
    int newState = firebaseData.intData();
    if (newState != relay2State) {
      relay2State = newState;
      digitalWrite(RELAY_2, relay2State == 1 ? HIGH : LOW);
      Serial.print("Relay 2 (Socket 2): ");
      Serial.println(relay2State == 1 ? "ON  ✓" : "OFF ✗");
    }
  } else {
    Serial.print("Relay2 Error: ");
    Serial.println(firebaseData.errorReason());
  }

  // ── Read Relay 3 ──────────────────────
  if (Firebase.getInt(firebaseData, "/relay3")) {
    int newState = firebaseData.intData();
    if (newState != relay3State) {
      relay3State = newState;
      digitalWrite(RELAY_3, relay3State == 1 ? HIGH : LOW);
      Serial.print("Relay 3 (Socket 3): ");
      Serial.println(relay3State == 1 ? "ON  ✓" : "OFF ✗");
    }
  } else {
    Serial.print("Relay3 Error: ");
    Serial.println(firebaseData.errorReason());
  }

  // ── Read Relay 4 ──────────────────────
  if (Firebase.getInt(firebaseData, "/relay4")) {
    int newState = firebaseData.intData();
    if (newState != relay4State) {
      relay4State = newState;
      digitalWrite(RELAY_4, relay4State == 1 ? HIGH : LOW);
      Serial.print("Relay 4 (Socket 4): ");
      Serial.println(relay4State == 1 ? "ON  ✓" : "OFF ✗");
    }
  } else {
    Serial.print("Relay4 Error: ");
    Serial.println(firebaseData.errorReason());
  }

  delay(500); // check every 0.5 seconds
}