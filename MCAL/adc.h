/*-------------------------------------------------------------------
 [FILE NAME]: adc.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for ADC driver
 -------------------------------------------------------------------*/

#ifndef ADC_H_
#define ADC_H_

/*----------------------------INCLUDES----------------------------*/

#include "../std_types.h"

/*----------------------------DEFINITIONS----------------------------*/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*----------------------------ENUMS----------------------------*/

/*-------------------------------------------------------------------
 [Enum Name]: ADC_ReferenceVolatge
 [Description]: This enum is responsible for the reference voltage
 used for the ADC
 -------------------------------------------------------------------*/

typedef enum {
	AREF, AVCC, _, INTERNAL
} ADC_ReferenceVolatge;

/*-------------------------------------------------------------------
 [Enum Name]: ADC_Prescaler
 [Description]: This enum is responsible for the prescaler
 used for the ADC
 -------------------------------------------------------------------*/

typedef enum {
	DIV_FACTOR_2,
	DIV_FACTOR_2_2,
	DIV_FACTOR_4,
	DIV_FACTOR_8,
	DIV_FACTOR_16,
	DIV_FACTOR_32,
	DIV_FACTOR_64,
	DIV_FACTOR_128
} ADC_Prescaler;

/*----------------------------STRUCTURES AND UNIONS----------------------------*/

/*-------------------------------------------------------------------
 [Structure Name]: ADC_ConfigType
 [Description]: This structure is responsible for configuring
 the ADC
 -------------------------------------------------------------------*/

typedef struct {
	/* Reference voltage configuration */

	ADC_ReferenceVolatge ref_volt;

	/* Prescaler configuration */

	ADC_Prescaler prescaler;

} ADC_ConfigType;

/*----------------------------FUNCTION DECLARATIONS----------------------------*/

/*-------------------------------------------------------------------
 [Function Name]: ADC_init
 [Description]: Function responsible for initializing the ADC
 [Args]: ADC_ConfigType* Config_Ptr:
 Pointer to the configurations structure of ADC
 [Returns]: void
 -------------------------------------------------------------------*/

void ADC_init(const ADC_ConfigType *Config_Ptr);

/*-------------------------------------------------------------------
 [Function Name]: ADC_readChannel
 [Description]: Function responsible for reading the digital value of
 the given ADC channel
 [Args]: uint8 channel_num:
 Number of the channel to read the analog signal
 [Returns]: The digital value
 -------------------------------------------------------------------*/

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
