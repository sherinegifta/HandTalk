# HandTalk
HandTalk is an Arduino based ASL sign detection and emergency contact system meant for differently abled people who need constant medical attention.
India constitutes 2.4 million deaf and dumb population, which holds the 20% of the world's Deaf and Dumb Population. These people lack the amenities that a normal person has. 

Deaf people have difficulty in communicating with people who do not understand sign language. 

The Hand Talk glove is a normal glove fitted with flex sensors. The sensors give an output based on a stream of data that varies with degree of bend made by the fingers. Flex sensors are sensors that change in resistance depending on the amount of bend on the sensor. They convert the change in bend to electrical resistance - the more the bend, the more the resistance value. The output from the sensor is converted to digital and is displayed on a LCD screen.

# General Structure:
Our project, HandTalk, translates hand gestures into a message. Flex Sensors are sewn onto the glove pick up the gesture made by the individual and then with the help of the Arduino, the analogue input is converted to digital for various gestures. For every particular gesture, there is specific digital output and that the digital output for the specific gesture is reserved for a specific message. So, when the individual does that particular gesture, the predefined message for that gesture is displayed on the LCD along with a beep(sound).

Given below is the block diagram for the same:

![alt text](https://i.ibb.co/Xj3mRGS/PROJECT.png)

This implementation heavily borrows from Hadeel Ayoub's implementation of SignLanguageGlove, from Goldsmith University, London and HandTalk from Carnegie Mello University by Bhargav Bhat, Hemant Sikaria, Jorge L. Meza and Wesley Jin (https://course.ece.cmu.edu/~ece549/spring08/team12/).

The difference in our project lies in the emergency message sent to the specified emergency contact via a GSM Module and also a tailored and more niche solution for deaf and dumb people that need medical monitoring: leads to a lighter solution.

# Future Enhancements:
1) With the help of various gestures commands, additional code and more sensitive analogue readings from the sensors, more commands can be added to extend the communication.
3) An oximeter may be used to record a person’s heart rate and in case of any abnormalities, a message can be sent to the concerned person via the GSM module seeking immediate medical attention.
4) Using the IoT technology we can connect this for live updates of the patient or person like locations, status body conditions etc. and customizable healthcare reports with data analysis using graphs and plotting tools.

# References:
1) Ms. Divyani Shende,Prof. Nakul Nagpal , Prof. Mayuri Chawla”,Literature Survey on Digital Glove for Gesture Recognition” , (Department of M. Tech (VLSI Design), Jhulelal Institute of Technology, India)  (Department of ETC Engineering, Jhulelal Institute of Technology, India)  (Department of ETC Engineering, Jhulelal Institute of Technology, India) 

2) P.B.Patel, Suchita Dhuppe, Vaishnavi Dhaye,”Smart Glove For Deaf And Dumb Patient”, Department Of Instrumentation Engineering Dr. D. Y. Patil Institute Of Technology Pimpri , Pune 411018 Maharashtra India.

3) Ambika Gujrati, Kartigya Singh,Khushboo,Lovika Soral, Mrs. Ambikapathy,
”Hand-talk Gloves with Flex Sensor: A Review”

4) ”Design of Smart Gloves”,Ms. Pallavi Verma,M.E. Scholar, EE, NITTTR Chandigarh
Mrs. Shimi S.L.Assistant Professor, EE NITTTR Chandigarh, Dr. S. Chatterji,Professor and Head, EE NITTTR Chandigarh
