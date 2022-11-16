#pragma config(Motor,  motorB,          leftwheel,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightwheel,    tmotorEV3_Large, PIDControl, encoder)
task main()
{
		while(1)
		{
			 motor[leftwheel] = 10;
		  motor[rightwheel] = -10;

		}


}
