#ifndef _PID_CONTROL_H_
#define _PID_CONTROL_H_

class PID_CONTROL
{

public:
//Vars
int ErrorNum = 0;
int Integral = 0;
int Derivative = 0;
int PreviousError = 0;
int FinalOutput = 0;
//Functions
void runPID(int Setpoint, int To_Set, int SensorInput, int Kp, int Ki, int Kd, bool Reversed);

private:
  
};

#endif /* _PID_CONTROL_H_ */