# 🧪 Servo Sweep Test – MG996R + ESP8266

## ✅ Task Completed
Successfully tested the **basic servo sweep** functionality using the MG996R servo motor connected to the **ESP8266 NodeMCU**.

## 🧰 Setup Details

- **Microcontroller:** ESP8266 (NodeMCU)
- **Servo Motor:** MG996R
- **Power Source:** External 5V/2A supply
- **Shared GND:** Between ESP and external power
- **Tested Pin:** D4 (GPIO2) for signal output

## 🧪 What Was Done

- Uploaded the standard Arduino **servo sweep example**.
- Verified range of motion from **0° to 180°**.
- Confirmed smooth and responsive movement.
- Monitored **serial output** to ensure signal was correctly received and executed.
- Used multimeter to confirm power draw remained within safe range.

## 🛡️ Notes

- MG996R draws significant current; must avoid powering directly from ESP.
- Ensure servo GND and ESP GND are **tied together** for reference voltage.
- Added appropriate **delay()** in loop to avoid servo jitter.

## 🗂️ Linked To

- Issue: `#4` Test Basic Servo Sweep Code
- Milestone: [Neck Movement](../../milestone/1)

---

Test conducted by `@hsbofficial` as part of the **Curiosity Bot v2** project.
