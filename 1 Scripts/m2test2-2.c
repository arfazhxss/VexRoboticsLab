#pragma config(Sensor, in1, infraC, sensorReflection)
#pragma config(Sensor, dgtl1, RedLED, sensorDigitalOut)
#pragma config(Sensor, dgtl4, StartButton, sensorDigitalIn)
#pragma config(Sensor, dgtl5, SonarIn, sensorSONAR_cm)
#pragma config(Sensor, dgtl7, GreenLED, sensorDigitalOut)
#pragma config(Sensor, dgtl11, StopButton, sensorDigitalIn)
#pragma config(Motor, port1, rightMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, leftMotor, tmotorVex393_HBridge, openLoop)
task main()
{

	while (1==1)
	{
		if (SensorValue(SonarIn)<4)
		{
			SensorValue[RedLED]=1;
			wait1Msec(50);
		} else {
			SensorValue[RedLED]=0;
			wait1Msec(50);
		}
	}

}
