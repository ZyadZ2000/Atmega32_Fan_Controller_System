# Atmega32_Fan_Controller_System

The Atmega32 microcontroller continuously monitors the temperature and based on the
temperature value, the microcontroller will drive the fan like this:
<ul>
        <li>a. If the temperature is less than 30C turn off the fan.</li>
        <li>b. If the temperature is greater than or equal 30C turn on the fan with 25% of its
            maximum speed.</li>
        <li>c. If the temperature is greater than or equal 60C turn on the fan with 50% of its
            maximum speed.</li>
        <li>d. If the temperature is greater than or equal 90C turn on the fan with 75% of its
            maximum speed.</li>
        <li> e. If the temperature is greater than or equal 120C turn on the fan with 100% of its
            maximum speed.</li>
    </ul>
      
      
<h1 style="font-size: 14px;">Implemented drivers are: GPIO, LCD, ADC, LM35 Sensor, DC Motor, and PWM</h1>
<img src="https://user-images.githubusercontent.com/85132955/212487836-d5545469-8093-43f1-bc5e-f97fd1a7b6b4.png" style="display: block; width: 80%;">
      
    
