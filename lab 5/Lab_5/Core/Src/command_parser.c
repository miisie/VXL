/*
 * command_parser.c
 *
 *  Created on: Dec 10, 2021
 *      Author: buiqu
 */

#include "command_parser.h"
#include "main.h"
enum ParserState  {Init , Read_Data};
enum ParserState parser_state = Init;
int index = 0;
int index_data = 0;
uint8_t  str[30];
void command_parser_fsm (){
	switch (parser_state){
		case Init:
			if (buffer[index] == '!') parser_state = Read_Data;
			else{
				index++;
				if(index == MAX_BUFFER_SIZE) index = 0;
			}
			break;
		case Read_Data:
			index ++;
			if (buffer[index] == '!') break;
			else if (buffer[index] == '#') {
				command_data[index_data] = '\0';

				if (buffer[index-1] == '!') parser_state = Init;
				else{ command_flag = 1;index = 0;buffer[0] = '\0';index_buffer = 0;parser_state = Init;index_data = 0;}
			}
			else {
				command_data[index_data++] =  buffer[index];
			}
			break;
	}
}


