#pragma config(Sensor, in1, infraC, sensorReflection)
#pragma config(Sensor, dgtl1, RedLED, sensorDigitalOut)
#pragma config(Sensor, dgtl4, StartButton, sensorDigitalIn)
#pragma config(Sensor, dgtl5, SonarIn, sensorSONAR_cm)
#pragma config(Sensor, dgtl7, GreenLED, sensorDigitalOut)
#pragma config(Sensor, dgtl11, StopButton, sensorDigitalIn)
#pragma config(Motor, port1, leftMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, rightMotor, tmotorVex393_HBridge, openLoop)

const int thresholdSensorValue = 1000; // My Idea --> if robot finds a value greater than the threshold

const int motorSpeed = 50;
int rightMotorSpeed = motorSpeed; // Motor Speed
int leftMotorSpeed = motorSpeed + 5;

int OFF = 0; // Light Source ON
int ON = 1;  // Light Source OFF

bool stopped = false;

void Stop()
{
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}
void moveAround()
{
	motor[leftMotor] = rightMotorSpeed;
	motor[rightMotor] = leftMotorSpeed;
}
task main()
{
	while(1==1) {
		if(SensorValue[StartButton]==0){
			moveAround();}
		if (SensorValue[infraC] < thresholdSensorValue)
		{
			Stop();
			//AllOn()
			//SensorValue(RedLED) = ON;
			return;
		}
	}
}
