# WindCat

WindCat is a smart air purifier with ESP8266EX.

## Feature

- measuring air quality(PM2.5, VOCs)
- Temp. and Humid. monitoring
- display current air quality
- Wi-Fi connection for report data to server using MQTT
- Fan control using PWM(like PC system cooling fan)
- Force maximum speed mode
- Deep sleep mode support

## BOM

| Manufacturer | Part No. | Qty. | Note |
| --- | --- | --- | --- |
| Any Vender | Arduino UNO R3 or Arduino NANO(328) | 1 |  |
| WaveShare | 128*64 SH1106 I2C OLED display(*1) | 1 |  |
| Sharp | GP2Y1010AU0F or GP2Y1014AU0F | 1 | |
| Any Vender | LED NEOPIXEL STICK 8 WS2812 RGB | 1 | |
| Any Vender | PWM controlled DC FAN | 2 | 4pin connecter(*2), least 100m^3/h or 137Pa(*3) |
| Any Vender | Momentary switch | 2 | |
| Any Vender | 11Ω register | 1 | LED protect |
| Any Vender | 150Ω register | 1 | |
| Any Vender | 10kΩ register | 2 |  |
| Any Vender | 220μF capacitor | 1 | |
| Any Vender | perfboard or breadboard | 1 | |
| Any Vender | USB B(or micro B) Female To USB B(or micro B) Male cable | 1 | If you do not need a firmware update, you can use a DC power cable. |


> Note
> 1. You need to set the rear jumper
> 2. A PWM terminal is required to control the speed of the fan.
> 3. It depends on the filter you use. Please check the filter's data sheet.


## Buy link for korean

한국에서 구입할 사람을 위해 부품의 링크를 남깁니다.

| Part No. |  |
| --- |  |
| 128*64 SH1106 SPI OLED display | http://www.eleparts.co.kr/EPXDYVCA |
| GP2Y1010AU0F or GP2Y1014AU0F | http://www.devicemart.co.kr/1327422 |
| LED NEOPIXEL STICK 8 WS2812 RGB | http://www.eleparts.co.kr/EPXFJC8G |
| Momentary switch| http://www.devicemart.co.kr/1312324 |
| PWM controled DC FAN | http://prod.danawa.com/info/?pcode=135166&cate=1131548#bookmark_product_information |
