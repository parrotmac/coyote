# coyote

Arduino Serial to SPI CAN Interface

This is a barebones Arduino sketch designed to send data from an Arduino to [Olympus2](https://github.com/parrotmac/olympus2).

The data output is formatted as: `CAN_ID:FRAME_VALUE\n`

For example:

```
25:FFF0567B7B7BA6

```
