I will not be including a precompiled firmware to upload as there are user variables that can be modified, and should absolutely be looked over by anyone using this code to customize your lighting experience. I have tried to be as accomodating as possible to any potential build with various LEDs. I am but one dev. :)

Here's a brief on what you're looking at:

1) WS2812B Digital or 12V Analog strips

There are 3 zones: bumper1, bumper2, and ground. Ground is optional.
At a bare minimum you must have front and back bumper red LED 12V analog strips for brake lights.
Reallistically it doesn't cost much to get beautiful RGB control for the ground zone. Your control options are:
A) I've written a feature I haven't seen in the wild: RGB rainbow that chases the ground at the speed you roll. (digital strips)
B) You can do rainbow colors that change with speed with analog RGB(W) strip as well as digital strip. (digital or analog strips)
C) Static rainbow, or static colors. (digital or analog strips)
D) Eventually there will be a "scan and collect" effect I will add, takes time. (digital strips)
E) Eventually there will be a pulsing effect, takes time. (digital or analog strips)
   
3) LED strip headlights, "custom" LED headlights, or none

    If none, use custom and leave pins disconnected, but really, why? The ~1KWH battery I chose can run my 2 watt "custom" LED for ~21 days straight..
    If your battery isn't large enough consider a different battery size, I will eventually include CAD models for multiple sizes.

At this time I have chosen to utilize an [Arduino Nano](https://store.arduino.cc/products/arduino-nano) to pull data from the [VESC](https://github.com/vedderb/bldc) over SPI and control LED lighting. I've chosen an acceptable generic Arduino Nano clone as availability at the time of purchase seemed to be low. I cannot vouch for personal purchasing choices, so YMMV.

I am not certain if the MCU on said board can truly handle the tasks at the frequency I am hoping as even controlling WS2812B digital RGB strips at all seems to be at it's limits. Getting accurate timing from this MCU for WS2812B LED strip control is commonly cited as a difficulty for developers. Real world tests will show if I need to adjust my MCU choice and will be forced to use a custom PCB. Not that this is a particularly challenging feat, and it's not off the table if Arduino Nanos can hand this challenge. I will eventually create a custom PCB for surface mount that will handle far more of the "custom" electronics that need to be made for this project. Included will be a resistor network for the weight sensing footpads, buck PSU to 12V or 5V, constant current PSU for LED headlights, control for said headlights, control for 12V analog LED RGB(W) strips, and controlling 5V WS2812B digital RGB LED strips. When I do decide to do this most likely I will replace the ATMEGA328P with a more capable chip. Again, I am but one dev. :)
