# USB HID Controlled LED System (Archive)

**Stack:** C • Embedded Systems (USB Host HID)  

**What it is:**  
Firmware that connects a USB mouse/keyboard to an embedded board and maps user actions to LED outputs:  
- Mouse movement controls LED positions.  
- Mouse button clicks change LED colors (red, purple, green, or cycle).  
- Keyboard inputs toggle indicator LEDs.  

**What I learned:**  
- Parsing USB HID reports (`USBH_HID_GetMouseInfo`).  
- Managing multiple USB pipes and host/device states.  
- Integrating hardware input with LED feedback loops.  
- Debugging embedded USB host stacks.  

**Why it matters (PM lens):**  
Shows how low-level USB drivers translate into interactive user experiences. Demonstrates tradeoffs between protocol complexity and real-time responsiveness.
