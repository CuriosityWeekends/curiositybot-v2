# 🤖 Face-Tracking Neck Movement – ESP8266 + MG996R Servo

This pull request contributes to the **Neck Movement** milestone by implementing the hardware setup and control logic for rotating a servo motor (MG996R) based on face position tracked via a USB webcam.

## 📌 What's Included

- ✅ Connected **MG996R servo** to **ESP8266 NodeMCU** using external power.
- ✅ Verified power draw and functionality using a multimeter.
- ✅ Shared GND between external supply and ESP (safe and stable).
- ✅ Set up basic servo sweep test via Arduino to confirm wiring.
- ✅ Cleaned up wiring diagram and commented code.
- ✅ Linked this work to Milestone: **"Neck Movement"**, Issue: `#3`.

## 💡 Next Steps

- Integrate OpenCV Python script for face tracking.
- Map face X-coordinate to angle (e.g., 0–180°).
- Send HTTP request to ESP8266 with servo angle.
- Toggle system on/off via a keyboard hotkey.

## 🛠️ Hardware Used

- MG996R Servo Motor  
- ESP8266 NodeMCU  
- External 5V/2A Power Supply  
- Logitech USB Webcam  

## 🔗 Related Issues

- Closes #3  
- Part of Milestone: [Neck Movement](../../milestone/1)

---

PR created by `@hsbofficial` for [Curiosity Bot v2](https://github.com/hsbofficial/Curiosity-Bot-v2)

