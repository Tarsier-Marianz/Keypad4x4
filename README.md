# Arduino-Keypad4x4


Assorted samples on how use **Keypad4x4** in [Arduino](https://www.arduino.cc/).

* `Keypad4x4Basic` - basic example using *Keypad4x4*, just print keys being pressed into [Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/).
* `Keypad4x4Advanced` - pressed keys save to buffer array before printing into [Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/)  after it reach limit buffer length.
* `Keypad4x4CharsIndicator` - another simple example on how to use *Keypad4x4*, adding some LED indicator depending type of characters being pressed, also clearing buffered keys when pressing `#` or `*`, buzzer if any keys being pressed.