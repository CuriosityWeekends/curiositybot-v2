

### 📄 `http-servo-endpoint.md`

````markdown
# 🔧 HTTP Servo Control Endpoint

## ✅ Task Summary
Implement a lightweight HTTP server on the ESP8266 that listens for GET requests to the `/servo` endpoint. The goal is to control a servo motor based on a query parameter (`angle=xxx`), enabling remote hardware interaction over Wi-Fi.

---

## 🔌 Requirements

- **Board:** ESP8266 (NodeMCU)
- **Servo Control Library:** `Servo.h`
- **Wi-Fi Library:** `ESP8266WiFi.h`, `ESP8266WebServer.h`
- **Endpoint:** `/servo?angle=90`
- **Method:** GET
- **Accepted Range:** 0–180°

---

## 🧪 Sample Code

```cpp
#include <ESP8266WiFi.h>
#include <Servo.h>
#include <ESP8266WebServer.h>

const char* ssid = "Curiosity Weefi";
const char* password = "12345678910";

// Set static IP address
IPAddress local_IP(192, 168, 1, 184); // change this to your desired IP
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional

ESP8266WebServer server(80);
Servo neckServo;

void handleServo() {
  if (server.hasArg("angle")) {
    int angle = server.arg("angle").toInt();
    angle = constrain(angle, 0, 180);
    neckServo.write(angle);
    Serial.println("Moving to angle: " + String(angle));
    server.send(200, "text/plain", "Moved to angle " + String(angle));
  } else {
    server.send(400, "text/plain", "Missing angle param");
  }
}

void setup() {
  Serial.begin(115200);
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
  Serial.println("STA Failed to configure");
  }
  
  WiFi.begin(ssid, password);
  neckServo.attach(D5);  // You can change the pin if needed

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  
  }

  Serial.println("Connected! IP: " + WiFi.localIP().toString());

  server.on("/servo", handleServo);
  server.begin();
}

void loop() {
  server.handleClient();
}

````

---

## 🌐 How to Use

After uploading the code:

1. Connect ESP8266 to Wi-Fi.
2. Open browser or use tools like Postman/cURL:

   ```
   http://<YOUR_ESP_IP>/servo?angle=45
   ```
3. Servo will rotate to 45°.

---

## 🧾 Example Response

```
HTTP 200 OK
Body: Servo moved to angle: 45
```

Or if angle is missing:

```
HTTP 400 Bad Request
Body: Missing 'angle' parameter
```

---

## 📂 Issue Reference

* Task: [`[#6](https://chatgpt.com/issues/6)`](../../issues/6) - Create HTTP server endpoint `/servo?angle=xxx`
* Project: Curiosity Bot v2
* Milestone: Neck Movement
* Status: 🟢 In Progress
* Author: `@hsbofficial`

---

## 🔮 Future Scope

* Add authentication or token validation
* Extend to support multiple servos
* Integrate with Blynk or custom dashboard for UI-based control

```

---

Let me know if you want this bundled into a ZIP, directly turned into a downloadable `.md` file, or merged with your previous Wi-Fi connection doc.
```
