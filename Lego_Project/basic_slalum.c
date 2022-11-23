#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S3,     Colour,         sensorEV3_Color, modeEV3Color_Color)





task main()
{
	int saw_black=0;//if i saw black or not
	int saw_white=0;//if i saw white or not
 	short currentColour;//current colour that the robot saw
 	int time_black=0;//amount of loop time that i views black
 	int allow_black=0;//did i really recognized black and it's not a bug
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
			//in case i saw nothing
			case 0:
			{

				//problem with recognizing transition between black and white
				saw_black=0;
				saw_white=0;
				time_black=0;
				allow=0;
				setMotorSpeed(leftMotor, 0);		//Set the leftMotor (motor1) to  power (0)
				setMotorSpeed(rightMotor, 0);  //Set the rightMotor (motor6) to  power (0)
			  displayCenteredBigTextLine(4, "%d",currentColour);

				break;
			}

			//in case i saw black (turn right)
			case 1:
			{
						//if i saw white,then i say black is right
						if(saw_white==1||allow==1)
						{
								saw_black=1;
								setMotorSpeed(leftMotor, 20);		//Set the leftMotor (motor1) to  power (20)
								setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to  power (5)
						}
						else
						{
							//if didn't see white,black might be an error
							//if didnt see black more than 3 times
							if(time_black<1000)
							{
								setMotorSpeed(leftMotor, 5);		//Set the leftMotor (motor1) to  power (5)
								setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to  power (5)
								time_black++;
								saw_black=0;
							}
							//if it is consistant
							else if(time_black==1000)
							{
								saw_black=1;
								time_black=0;
								allow=1;
								setMotorSpeed(leftMotor, 20);		//Set the leftMotor (motor1) to  power (20)
								setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to  power (5)
							}

						}
				    displayCenteredBigTextLine(4, "black%d",allow);
				    break;
			}
			//in case i saw white (turn left)
			case 6:
			{
				if(saw_black==0)
				{
						setMotorSpeed(leftMotor, 5);		//Set the leftMotor (motor1) to  power (5)
						setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to  power (5)
				}
				else
				{
						setMotorSpeed(leftMotor, 5);		//Set the leftMotor (motor1) to  power (5)
						setMotorSpeed(rightMotor, 20);  //Set the rightMotor (motor6) to  power (20)

				}
				saw_white=1;
				time_black=0;
				displayCenteredBigTextLine(4, "white%d",saw_black);

				break;
			}

			//otherwise
			default:
			{
				//problem with recognizing transition between black and white
				setMotorSpeed(leftMotor, 5);		//Set the leftMotor (motor1) to half power (50)
				setMotorSpeed(rightMotor, 5);  //Set the rightMotor (motor6) to half power (50)
				time_black=0;
			  displayCenteredBigTextLine(4, "%d",currentColour);

				break;

			}

		}



	}



}
