const int speed = 125;

// STATES FOR THE MOTOR, OFF IN GENERAL, ON OTHERWISE
// typedef enum
// {
//     MOTOR_OFF = 0,
//     MOTOR_ON
// } state;

// state offState()
// {
//     if (SensorValue(button1) == 1)
//     {
//         motor[motor1] = speed;
//         return (MOTOR_ON);
//     }
//     else
//     {
//         return (MOTOR_OFF);
//     }
// }

// // state OnState()
// // {
// //     if ()
// // }

void 

task main()
{
    // state sys = MOTOR_OFF;
    // state run;
    int timeState = 4200;

    while (true)
    {
        // button1 == the push down button
        if (SensorValue(button1)==1)
            // if time smaller than x time, the motor will go on
            if (time1[T1] < timeState)
            {
                clearTimer(T1);
                motor[motor1] = speed;
            } 
            // if time hits timeState, the motor will stop and rotate
        if (time1[T1] >= timeState)
        {
            wait1Msec(500);
            motor[motor1]=0;
        }
    }
}