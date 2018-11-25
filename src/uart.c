/*
 * uart.c
 *
 *  Created on: Nov 7, 2018
 *      Author: Swarupa De
 */



#include "MKL25Z4.h"
#include "uart.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>

#define UART0_BAUD_RATE             (57600) //115200
//declare rx_buffer and tx_buffer for data manipulation

void uartinit()
{

		    uint16_t baudmoddivisor;

		   //Set gate clock  for PORTA
			SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

			//Enable clock for UART0
			SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

			// Set the alternate function for PORTA as UART0
			PORTA_PCR1 |= PORT_PCR_MUX(0x2);
			PORTA_PCR2 |= PORT_PCR_MUX(0x2);

			//set clock source as MCGPLLCLK/2
			SIM_SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK);

			SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);
			//SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL(1);

			// Disable tx and rx before editing registers of UART0
			UART0_C2 |= (UART0_C2_TE(0) | UART0_C2_RE(0));


			//calculate the baud rate modulo divisor and set the baud rate
			UART0_BDH &= ~UART0_BDH_SBR_MASK;
			UART0_BDL &= ~UART0_BDL_SBR_MASK;

			baudmoddivisor= (uint16_t)((SystemCoreClock)/(UART0_BAUD_RATE *16));
			UART0_BDH |= UARTLP_BDH_SBR((baudmoddivisor >> 8)) ;
			UART0_BDL |= UARTLP_BDL_SBR(baudmoddivisor);

			//Selecting 8 bit data, 1 stop bit, No parity
			UART0_C1 |= UART0_C1_M(0) | UART_C1_PE(0);
			UART0_BDH |= UART_BDH_SBNS(0);


			//Enabling the Transmitter enable and receiver enable bit
			UART0_C2 |= (UART0_C2_TE(1) | UART0_C2_RE(1));



}

void RX_interrupt_init()
{

	NVIC_EnableIRQ(UART0_IRQn);
	UART0_C2 |= (UART_C2_RIE_MASK);

}
void send_to_console_str(char data[])
{
	for(int i =0; data[i] != '\0'; i++)
	{
		while(!(UART0_S1 & UART_S1_TDRE_MASK));
		UART0_D = (data[i]);
		while(!(UART0_S1 & UART_S1_TC_MASK));
	}
}

void send_to_console(uint8_t data)
{
	while(!(UART0_S1 & UART_S1_TDRE_MASK));
	UART0_D = (data);
	while(!(UART0_S1 & UART_S1_TC_MASK));



}

status receive_from_console()
{
	uint8_t data;
	status value;


	data = UART0_D;
#ifdef DEBUG
	send_to_console_str("Inserting\r\n");
	send_to_console(data);
	send_to_console_str("\r\n");
#endif
	send_to_console(data);
	value =	insert_data(&RX_buffer, data);
	if(value == ERROR)
		return ERROR;

}
void UART0_IRQHandler()
{
	if((UART0_S1) & (UART0_S1_RDRF_MASK))
		{
			receive_from_console();
		}
}


