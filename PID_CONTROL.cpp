#include "PID_CONTROL.h"
/*
    How to use:
    The setpoint is the desired reading from your sensor (ie a gyroscope value that reads 90 degrese after a right turn)
    The SensorReading is the current value (ie the current gyroscope value)
    The OutputVar is the Variable to store or write the output
    Kp, Ki, and Kd are constants. To set them, see https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops
    MinError is the amount of error that can be tolerated. This needs to be set to avoid error accumulating and causing large response when small ones are needed.
    MaxOutput is the maximum value of your output variable. (ie a max motor speed)
    MinOutput is assumed to be the opposite of your max output 
*/
void PID_CONTROL::PIDLoop(int &Setpoint, int &SensorReading, int Kp, int Ki, int Kd, int MinError, int MaxOutput, int MinOutput)
{   
    //Read Input and determine the amount error
    ErrorAmt = Setpoint - SensorReading;
 
    //The integral is the area under the curve of graphed values
    //This keeps track of past error and helps prevent smaller errors as it gets closer to the setpoint 
    Integral = Integral + ErrorAmt * DELTA_TIME;

    //The derivative estimates future error from past error changes
    Derivative = (SensorReading - PreviousSensorReading)/DELTA_TIME;

    //Output the New Value, ensuring it is inside of the possible values
    Output = (Kp * ErrorAmt) + (Ki * Integral) + (Kd * Derivative);

    if(Output > MaxOutput)
    {
        Output = MaxOutput;
    }
    if(Output < MinOutput)
    {
        Output = MinOutput;
    }
     
    

    //Ensure the Integral does not grow massive from a small, consistent error
    if(Integral < MinIntegralVal)
    {
        Integral = 0;
    }

    //Set the previous error, if it need to be set because it is outside of the acceptable parameters
    if(ErrorAmt < MinError)
    {
        PreviousError = 0;
    }

    else
    {
        PreviousError = ErrorAmt;
    }

    PreviousSensorReading = SensorReading;
}
/*How to use: This is a P (Proportional) loop only. This is used when a full PID or PI loop is unnessescary. 
    The setpoint is the desired reading from your sensor (ie a gyroscope value that reads 90 degrese after a right turn)
    The SensorReading is the current value (ie the current gyroscope value)
    The OutputVar is the variable to store the output 
    Kp is a constant. To set it, see https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops
    MinError is the amount of error that can be tolerated. This needs to be set to avoid error accumulating and causing large adjustments when small ones are needed.
    MaxOutput is the maximum value of your output variable. (ie a max motor speed)
    MinOutput is assumed to be the opposite of your max output
*/
void PID_CONTROL::PLoop(int Setpoint, int SensorReading, int OutputVar, int Kp, int MinError, int MaxOutput, int MinOutput)
{   
    ErrorAmt = Setpoint - SensorReading;
    OutputVar = (Kp*ErrorAmt)+Setpoint;
}