# 👽 alien-client
Art-Net to DMX converter with Arduino.

## Hardware Implemention
This code required a ethernet interface and DMX (RS485) transceiver.

### Ethernet 
By default it uses the same pins with [Official Arduino Ethernet Shield](https://store.arduino.cc/usa/arduino-ethernet-shield-2) shown [here](https://playground.arduino.cc/Main/ShieldPinUsage). We are currently using third-party ethernet interface with `10`, `11`, `12` and `13` pins and it works fine.

### DMX (RS485)
We are using `RS485` ([Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/485fm.pdf)) as converter IC. Connection pin on arduino defined as `DMX_OUT_PIN` in the code.

## Dependencies
- Artnet by Nathanaël Lécaudé ([GitHub](https://github.com/natcl/Artnet))
- DmxSimple by Peter Knight ([GitHub](https://github.com/PaulStoffregen/DmxSimple))

## Contributing
Issues and PRs are welcome.
