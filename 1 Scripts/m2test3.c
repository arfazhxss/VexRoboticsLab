#pragma config(Sensor, in1,    infraC,         sensorReflection)
#pragma config(Sensor, dgtl1,  RedLED,         sensorDigitalOut)
#pragma config(Sensor, dgtl4,  StopButton,     sensorDigitalIn)
#pragma config(Sensor, dgtl5,  SonarIn,        sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  GreenLED,       sensorDigitalOut)
#pragma config(Sensor, dgtl11, StartButton,    sensorDigitalIn)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//const int thresholdSensorValue = 1000; // My Idea --> if robot finds a value greater than the threshold

const int motorSpeed = 50;
int rightMotorSpeed = motorSpeed+5; // Motor Speed
int leftMotorSpeed = motorSpeed;

// int OFF = 0; // Light Source ON
// int ON = 1;  // Light Source OFF

// bool stopped = false;

void moveAround()
{
    motor[leftMotor] = rightMotorSpeed;
    motor[rightMotor] = -leftMotorSpeed;
}
void moveTo()
{
    motor[rightMotor] = rightMotorSpeed + 10;
    motor[leftMotor] = leftMotorSpeed - 10;
}
void moveBack()
{
    motor[rightMotor] = -rightMotorSpeed;
    motor[leftMotor] = -leftMotorSpeed;
}
task main()
{
    while (1 == 1)
    {
        if (SensorValue[StartButton] == 0)
        {
            clearTimer(T1);
            while (1 == 1)
            {
                if (time1[T1] >= 3000)
                {
                    clearTimer(T1); // Time is 0 now
                    while (time1[T1] < 3000)
                    {
                        moveTo();
                        if ((SensorValue[SonarIn] <= 50) && (SensorValue[SonarIn] != -1))
                        {
                            moveBack();
                            wait1Msec(1000);
                            moveAround();
                            wait1Msec(2000);
                        }
                    }
                    clearTimer(T1); // Time is 0 now
                }
            }
        }
    }
}
