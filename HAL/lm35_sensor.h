/*-------------------------------------------------------------------
 [FILE NAME]: lm35_sensor.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for LM35 Sensor driver
 -------------------------------------------------------------------*/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

/*----------------------------INCLUDES----------------------------*/

#include "../std_types.h"

/*----------------------------DEFINITIONS----------------------------*/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*----------------------------FUNCTION DECLARATIONS----------------------------*/

/*-------------------------------------------------------------------
 [Function Name]: LM35_getTemperature
 [Description]: Function responsible for calculate the temperature from the ADC digital value
 [Args]: void
 [Returns]: The value of the sensed temperature
 -------------------------------------------------------------------*/

uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
