
void waitOnPress()
{
    while{!getButtonPress(buttonAny)}
    {}
    while(getButtonPress(buttonAny))
    {}
}

void rotateBy(int degrees)
{
    sensorValue[S2] = 0;
    motor[motorA] = 25;
    motor[motorD] = -25;
    while(sensorValue[S2] < degrees)
    {}
    motor[motorA] = motor[motorD] = 0;
}

task main()
{
    int const ROBOT_LENGTH = 20;

    displayScreen(1, "Group 21");
    displayScreen(2, "Wednesday");
    displayScreen(3, "4:30");

    SensorType[S1] = sensorEV3_Touch;
    wait1Msec(50);
    SensorType[S2] = sensorEV3_Color;
    wait1Msec(50);
    SensorMode[S2] = modeEV3Color_Color;
    wait1Msec(50);
    SensorType[S3] = sensorEV3_Ultrasonic;
    wait1Msec(50);
    SensorType[S4] = sensorEV3_Gyro;
    wait1Msec(50);

    waitOnPress();

    motor[motorA] = motor[motorD] = 30;
    while(sensorValue[S2] != (int)colorRed)
    {}
    wait1Msec(50);
    rotateBy(90);
    motor[motorA] = motor[motorD] = 20;
    while(sensorValue[S1]==0)
    {
        if(sensorValue[S3]<100+ROBOT_LENGTH)
        {
            rotateBy(180);
            rotateBy(180);
        }
    }
    motor[motorA] = motor[motorD] = 0;
}
