
### 📄 `connect-esp8266-to-wifi.md`

````markdown
# 🌐 Connect ESP8266 to Wi-Fi and Display IP

## ✅ Task Summary
This task involves connecting an ESP8266 board to a Wi-Fi network and displaying its assigned local IP address via the serial monitor. The IP is essential for further network communication, especially in IoT or robotics projects like **Curiosity Bot v2**.

---

## 🔧 Setup

- **Board:** ESP8266 (NodeMCU)
- **Library:** `ESP8266WiFi.h`
- **IDE:** Arduino IDE / PlatformIO
- **Milestone:** [Neck Movement](../../milestone/1)
- **Status:** ✅ Completed

---

## 🧪 Code Used

```cpp
#include <ESP8266WiFi.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.print("Connected! IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing here for now
}
````

---

## 📟 Serial Monitor Output

```plaintext
Connecting to WiFi...
Connecting to WiFi...
Connecting to WiFi...
Connected! IP: 192.168.1.184
```

---

## 📁 Repository Links

* Issue: [`#5`](../../issues/5) - Connect ESP8266 to Wi-Fi and Print IP Address
* Project: Curiosity Bot v2
* Author: `@hsbofficial`

---