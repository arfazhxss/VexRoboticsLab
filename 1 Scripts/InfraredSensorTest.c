#pragma config(Sensor, in1, infraC, sensorReflection)
#pragma config(Sensor, in2, InfraC2, sensorAnalog)
#pragma config(Sensor, dgtl1, RedLED, sensorDigitalOut)
#pragma config(Sensor, dgtl4, buttonToMove, sensorDigitalIn)
#pragma config(Sensor, dgtl6, SonarIn, sensorSONAR_cm)
#pragma config(Sensor, dgtl11, buttonToTurn, sensorDigitalIn)
#pragma config(Motor, port1, leftMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, rightMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*************************************************************************
 *
 *
 * Electrical Test 01: IR Sensor Test
 *
 * Breadboard Connected To: Digital Port X (LED Light Signal)
 *                          Analog Port X (PhotoTransistor)
 *
 *
 *************************************************************************/

// Threshold of value read from phototransistor circuit.
// const int thresholdSensorValue = 1000; // My Idea --> if robot finds a value greater than the thresh

// enum programState // States in our Test
// {
//     LookingForSource,
//     FoundSource,
//     MoveToSource,
//     stopTest
// };

const int motorSpeed = 30;
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
    }
}

void moveBack()
{
    motor[rightMotor] = -rightMotorSpeed;
    motor[leftMotor] = leftMotorSpeed;
}

void moveTo()
{
    motor[rightMotor] = rightMotorSpeed;
    motor[leftMotor] = -leftMotorSpeed;
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
    SensorValue(RedLED) = OFF;
    while (1 == 1)
    {
        if (SensorValue[buttonToTurn] == 0) {Stop();break;}
        if (SensorValue[SonarIn] > 10)
        {
            moveAround();
        }
        else if (SensorValue[SonarIn] <= 10)
        {
            moveBack();
        }
        // if (SensorValue[infraC] > thresholdSensorValue)
        if (SensorValue[SonarIn] == 3)
        {
            SensorValue(RedLED) = ON;
            return;
        }
    }
}

void moveToSource()
{
    while (SensorValue[SonarIn]>5)
    {
        if (SensorValue[buttonToTurn] == 0) {Stop();break;}
        moveTo();
    }
    return;
}

task main()
{
    SourceDetectionSignal();
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
