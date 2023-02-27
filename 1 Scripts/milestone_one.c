#pragma config(Sensor, dgtl4,  buttonToMove,   sensorDigitalIn)
#pragma config(Sensor, dgtl11, buttonToTurn,   sensorDigitalIn)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop, reversed)

/*
/	Vex Robotics RobotC Program, Test Code 007
/	"Milestone 1: Mechanical Test"
/
/	Paisley Kerstens, Aleksia Loewen, Arfaz Hussain
/
*/

int motorSpeed = 50;                                 // (UNIT) centimeter, cm

void moveForward() {
    /*MAIN*/
    motor[leftMotor] = motorSpeed;
    motor[rightMotor] = motorSpeed+5;                // calibrating with both motor speed
    wait1Msec(2000);                                 // may differ by weight and circumstance, subject to change

    /*STOP*/                                         // duration: 1 second
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
    wait1Msec(1000);

	/* motorSpeed=-15;                                 // legacy test start
	motor[leftMotor] = motorSpeed;
	motor[rightMotor] = motorSpeed-10;
	wait1Msec(3000); */                                // legacy test end

}

void turnRight() {
    /*MAIN*/
    motor[leftMotor] = motorSpeed;
    motor[rightMotor] = 0;                              // calibrating with both motor speed, duration: 1.3ish? seconds?
    wait1Msec(1300);                                    // duration will differ by weight, circumstances, subject to change

    /*STOP*/                                            // duration: 1 second
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
    wait1Msec(1000);

}

task main () {
    while (1==1) {                                    // continuity clause
        if (SensorValue[buttonToMove] == 0) {         // should be 1 when button is pressed according to documentation
            moveForward();                            // function, run - wait - run - stop
		    }
        else if (SensorValue(buttonToTurn) == 0) {    // should be ... documentation
            turnRight();                              // function, run - wait - run - stop
		    }
        else {                                        // default mode
            motor[leftMotor] = 0;
            motor[rightMotor] = 0;
        }
    }
}
