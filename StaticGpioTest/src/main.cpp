/**			<! Coding with UTF-8 >
 *   Date      :   2019/11/09     YYYY-MM-DD
 *   Author    :   Happeneddr9
 *   Font use  :   Consolas with YaHei 雅黑體
 *
 *   @brief:	YM2151 VGM Player code
 *
 *		UTF-8 TextTest: マフェット
 */

/**
 *	系統參數請到 Basic.h 或 main.h 處修改
 *	System parameter defined in header "Basic.h" or "main.h"
 */
#include "Arduino/Basic.h"         		// use delay()  millis()
//#include "HardwareUart/HWSerial0.h"     // use Serial  硬體UART串列阜

// <!# Warning!: PA13 and PA14 using for the ST-LINK, so avoid to use them for GPIO !>



//const GpioC LED0(PC14);		// less Size, 2 bytes per Pin.
//const GpioB LED1(PB12);		// construct by GpioPin type, also initialize Port RCC.

//const GpioFast LED0(PC14);	// General Pin, larger size usage, 8 bytes.
//const GpioFast LED1(PB12);	// construct by GpioPin type.

const GpioC LED0(GPIO_Pin_14);	// less size usage, 2 bytes per Pin.
const GpioB LED1(GPIO_Pin_12);	// construct by GPIO_pins_define, RCC isn't initialized here.

int main(void) {
	SysTickInit(1000);     // 系統時鐘頻率 預設1kHz 此設定會影響到 delay() millis() std::chrono
	// Serial.begin(38400, Usart1::PinMap_TXRX::DefaultMap);
	LED0.RCC_config(Port::B);
	LED0.RCC_config(Port::C);

	LED0.begin(OUTPUT);
	LED1.begin(OUTPUT);

	for (uint32_t i = 0; i < sizeof(LED1); ++i){
		LED1.setHigh();
		delay(200);
		LED1.setLow();
		delay(200);
	}

	delay(2000);

	for (;;) {
		LED0.setHigh();
		delay(200);
		LED0.setLow();
		delay(500);

		LED1.setHigh();
		delay(200);
		LED1.setLow();
		delay(500);
	}
}

