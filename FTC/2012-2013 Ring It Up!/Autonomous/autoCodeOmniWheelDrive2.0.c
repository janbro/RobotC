#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     weightedRingLight,tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoStandard)
#pragma config(Sensor, S2,     lightSensor,            sensorLightActive)
#pragma config(Sensor, S3,     HTIRS2,               sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "/hitechnic-sensormux.h"
#include "/lego-ultrasound.h"
#include "/hitechnic-force.h"
#include "/hitechnic-irseeker-v2.h"
// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTFS1 = msensor_S4_1;
const tMUXSensor HTFS2 = msensor_S4_2;
void raiseArm(){
	/*int encoderTarget=-1600;
	if(nMotorEncoder[weightedRingLight]<encoderTarget){
		motor[armMotor]=-100;
	}
	else if(nMotorEncoder[weightedRingLight]>encoderTarget){
		motor[armMotor]=100;
	}
	else{
		motor[armMotor]=0;
	}*/
}

task main()
{
	//while(true){
	//	nxtDisplayCenteredTextLine(1,"%i",SensorValue[lightSensor]);
	//}
	//waitForStart();
	nMotorEncoder[weightedRingLight]=0;
	int threshold=20;
	int powerLevel=50;
	int lines=0;
	int prevColor=0;
	int dcS1,dcS2,dcS3,dcS4,dcS5;
	while(SensorValue[lightSensor]<threshold){
		motor[motorFL] = -powerLevel;
    motor[motorFR] = -powerLevel;
    motor[motorBR] = -powerLevel;
    motor[motorBL] = -powerLevel;
    HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
    nxtDisplayCenteredTextLine(1,"IR%i",dcS3);
	}
	motor[motorFL]=0;
	motor[motorFR]=0;
	motor[motorBL]=0;
	motor[motorBR]=0;
	if(dcS3>10){
		while(true){
			raiseArm();
			nxtDisplayCenteredTextLine(1,"IRBeacon Found");
		}
	}
	wait1Msec(1000);
	while(SensorValue[lightSensor]<threshold){
		motor[motorFL]=powerLevel;
		motor[motorFR]=powerLevel;
		motor[motorBL]=0;
		motor[motorBR]=0;
	}
	motor[motorFL]=0;
	motor[motorFR]=0;
	motor[motorBL]=0;
	motor[motorBR]=0;
	PlaySound(soundBeepBeep);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	if(dcS3>10){
		while(true){
			raiseArm();
			nxtDisplayCenteredTextLine(1,"IRBeacon Found");
		}
	}
	wait1Msec(1000);
	while(SensorValue[lightSensor]<threshold){
		motor[motorFL]=powerLevel;
		motor[motorFR]=powerLevel;
		motor[motorBL]=0;
		motor[motorBR]=0;
	}
	motor[motorFL]=0;
	motor[motorFR]=0;
	motor[motorBL]=0;
	motor[motorBR]=0;
	PlaySound(soundBeepBeep);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	if(dcS3>10){
		while(true){
			raiseArm();
			nxtDisplayCenteredTextLine(1,"IRBeacon Found");
		}
	}
	wait1Msec(1000);
	while(SensorValue[lightSensor]<threshold){
		motor[motorFL]=-powerLevel*3;
		motor[motorFR]=-powerLevel*3;
		motor[motorBL]=0;
		motor[motorBR]=0;
	}
	motor[motorFL]=0;
	motor[motorFR]=0;
	motor[motorBL]=0;
	motor[motorBR]=0;
	PlaySound(soundBeepBeep);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	if(dcS3>10){
		while(true){
			raiseArm();
			nxtDisplayCenteredTextLine(1,"IRBeacon Found");
		}
	}
	wait1Msec(1000);
	while(SensorValue[lightSensor]<threshold){
		motor[motorFL]=-powerLevel*2;
		motor[motorFR]=-powerLevel*2;
		motor[motorBL]=0;
		motor[motorBR]=0;
	}
	motor[motorFL]=0;
	motor[motorFR]=0;
	motor[motorBL]=0;
	motor[motorBR]=0;
	PlaySound(soundBeepBeep);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	if(dcS3>10){
		while(true){
			raiseArm();
			nxtDisplayCenteredTextLine(1,"IRBeacon Found");
		}
	}
	wait1Msec(1000);
	while(SensorValue[lightSensor]<threshold){
		motor[motorFL]=-powerLevel;
		motor[motorFR]=-powerLevel;
		motor[motorBL]=0;
		motor[motorBR]=0;
	}
	motor[motorFL]=0;
	motor[motorFR]=0;
	motor[motorBL]=0;
	motor[motorBR]=0;
	PlaySound(soundBeepBeep);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	if(dcS3>10){
		while(true){
			raiseArm();
			nxtDisplayCenteredTextLine(1,"IRBeacon Found");
		}
	}
	wait1Msec(1000);
}
