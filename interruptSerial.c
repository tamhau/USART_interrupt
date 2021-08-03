/*
 * interruptSerial.c
 *
 *  Created on: Apr 27, 2016
 *      Author: tamhau
 */

 #include <stdint.h>

 
 #include <avr/io.h>                     // needed for uint8_t
 #include <avr/interrupt.h>
 #include <avr/pgmspace.h>


 #include <avr/interruptSerial.h>

 // Initialize for USART
 void USART_init(void)
 {
   _inline_USART_init();
 }


 void USART_send(volatile char data, uint8_t Buffer)
 {
   _inline_USART_send(data,Buffer);
 }


 void USART_putstring(char *StringPtr, uint8_t Buffer)
 // sends the characters from the string one at a time to the USART
 {
   _inline_USART_putstring(StringPtr,Buffer);
 }


 void USART_putstring_P(const char *StringPtr, uint8_t Buffer)
 // sends the characters from the string one at a time to the USART
 {
   while(pgm_read_byte(StringPtr) != 0x00)
   {
     USART_send(pgm_read_byte(StringPtr++),Buffer);
   }
 }


