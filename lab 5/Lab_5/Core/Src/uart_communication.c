/*
 * uart_communication.c
 *
 *  Created on: Dec 10, 2021
 *      Author: buiqu
 */

#include "uart_communication.h"
#include "main.h"
#include "timer.h"

enum UartState {Init , Send_Data };
enum UartState uart_state = Init;
uint8_t  str[30];
uint32_t ADC_value = 0;
int length;
void uart_communiation_fsm (){
	switch(uart_state){
		case Init:
			  if (command_flag == 1){
					 command_flag = 0;
					 HAL_GPIO_TogglePin(GPIOA, Yellow_Pin);
					 uart_state = Send_Data;
			  }
			break;
		case Send_Data:
			if (strcmp(command_data,"RST") == 0){
				ADC_value = HAL_ADC_GetValue (& hadc1 );
				length = sprintf (str , "\r\n adc = %d\r\n", ADC_value );
				HAL_UART_Transmit (& huart2 , ( void *) str ,length, 1000) ;
				setTimer(3000);
				command_data[0] = '\0';
			}
			else if (strcmp(command_data,"OK") == 0){
				int length2 = sprintf (str , "\r\n check = %s\r\n", command_data );
				HAL_UART_Transmit (& huart2 , ( void *) str ,length2, 1000) ;
				command_data[0] = '\0';
				command_flag = 0;
				uart_state = Init;
			}
			if(timer_flag == 1){
				HAL_UART_Transmit (& huart2 , ( void *) str ,length, 1000) ;
				setTimer(3000);
			}
			break;
	}
}
