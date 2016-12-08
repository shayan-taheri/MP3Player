#include "unit_test.h"

void LED_Test(void) {
	uint8_t i;
	for (i=0; i<5; i++) {
		LED_FLASH_Change_State();
		delay1s(1);
	}
}

// void LCD_Test(void) {
// 	uint8_t text[] = "LCD Ready!";
// 	LCD_Write_String(text);
// }

void UART_Test(void) {
	uint8_t i=0;
	uint8_t text[] = "UART Ready!";

	while(text[i]!=0x00)
		putchar(text[i++]);
	
	printf("\n\r");
}

// void Memory_Test(void) {
// 	uint8_t *txt_ptr;
// 	txt_ptr = code_memory_init();
// 	print_memory(50, txt_ptr);

// 	printf("\n\r");
// }

// void Xdata_Memory_Test(void) {
// 	uint8_t *txt_ptr;
// 	txt_ptr = xdata_memory_init();
// 	print_memory(50, txt_ptr);

// 	printf("\n\r");
// }

void I2C_Test(void) {
	uint8_t	I2C_error, time_out;
	uint8_t bytes_to_send[] = {0x01};
	uint8_t bytes_to_receive[1];
	P1_3 =0;
	P1_3 =1;
	time_out = 100;
	do {
		I2C_error = I2C_Write(0x43, 1, &bytes_to_send);		// Sending internal memory address
		time_out--;
	} while((I2C_error!=I2C_NO_ERROR)&&(time_out!=0));
	
	time_out = 100;
	do {
		I2C_error = I2C_Read(0x43, 1, &bytes_to_receive);		// Receiving data from slave
		time_out--;
	} while((I2C_error!=I2C_NO_ERROR)&&(time_out!=0));
	P1_3 =0;
	printf("0x%2.2bX\n\r", bytes_to_receive[0]);
	if (bytes_to_receive[0]==0xAC)
		printf("I2C Acknowledge received!\n");
	else
		printf("I2C Failed!\n");
}

	// printf("Sending Patch file to MP3 Decoder");
	// do {
	// 	bytes_to_send[0] = *(config_ptr+(i++));
	// 	bytes_to_send[1] = *(config_ptr+(i++));
	// 	printf(">%bu", bytes_to_send[0]);
	// 	printf(":%bu<", bytes_to_send[1]);
	// 	time_out = 100;
	// 	do {
	// 		I2C_error = I2C_Write(0x43, 2, &bytes_to_send);		// Sending internal memory address
	// 		time_out--;
	// 	} while((I2C_error!=I2C_NO_ERROR)&&(time_out!=0));
	// 	if (time_out == 0) {
	// 		I2C_error = TIMEOUT_ERROR;
	// 	}
	// } while((I2C_error==I2C_NO_ERROR) && (bytes_to_send[0] != 0xFF));
	// if (I2C_error == I2C_NO_ERROR){
	// 	printf("Sent.\n");		
	// } else {
	// 	printf("Error!\n");
	// }