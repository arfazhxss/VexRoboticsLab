#pragma config(Sensor, in1,    infraC,         sensorReflection)
#pragma config(Sensor, in2,    InfraC2,        sensorAnalog)
#pragma config(Sensor, dgtl1,  RedLED,         sensorDigitalOut)
#pragma config(Sensor, dgtl4,  buttonToMove,   sensorDigitalIn)
#pragma config(Sensor, dgtl7,  SonarIn,        sensorSONAR_cm)
#pragma config(Sensor, dgtl11, buttonToTurn,   sensorDigitalIn)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
task main()
{
while(SensorValue(infraC)<100){
	SensorValue(RedLED)=1;
	//wait1Msec(1000);
	}
//while(sensorvalue(infraC)>100){




}
