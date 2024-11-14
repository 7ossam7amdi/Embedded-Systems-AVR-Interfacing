
#include <util/delay.h>
#include "LIB/Std_Types.h"
#include "DIO/DIO_interface.h"
#include "LED_interface.h"



int main(){

	LED_t My_LED = {LED_SINK , PORT_A , PIN0 };

	LED_Init(&My_LED);

	while(1){
		LED_ON(&My_LED);
		_delay_ms(1000);
		LED_OFF(&My_LED);
		_delay_ms(1000);
	}
}

