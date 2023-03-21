#pragma config(Sensor, in1,    infraC,         sensorReflection)
#pragma config(Sensor, dgtl1,  RedLED,         sensorDigitalOut)
#pragma config(Sensor, dgtl4,  buttonToMove,   sensorDigitalIn)
#pragma config(Sensor, dgtl5,  SonarIn,        sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  GreenLED,       sensorDigitalOut)
#pragma config(Sensor, dgtl11, buttonToTurn,   sensorDigitalIn)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
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
const int thresholdSensorValue = 1000; // My Idea --> if robot finds a value greater than the threshold

const int motorSpeed = 30;
int rightMotorSpeed = motorSpeed; // Motor Speed
int leftMotorSpeed = motorSpeed + 5;

int OFF = 0; // Light Source ON
int ON = 1;  // Light Source OFF

void firstSignalTest()
{
    SensorValue(RedLED) = ON;
    wait1Msec(1000);
    SensorValue(GreenLED) = ON;
    wait1Msec(1000);
    SensorValue(RedLED) = OFF;
    wait1Msec(1000);
    SensorValue(GreenLED) = OFF;
    wait1Msec(1000);
}

void SourceDetectionSignal()
{
    SensorValue(RedLED) = ON;
    wait1Msec(350);
    SensorValue(RedLED) = OFF;
    wait1Msec(350);
    SensorValue(RedLED) = ON;
    wait1Msec(350);
    SensorValue(RedLED) = OFF;
    wait1Msec(350);
    SensorValue(RedLED) = ON;
}

void TargetFixed()
{
    SensorValue(GreenLED) = ON;
    //SensorValue(RedLED) = ON;
    return;
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
        if (SensorValue[buttonToMove] == 0)
        {
            break;
        }
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
    motor[rightMotor] = rightMotorSpeed + 10;
    motor[leftMotor] = -leftMotorSpeed - 10;
}

void moveAround()
{
    motor[leftMotor] = rightMotorSpeed;
    motor[rightMotor] = leftMotorSpeed;
}

void moveAroundBack()
{
	clearTimer(T1);
	while (time1[T1] <= 200)
  {
		moveAround();
  }

}

void Stop()
{
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
}

void lookingForSource()
{
    clearTimer(T1);
    SensorValue(RedLED) = OFF;
    SensorValue(GreenLED) = OFF;
    while (1 == 1)
    {
        if (SensorValue[infraC] < thresholdSensorValue)
        {
            Stop();
            SensorValue(RedLED) = ON;
            break;
        }
        if (SensorValue[buttonToTurn] == 0)
        {
            Stop();
            break;
        }
        if (time1[T1] >= 5000)
        {
            clearTimer(T1);
            while (time1[T1] <= 200)
            {
                moveTo();
                if ((SensorValue[SonarIn] <= 50) && (SensorValue[SonarIn] != -1))
                {
                    moveBack();
                    wait1Msec(50);
                }
            }
            clearTimer(T1);
        }
        else if (SensorValue[SonarIn] > 10)
        {
            moveAround();
        }
        else if ((SensorValue[SonarIn] <= 50) && (SensorValue[SonarIn] != -1))
        {
            moveAroundBack();
            //moveBack();
        }
    }
    return;
}

void moveToSource()
{
    while (SensorValue[SonarIn] > 5)
    {
        if (SensorValue[buttonToTurn] == 0)
        {
            Stop();
            break;
        }
        moveTo();
    }
    if (SensorValue[SonarIn] < 5)
    {
        SensorValue[RedLED] = ON;
        Stop();
        TargetFixed();
        return;
    }
}

task main()
{
    firstSignalTest();
    while (1 == 1)
    {
        if (SensorValue[buttonToMove] == 0)
        {
            while (1 == 1)
            {
                // NoSourceDetectionSignal();
                lookingForSource();
                moveToSource();
                //SourceDetectionSignal();
                //NoSourceDetectionSignal();
            }
        }
    }
}
