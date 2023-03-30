#pragma config(Sensor, in1, infraC, sensorReflection)
#pragma config(Sensor, dgtl1, RedLED, sensorDigitalOut)
#pragma config(Sensor, dgtl4, StopButton, sensorDigitalIn)
#pragma config(Sensor, dgtl5, SonarIn, sensorSONAR_cm)
#pragma config(Sensor, dgtl7, GreenLED, sensorDigitalOut)
#pragma config(Sensor, dgtl9, LimitSwitchR, sensorDigitalIn)
#pragma config(Sensor, dgtl10, LimitSwitchL, sensorDigitalIn)
#pragma config(Sensor, dgtl11, StartButton, sensorDigitalIn)
#pragma config(Motor, port2, upperMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port1, rightMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, leftMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// const int thresholdSensorValue = 1000; // My Idea --> if robot finds a value greater than the threshold

const int motorSpeed = 50;
int rightMotorSpeed = motorSpeed; // Motor Speed
int leftMotorSpeed = motorSpeed;
const int thresholdSensorValue = 1000;

//int OFF = 0; // Light Source ON
int ON = 1;  // Light Source OFF
//int timeConstant = 1500;
// bool stopped = false;

void Stop()
{
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
}
void moveAround()
{
    motor[leftMotor] = rightMotorSpeed;
    motor[rightMotor] = -leftMotorSpeed;
}
void moveTo()
{
    motor[rightMotor] = rightMotorSpeed;
    motor[leftMotor] = leftMotorSpeed;
}
void moveToSlow()
{
    motor[rightMotor] = rightMotorSpeed - 20;
    motor[leftMotor] = leftMotorSpeed - 20;
}
void moveAroundSlowRight1()
{
    motor[rightMotor] = -rightMotorSpeed + 20;
    motor[leftMotor] = leftMotorSpeed - 20;
    wait1Msec(250);
}
void moveAroundSlowLeft1()
{
    motor[rightMotor] = +rightMotorSpeed - 20;
    motor[leftMotor] = -leftMotorSpeed + 20;
    wait1Msec(250);
}
// void moveAroundSlowRight_OBJ_PLACEMENT()
// {
//     motor[rightMotor] = -rightMotorSpeed + 20;
//     motor[leftMotor] = +leftMotorSpeed - 20;
//     wait1Msec(250);
// }
// void moveBack()
// {
//     motor[rightMotor] = -rightMotorSpeed;
//     motor[leftMotor] = -leftMotorSpeed;
// }
void moveBack60()
{
    motor[rightMotor] = -rightMotorSpeed;
    motor[leftMotor] = -leftMotorSpeed;
    wait1Msec(1000);
    Stop();
}
void objectPlacement()
{
    /*MAIN*/
    motor[upperMotor] = -15;
    wait1Msec(1500);
    motor[upperMotor] = 0;
}
void objectPlacementReverse()
{
    /*MAIN*/
    motor[upperMotor] = 15;
    wait1Msec(1500);
    motor[upperMotor] = 0;
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// void objectPlacementReverse()
//{
/*MAIN*/
//    motor[upperMotor] = -motorSpeed;
//    wait1Msec(timeConstant);
//}
int smallestSignal(int SignalOne, int SignalTwo, int SignalThree, int SignalFour, int SignalFive)
{
    int smallest = SignalThree;

    if (SignalOne <= smallest)
    {
        smallest = SignalTwo;
    }

    if (SignalTwo <= smallest)
    {
        smallest = SignalThree;
    }

    if (SignalFour <= smallest)
    {
        smallest = SignalFour;
    }

    if (SignalFive <= smallest)
    {
        smallest = SignalFive;
    }

    return smallest;
}
void signalCheck5() {
    while (1 == 1) // re-align
    {
        // take signal 0
        int sensorValue1 = SensorValue[infraC];
        wait1Msec(51);
        int sensorValue2 = SensorValue[infraC];
        int signalMain = min(sensorValue1, sensorValue2);

        // take signal -1
        moveAroundSlowRight1();
        sensorValue1 = SensorValue[infraC];
        wait1Msec(51);
        sensorValue2 = SensorValue[infraC];
        int signalRightOne = min(sensorValue1, sensorValue2);

        // take signal -2
        moveAroundSlowRight1();
        sensorValue1 = SensorValue[infraC];
        wait1Msec(51);
        sensorValue2 = SensorValue[infraC];
        int signalRightTwo = min(sensorValue1, sensorValue2);

        // take signal 1
        moveAroundSlowLeft1();
        moveAroundSlowLeft1();
        moveAroundSlowLeft1();
        sensorValue1 = SensorValue[infraC];
        wait1Msec(51);
        sensorValue2 = SensorValue[infraC];
        int signalLeftOne = min(sensorValue1, sensorValue2);

        // take signal 2
        moveAroundSlowLeft1();
        sensorValue1 = SensorValue[infraC];
        wait1Msec(51);
        sensorValue2 = SensorValue[infraC];
        int signalLeftTwo = min(sensorValue1, sensorValue2);

        // now move to 0
        moveAroundSlowRight1();
        moveAroundSlowRight1();

        // calculate the smallest signal
        int signal = smallestSignal(signalRightOne, signalRightTwo, signalMain, signalLeftOne, signalLeftTwo);
        if (signal == signalRightOne)
        {
            moveAroundSlowRight1();
            break;
        }
        if (signal == signalRightTwo)
        {
            moveAroundSlowRight1();
            moveAroundSlowRight1();
            break;
        }
        if (signal == signalLeftOne)
        {
            moveAroundSlowLeft1();
            break;
        }
        if (signal == signalLeftTwo)
        {
            moveAroundSlowLeft1();
            moveAroundSlowLeft1();
            break;
        }
        if (signal == signalMain)
        {
            break;
        }
    }
    return;
}

task main()
{
    int sensorValue1 = 0;
    int sensorValue2 = 0;
    int sensorValue3 = 0;
    int sensorValue4 = 0;
    while (1 == 1)
    {
        if (SensorValue[StartButton] == 0)
        {
            while (1 == 1) // spin around find target
            {
                moveAround();
                int sensorValue1 = 0;
                int sensorValue2 = 0;
                sensorValue1 = SensorValue[infraC];
                wait1Msec(51);
                sensorValue2 = SensorValue[infraC];
                int signal = min(sensorValue1, sensorValue2);
                if (signal < thresholdSensorValue)
                {
                    // SensorValue(RedLED) = ON;
                    Stop();
                    wait1Msec(1000); // test
                    break;
                }
            }
            // move to target till off path
            while ((((SensorValue[SonarIn] > 80) && (SensorValue[SonarIn] != -1))))
            //||((SensorValue[LimitSwitchR] == 0) || (SensorValue[LimitSwitchL] == 0))
            {
                moveTo();
            }
            Stop();
            wait1Msec(1000);
            signalCheck5();
            // move to target till off path
            while ((((SensorValue[SonarIn] > 50) && (SensorValue[SonarIn] != -1))))
            //||((SensorValue[LimitSwitchR] == 0) || (SensorValue[LimitSwitchL] == 0))
            {
                moveTo();
            }
            Stop();
            wait1Msec(1000);
            while (1 == 1) // re-align
            {
                // take signal 0
                sensorValue1 = SensorValue[infraC];
                wait1Msec(51);
                sensorValue2 = SensorValue[infraC];
                int signalMain = min(sensorValue1, sensorValue2);

                // take signal -1
                moveAroundSlowRight1();
                sensorValue1 = SensorValue[infraC];
                wait1Msec(51);
                sensorValue2 = SensorValue[infraC];
                int signalRightOne = min(sensorValue1, sensorValue2);

                // take signal -2
                moveAroundSlowRight1();
                sensorValue1 = SensorValue[infraC];
                wait1Msec(51);
                sensorValue2 = SensorValue[infraC];
                int signalRightTwo = min(sensorValue1, sensorValue2);

                // take signal 1
                moveAroundSlowLeft1();
                moveAroundSlowLeft1();
                moveAroundSlowLeft1();
                sensorValue1 = SensorValue[infraC];
                wait1Msec(51);
                sensorValue2 = SensorValue[infraC];
                int signalLeftOne = min(sensorValue1, sensorValue2);

                // take signal 2
                moveAroundSlowLeft1();
                sensorValue1 = SensorValue[infraC];
                wait1Msec(51);
                sensorValue2 = SensorValue[infraC];
                int signalLeftTwo = min(sensorValue1, sensorValue2);

                // now move to 0
                moveAroundSlowRight1();
                moveAroundSlowRight1();

                // calculate the smallest signal
                int signal = smallestSignal(signalRightOne, signalRightTwo, signalMain, signalLeftOne, signalLeftTwo);
                if (signal == signalRightOne)
                {
                    moveAroundSlowRight1();
                    break;
                }
                if (signal == signalRightTwo)
                {
                    moveAroundSlowRight1();
                    moveAroundSlowRight1();
                    break;
                }
                if (signal == signalLeftOne)
                {
                    moveAroundSlowLeft1();
                    break;
                }
                if (signal == signalLeftTwo)
                {
                    moveAroundSlowLeft1();
                    moveAroundSlowLeft1();
                    break;
                }
                if (signal == signalMain)
                {
                    break;
                }
            }
            while (1 == 1) // go to target
            {
                moveToSlow();
                int sensorValue1 = SensorValue[SonarIn];
                if ((sensorValue1 <= 3) && (sensorValue1 != -1))
                {
                    Stop();
                    break;
                }
            }
            //moveAroundSlowRight_OBJ_PLACEMENT();
            objectPlacement();
            objectPlacementReverse();
            Stop();
            wait1Msec(500);
            moveBack60();
            Stop();
            SensorValue(RedLED) = ON;
        }
    }
}
