# TurnSignal-WS2812B
FastLED Turn Signal with Arduino and WS2812B

A build-up running light, the built-up about 0.2sec stands and then completely off without effect.
A kind of turn signal as in the Audi or VW Golf with push button for Left and Right, when the button is pressed, it will do the effect 3 times.

A big "thank you" goes to the user Hans from the forum tweaking4all.com
The link to the topic: https://www.tweaking4all.com/forums/topic/running-light-with-push-button/

For the buttons,
From GND -> 10K Ohm resistor -> to pin 4. buttonleft
From fGND -> 10K Ohm resistor -> to pin 5. buttonright
Pin 2 -> one side of the switch.
+5V (Arduino) -> other side of the switch.

This is just the test or the test setup.
For real use, the LEDs should be powered by an external 5V power supply. The Arduino does not have enough power to supply the LEDs permanently.

For the color code of resistors see this great page: https://www.tweaking4all.com/hardware/resistor-color-calculator/


![Wire](https://github.com/Robiv8/TurnSignal-WS2812B/blob/master/TurnLight.png "Wire")

[![Video](http://img.youtube.com/vi/LjFCRdPBISA/0.jpg)](http://www.youtube.com/watch?v=LjFCRdPBISA "VideoTurneLight")
