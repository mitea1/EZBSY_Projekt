/*
 * Light_Sensor.c
 *
 *  Created on: Mar 16, 2016
 *      Author: Adrian
 */

#include <stm32l1xx.h>
#include "i2c.h"
#include <math.h>
#include "Light_Sensor.h"
//#include "UART_Print.h"


char string[20];


void test(){

	TELTRONIC_I2C_Init(I2C2);

	while(1){



//		sprintf(string, "%d", *data);
//		UART1_Write("New Value: ");
//		UART1_Write(string);
//		UART1_Write("\n");
	}
}

/**
 * Returns the Lux from the Light Sensor
 */
double LIGHT_SENSOR_getLux(void){

	// Error Value
	uint8_t error;

	// Data Container
	uint8_t data[2];

	// Get Data via I2C
	error = TELTRONIC_I2C_Read(I2C2,LIGHT_SENSOR_ADDRESS,LIGHT_SENSOR_LUX_H_L_BYTE,1,data,2);

	// Extract values from register
	uint8_t exponent = (data[0] >> 4) & 0xF;
	uint8_t mantissa = data[0] & 0xF;

	// Calculate the lux value
	double lux = pow(2,exponent) + mantissa * 0.72;

	return lux;
}



