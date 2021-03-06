#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  baseRightIME,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  baseLeftIME,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           baseRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           baseLeft,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port4,           mobileLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           mobileRight,   tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void mobileUp(){
	motor[mobileLeft] = -127;
	motor[mobileRight] = -127;
	wait1Msec(400);
}

void mobileDown(){
	motor[mobileLeft] = 127;
	motor[mobileRight] = 127;
	wait1Msec(400);
}

void mobileStop(){
	motor[mobileLeft] = 0;
	motor[mobileRight] = 0;
}

void mobileStayH(){
	motor[mobileLeft] = -20;
	motor[mobileRight] = -20;
}

void mobileStay(){
	motor[mobileLeft] = -63;
	motor[mobileRight] = -63;
}

void clearEncoderValue(){
	nMotorEncoder[baseLeft] = 0;
	nMotorEncoder[baseRight] = 0;
}

// 1 inch per 15 revolutions
//mobile goal: 55 inches away

void moveForward(float inches){
	clearEncoderValue();
	float ratioToLeft = 0.9;
	while (nMotorEncoder[baseRight] > -50*inches){
		motor[baseLeft] = -80;
		motor[baseRight] = -80*ratioToLeft;
	}
}

void charge(){
	motor[baseLeft] = -120;
	motor[baseRight] = -110;
}

void wiggle(){
	motor[baseLeft] = -60;
	motor[baseRight] = -50;
	wait1Msec(800);
	motor[baseLeft] = 60;
	motor[baseRight] = 50;
	wait1Msec(500);
	motor[baseLeft] = 80;
	motor[baseRight] = -70;
	wait1Msec(100);
	motor[baseLeft] = -80;
	motor[baseRight] = 70;
	wait1Msec(100);
}

void moveBackward(float inches){
	clearEncoderValue();
	float ratioToLeft = 0.9;
	while (nMotorEncoder[baseRight] < 50*inches){
		motor[baseLeft] = 80;
		motor[baseRight] = 80*ratioToLeft;
	}
}


void rotateSmall(){
	clearEncoderValue();
	while (nMotorEncoder[baseRight] > -350){
		motor[baseLeft] = 80;
		motor[baseRight] = -70;
	}
}

void stopMoving() {
	motor[baseLeft] = 0;
	motor[baseRight] = 0;
}

task main()
{
	clearEncoderValue();
	moveForward(45);
	stopMoving();
	mobileUp();
	mobileStayH();
	moveBackward(55);
	stopMoving();
	rotateSmall();
	stopMoving();
	mobileUp();
	mobileStay();
	charge();
	wait1Msec(2500);
	stopMoving();
	wiggle();
	wiggle();
	wiggle();
	mobileDown();
	moveBackward(20);
	stopMoving();
}
