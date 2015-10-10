#pragma config(Motor,  port3,           rightmotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftmotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           rotator,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           ldump,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           rdump,         tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){


	//Changeable, Debugable, conifig for motor speeds.

	int servoMin = -90; //Closed position for back gate (defualt)
	int servoMax = 127; //Open position for back gate

	int rotateSpeed = 40; //Speed of arm rotation
	int armSpeed = 60; //Speed of arm up-and-down
	
	//End config
	
	

	motor[ldump] = servoMin; //Set initial value of servos
	motor[rdump] = servoMin;

	while(true){ //Main loop - keeps the program running

		//Assign wheel motors to the up/down joysticks
		motor[leftmotor] = vexRT[Ch2];
		motor[rightmotor] = vexRT[Ch3];

		
		//ARM CONTROLS
		if(vexRT(Btn7U)){ //If button 7 up is pressed, move arm up
			motor[arm] = armSpeed * -1;
			} else if(vexRT(Btn7D)){ //If button 7 down is pressed, move arm down
			motor[arm] = armSpeed;
			} else { //If neither are pressed, keep the arm still
			motor[arm] = 0;
		}
		
		//ARM ROTATION CONTROLS
		if(vexRT(Btn6U)){ //If button 6 up is pressed, rotate arm clockwise
			motor[rotator] = rotateSpeed;
			} else if(vexRT(Btn5U)){ //If button 5 up is pressed, rotate arm counterclockwise
			motor[rotator] = rotateSpeed * -1;
			} else { //If neither are pressed, keep the arm still
			motor[rotator] = 0;
		}
		
		//GATE CONTROLS
		if(vexRT(Btn8U)){ //Close latch
			motor[ldump] = servoMin;
			motor[rdump] = servoMin;
		} else if(vexRT(Btn8D)){ //Open latch
			motor[ldump] = servoMax;
			motor[rdump] = servoMax;
		}


	}
	
}

}
