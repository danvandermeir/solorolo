This is a loose schematic for the current headlight and underglow iteration I have chosen. Prper update coming soon.

Conceptually the schematic isn't terribly complex.
```
Charge Port > Battery
                v
          Anti Spark Switch > VESC > Hub Motor
                v              v v
 v----< Constant Voltage PSU   | >   Resistor Network
 |              v              |            v
 |      Constant Current PSU   |     Pressure Sensitive Resistors
 |              v              v
 |        Transistor Pair   <  Arduino Nano
 |              v              v
 |    "Custom" LED Headlights  v
 |                             v
 >---------------------------->WS2812B LED strips (bumper1, bumper2, ground)
```
Eventually I will add more variants.
