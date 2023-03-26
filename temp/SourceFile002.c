#pragma config(Sensor, in1, infraC, sensorReflection)
#pragma config(Sensor, dgtl1, RedLED, sensorDigitalOut)
#pragma config(Sensor, dgtl4, BB, sensorDigitalIn)
#pragma config(Sensor, dgtl6, SonarIn, sensorSONAR_cm)
#pragma config(Sensor, dgtl11, BA, sensorDigitalIn)
#pragma config(Motor, port1, leftMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, rightMotor, tmotorVex393_HBridge, openLoop)

int motorSpeed = 30;
int rightMotorSpeed = motorSpeed; // Motor Speed
int leftMotorSpeed = motorSpeed + 5;

int OFF = 0; // Light Source ON
int ON = 1;  // Light Source OFF

void SourceDetectionSignal()
{
    SensorValue(RedLED) = ON;
    wait1Msec(350);
    SensorValue(RedLED) = OFF;
    wait1Msec(350);
    SensorValue(RedLED) = ON;
    wait1Msec(350);
    SensorValue(RedLED) = OFF;
}

void NoSourceDetectionSignal()
{
    while (1 == 1)
    {
        SensorValue(RedLED) = ON;
        wait1Msec(1000);
        SensorValue(RedLED) = OFF;
        wait1Msec(1000);
        SensorValue(RedLED) = ON;
        wait1Msec(1000);
        SensorValue(RedLED) = OFF;
        wait1Msec(1000);
        if (SensorValue[buttonToMove]==0) {break;}
    }
    return;
}

void moveBack()
{
    motor[rightMotor] = -rightMotorSpeed;
    motor[leftMotor] = leftMotorSpeed;
}

void moveTo()
{
    motor[rightMotor] = rightMotorSpeed+10;
    motor[leftMotor] = -leftMotorSpeed-10;
}

void moveAround()
{
    motor[leftMotor] = rightMotorSpeed;
    motor[rightMotor] = leftMotorSpeed;
}

void Stop()
{
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
}

void lookingForSource()
{
   // clearTimer(T1);
    SensorValue(RedLED) = OFF;
    while (1 == 1)
    {
        //if (SensorValue[BB] == 0) {Stop();break;}
        //if (time1[T1]>=5000) {
            //clearTimer(T1);
            //while (time1[T1]<=1000) {
                moveTo();
                if ((SensorValue[SonarIn] <= 30) && (SensorValue[SonarIn] != -1))
                {
                    moveBack();
                }
            }
            clearTimer(T1);
        }
        if ((time1[T1]<5000)&&(SensorValue[SonarIn] > 10))
        {
            moveAround();
        }
        else if ((time1[T1]<5000)&&(SensorValue[SonarIn] <= 30)&&(SensorValue[SonarIn] != -1))
        {
            moveBack();
            wait1Msec(500);
        }
        // if (SensorValue[infraC] > thresholdSensorValue)
        // {
        //     SensorValue(RedLED) = ON;
        //     return;
        // }
    }
}

void moveToSource()
{
    while (SensorValue[SonarIn]>5)
    {
        if (SensorValue[buttonToTurn] == 0) {Stop();break;}
        moveTo();
    }
    if (SensorValue[SonarIn]<5) {Stop();}
    return;
}

task main()
{
    SourceDetectionSignal();
    while (1==1) {
        if (SensorValue[buttonToMove] == 0)
        {
            while(1==1)
            {
                lookingForSource();
                moveToSource();
                NoSourceDetectionSignal();
            }
        }
    }
}
task main()
{



}
