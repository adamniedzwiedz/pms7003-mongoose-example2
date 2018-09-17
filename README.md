# Mongoose OS the PMS7003 dust sensor example (C/C++)

For the details look at the [library](https://github.com/adamniedzwiedz/pms7003-mongoose-os-lib2)

## Typical connection.

<p align="center">
  <img src="https://github.com/adamniedzwiedz/pms7003-mongoose-example2/blob/master/pms7003_connection.png">
</p>

## Overview

This example shows how to read the PM concentration (air polution) using the PMS7003 dust sensor with ESP8266 and Mongoose OS.

Since communication with the sensor is done via *UART0* the debug messages are sent through *UART1*.

In the example the PMS7003 is set to work in a **passive mode** and readings are done via *requests*. 
However it is possible to set the sensor in an **active mode**  `pms7003_init(uart_no, pms7003_callback, ACTIVE)` or `pms7003_set_mode(mgos_pms7003, ACTIVE)`. 

It is also possible to put the sensor to *sleep* `pms7003_sleep(mgos_pms7003)` and then *wake it up* `pms7003_wakeup(mgos_pms7003)`. In a sleep mode internal fan is off. 

_Note_

The **pms7003_init** must be called with at least *2 second* delay after powering on the sensor.

## How to install this app
- [Download](https://github.com/adamniedzwiedz/pms7003-mongoose-example2/archive/master.zip) and unpack or clone `git clone https://github.com/adamniedzwiedz/pms7003-mongoose-example2` the project
- Install [mos tool](https://mongoose-os.com/software.html)
- Open command line window and go to the project folder and run `mos build --platform esp8266`
- Run `mos flash`
