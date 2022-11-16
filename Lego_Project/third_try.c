#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S3,     Colour,         sensorEV3_Color, modeEV3Color_Color)




task main()
{
	int saw_black=0;
	int flag_opos=1;
	//int i = 15;
	//int j = 20;
	//int temp;
 	short currentColour;
	while (true)
	{
		// Colours range from 0 to 7
	  // None    = 0
	  // Black   = 1
	  // Blue    = 2
	  // Green   = 3
	  // Yellow  = 4
	  // Red     = 5
	  // White   = 6
	  // Brown   = 7
		currentColour = SensorValue[Colour];
		switch(currentColour)
		{
			case 1:
			{

						setMotorSpeed(leftMotor, 20);		//Set the leftMotor (motor1) to half power (50)
						setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to half power (50)
				    displayCenteredBigTextLine(4, "black");
				    break;
			}
			case 6:
			{
				setMotorSpeed(leftMotor, 5);		//Set the leftMotor (motor1) to half power (50)
				setMotorSpeed(rightMotor, 20);  //Set the rightMotor (motor6) to half power (50)
				displayCenteredBigTextLine(4, "white");
				break;
			}
			default:
			{
				//problem with recognizing transition between black and white
				setMotorSpeed(leftMotor, 0);		//Set the leftMotor (motor1) to half power (50)
				setMotorSpeed(rightMotor, 0);  //Set the rightMotor (motor6) to half power (50)
			  displayCenteredBigTextLine(4, "None");
				break;

			}

		}



	}



}
