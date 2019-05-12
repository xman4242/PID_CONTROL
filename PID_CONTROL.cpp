#include "PID_CONTROL.h"
/*
    How to use:
    The setpoint is the desired reading from your sensor (ie a gyroscope value that reads 90 degrese after a right turn)
    The SensorReading is the current value (ie the current gyroscope value)
    The OutputVar is the Variable to store the output include
    Kp, Ki, and Kd are constants. To set them, see https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops
    MinError is the amount of error that can be tolerated. This needs to be set to avoid error accumulating and causing large turns when small ones are needed.
    MaxOutput is the maximum value of your output variable. (ie a max motor speed when turning)
*/
void PID_CONTROL::runPID(int Setpoint, int SensorReading, int OutputVar, int Kp, int Ki, int Kd, int MinError, int MaxOutput, int MinOutput)
{   
    //Read Input and determine error
    ErrorAmt = Setpoint - SensorReading;

    //Calculate New Value 
    //The integral is the area under the curve of graphed values
    //This keeps track of past error and helps prevent smaller errors as it gets closer to the setpoint 
    Integral = Integral + ErrorAmt * DELTA_TIME;

    //The derivative estimates future error from past error changes
    Derivative = (ErrorAmt - PreviousError)/DELTA_TIME;

    //Output the New Value
    OutputVar = (Kp * ErrorAmt) + (Ki * Integral) + (Kd * Derivative);
    if(OutputVar > MaxOutput)
    {
        OutputVar = MaxOutput;
    }
    if(OutputVar < MinOutput)
    {
        OutputVar = MinOutput;
    }
    //Set the previous error, if it is outside of the acceptable parameters
    if(ErrorAmt < MinError)
    {
        PreviousError = 0;
    }
    else
    {
        PreviousError = ErrorAmt;
    }
}