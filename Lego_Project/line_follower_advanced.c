
#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S3,     Colour,         sensorEV3_Color, modeEV3Color_Color)


task main()
{
	int flag=0;
	short currentColour;
	int speed_add_left=0,speed_add_right=0;
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
		if(flag==1)
		{
			speed_add_left=0;
			speed_add_right=-5;
		}
		else
		{
			speed_add_left=-5;
			speed_add_right=0;
		}

		switch(currentColour)
		{
			//black
			case 1:
						setMotorSpeed(leftMotor, 20);		//Set the leftMotor (motor1) to half power (50)
						setMotorSpeed(rightMotor, 20);  //Set the rightMotor (motor6) to half power (50)
				    displayCenteredBigTextLine(4, "black");
				    break;

			default:
						if(flag==0)
						{
								setMotorSpeed(leftMotor, 20);		//Set the leftMotor (motor1) to half power (50)
								setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to half power (50)
								displayCenteredBigTextLine(4, "flag 1");
								flag=1;
				    		break;
						}
						else
						{
								setMotorSpeed(leftMotor, 5);		//Set the leftMotor (motor1) to half power (50)
								setMotorSpeed(rightMotor, 20);  //Set the rightMotor (motor6) to half power (50)
								displayCenteredBigTextLine(4, "flag 0");
								flag=0;
								break;
						}


		}


		sleep(20);
	}
}
