#include "PID_CONTROL.h"

void PID_CONTROL::runPID(int Setpoint, int To_Set, int SensorInput, int Kp, int Ki, int Kd, bool Reversed)
{
    //Read Output
    ErrorNum = Setpoint - SensorInput;
    //Calculate New Value 
    Integral = Integral + ErrorNum * 20;
    Derivative = (ErrorNum - PreviousError)/20;
    //Output the New Value
    FinalOutput = Kp * ErrorNum + Ki * Integral + Kd * Derivative;
    //Set the previous error
    PreviousError = ErrorNum;
}