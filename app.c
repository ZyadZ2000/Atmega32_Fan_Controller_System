/*-------------------------------------------------------------------
 [FILE NAME]: app.c
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Source file for Application
 -------------------------------------------------------------------*/

/*----------------------------INCLUDES----------------------------*/

#include "MCAL/adc.h" /* To initialize the ADC */
#include "HAL/dc_motor.h" /* To control the DC MOTOR */
#include "HAL/lcd.h"  /* To initialize and use the LCD */
#include "HAL/lm35_sensor.h"  /* To get the reading of the LM35 Sensor */

int main(void) {

	/* Configuring the ADC*/

	ADC_ConfigType adc_config = { INTERNAL, DIV_FACTOR_8 };
	ADC_init(&adc_config);

	/* Initializing the LCD */

	LCD_init();

	/* Initializing the DC MOTOR */

	DcMotor_Init();

	/* Getting the reading of the sensor */

	uint8 Temp = LM35_getTemperature();

	while (1) {

		/*
		 Displaying the state of the fan and the temperature reading from the sensor
		 Changing the state and the rotation speed based on the read temperature
		 */

		if (Temp < 30) {
			LCD_displayStringRowColumn(0, 3, "FAN is OFF");
			LCD_displayStringRowColumn(1, 3, "Temp = ");
			LCD_intgerToString(Temp);
			LCD_displayString("  "); /* To clear any additional characters on the screen */
			DcMotor_Rotate(STOPPED, 0);
		} else if (Temp >= 30 && Temp < 60) {
			LCD_displayStringRowColumn(0, 3, "FAN is ON ");
			LCD_displayStringRowColumn(1, 3, "Temp = ");
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' '); /* To clear any additional characters on the screen */
			DcMotor_Rotate(CW, 25);
		} else if (Temp >= 60 && Temp < 90) {
			LCD_displayStringRowColumn(0, 3, "FAN is ON ");
			LCD_displayStringRowColumn(1, 3, "Temp = ");
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' '); /* To clear any additional characters on the screen */
			DcMotor_Rotate(CW, 50);
		} else if (Temp >= 90 && Temp < 120) {
			LCD_displayStringRowColumn(0, 3, "FAN is ON ");
			LCD_displayStringRowColumn(1, 3, "Temp = ");
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' '); /* To clear any additional characters on the screen */
			DcMotor_Rotate(CW, 75);
		} else {
			LCD_displayStringRowColumn(0, 3, "FAN is ON ");
			LCD_displayStringRowColumn(1, 3, "Temp = ");
			LCD_intgerToString(Temp);
			DcMotor_Rotate(CW, 100);
		}
		Temp = LM35_getTemperature(); /* Getting the latest reading */
	}
	return 0;
}
