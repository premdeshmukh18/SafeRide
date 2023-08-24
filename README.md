# SafeRide
By utilizing technology to identify potential safety hazards, the innovative project Saferide seeks to increase rider safety. Saferide promotes safe riding practices and reduces the risk of accidents and injuries by monitoring if a rider is wearing a helmet and is under the influence of alcohol. With more vehicles on the road and increased accidents and fatalities, there is a growing need for solutions promoting safe transportation practices. Saferide meets this need by employing sensors to detect possible safety hazards and inform riders and drivers when needed. Saferide has the ability to drastically minimize the risks connected with riding and make the roads safer.
## Table of Contents

- [Objectives](#objectives)
- [Block Diagram of the system](#blockdiagram)
- [Hardware Used](**hardware**)
- [Software Requirements](**software**)
- [Conclusion](#conclusion)
- [Future Scope](#futurescope)

## Objectives

  - To study statistics and research papers on existing projects related to the smart helmet to realize the depth of a problem and to define a final problem statement.
  - To Explore various electronic components and sensors applicable to the proposed system. Decide the most feasible components and check their availability in the market. Getting familiar with the Arduino IDE and design logic for integrating the microcontroller and various sensors.
  - To design a circuit diagram and use available simulation software to check the reliability of the designed circuit diagram.
  - To test and debug the finalized circuit diagram for various cases.

## BlockDiagram 
![block diagram](https://github.com/premdeshmukh18/SafeRide/assets/97452643/f896a263-e5d2-4bf0-8ca1-55d6eb1a6790)

1. **Helmet Wear Check** block uses a push button to detect whether the rider is
wearing a helmet or not. The signal is interpreted by the ESP (microcontroller)
according to the logic of the code.
2. **Alcohol Detection** block utilizes an MQ3 sensor to detect alcohol levels. It
sends digital or analog signals within a certain range to indicate the presence
of alcohol.
3. The **Server** block, powered by an **ESP8266**, acts as a server. It collects data
from other blocks, checks if the rider is under the influence of alcohol,
Wearing a helmet verifies the receiver's presence on the other end. It
can communicate with the receiver using libraries like **ESPNOW** ([espnow library](https://github.com/yoursunny/WifiEspNow.git)) without
sending data to the cloud.
4. The **Receiver** block receives data from the server and enables other blocks
(such as I2C LCD and Motor) to function based on the received message.
5. The **I2C (LCD)** block uses the I2C protocol to interface with an LCD
display. It displays appropriate messages and warnings to the rider based on
the system's purpose.
6. The **Engine Motor** block represents a prototype of the actual motor on an electric
motorcycle. It consists of an L293D motor driver and a 5V DC toy motor.

**Hardware**

● Push Button

● Alcohol Sensor MQ3 [4753]

● ESP8266 (NodeMCU)

● 16x2 (1602) Character Green Backlight LCD Display

● L293D Motor Driver

● 150 RPM Single Shaft DC Motor


**Software**

[Arduino IDE(2.1.0)](https://docs.arduino.cc/software/ide-v2) and [ESP8266 library](https://github.com/esp8266/Arduino.git)


## Conclusion

The “SafeRide” project is a significant contribution to enhancing the safety of
motorcycle riders. The project involves the integration of different technologies to
develop a helmet that can detect Alcohol and helmet wear to improve safety. The
system includes sensors, microcontrollers, and wireless communication technologies.
The project aims to prevent accidents and reduce the severity of injuries in case of an
accident.

## FutureScope 

● Using FSR(Force sensitive resistor) instead of push-button for greater
accuracy and sensitivity.

● Improved data analysis: The data collected by the smart helmet system can be
analyzed to provide insights into the causes of accidents and help improve
safety policies and regulations.

● Integration with smart cities: The smart helmet system can be integrated with
smart city systems to provide real-time information on road conditions, traffic,
and weather conditions to enhance safety.







