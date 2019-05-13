#ifndef _PID_CONTROL_H_
#define _PID_CONTROL_H_

//Macros
#define DELTA_TIME 20 //Change in time between readings (millis)


class PID_CONTROL
{
//The loop does not automatically time itself, it needs to be put into some kind of timer

public:
//Vars
int ErrorAmt = 0;
int Integral = 0;
int Derivative = 0;
int PreviousError = 0;
int Kp = 0;
int Ki = 0;
int Kd = 0;

//Functions
void PIDLoop(int Setpoint, int SensorReading, int OutputVar, int Kp, int Ki, int Kd, int MinError, int MaxOutput, int MinOutput);
void PLoop(int Setpoint, int SensorReading, int OutputVar, int Kp, int MinError, int MaxOutput, int MinOutput);

private:
  
};

#endif /* _PID_CONTROL_H_ */