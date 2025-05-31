#include <ESP8266WiFi.h>
#include <Servo.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Curiosity Weefi";
const char* password = "12345678910";

// MQTT broker details
const char* mqtt_server = "192.168.68.130"; 
const int mqtt_port = 1883;
const char* mqtt_topic = "cw/humanoid";

// Servo object
Servo neckServo;

// WiFi & MQTT objects
WiFiClient espClient;
PubSubClient client(espClient);

// WiFi connection function
void setup_wifi() {
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// MQTT message handler
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  int angle = message.toInt();
  angle = constrain(angle, 0, 180);  // Just in case

  Serial.print("Received angle: ");
  Serial.println(angle);

  neckServo.write(angle);
}

// MQTT reconnect logic
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected!");
      client.subscribe(mqtt_topic);
      Serial.print("Subscribed to topic: ");
      Serial.println(mqtt_topic);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(". Trying again in 5 seconds.");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  neckServo.attach(D5); // You can change to your servo pin
  neckServo.write(90);  // Default center position
  Serial.println("Setup complete.");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
