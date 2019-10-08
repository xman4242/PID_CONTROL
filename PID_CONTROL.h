#ifndef _PID_CONTROL_H_
#define _PID_CONTROL_H_

//Macros
#define DELTA_TIME 20 //Change in time between readings (millis)
#define MinIntegralVal 1 //This sets the minimum integral value. Change if you are having problems with it growing to large
#define ErrorPercent .05 //This is the percentage around the setpoint it will check for completion. Do not change unless you know what you are doing!


class PID_CONTROL
{
//The loop does not automatically time itself, it needs to be put into some kind of timer

public:
//Vars
int ErrorAmt = 0;
int Integral = 0;
int Derivative = 0;
int Output = 0;
int PreviousError = 0;
int PreviousSensorReading = 0;
int Kp = 0;
int Ki = 0;
int Kd = 0;

//Functions
void PIDLoop(int &Setpoint, int &SensorReading, int Kp, int Ki, int Kd, int MinError, int MaxOutput, int MinOutput);
void PLoop(int Setpoint, int SensorReading, int OutputVar, int Kp, int MinError, int MaxOutput, int MinOutput);

private:
  
};

#endif /* _PID_CONTROL_H_ */