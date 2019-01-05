#include<cstdio>
#include<cmath>
#include <iostream>

#include "pid.hpp"

using namespace std;

PID::PID(double Kp, double Ki, double Kd, double threshold)
{
    this-> kp = Kp;
    this-> ki = Ki;
    this-> kd = kd;
    this-> thres = threshold;
    this-> error = 0;
}

void PID::init()
{
    this-> error = 0;
}

double PID::pidXY(double x, double y, double offset)
{
    double result;
    result = pidCtrl(sqrt((x*x) + (y*y)), offset);
    return result;
}

double PID::pidCtrl(double input, double offset)
{
    double newError;
    double P;
    double I;
    double D;
    double result;

    newError = input - this-> preInput;

    P = (input-thres)* this-> kp;
    I = (newError + error)* this->ki;
    D = (newError - error)* this-> kd;

    error = newError;
    preInput = input;
    
    result = P + I + D + offset;
    cout << result << "\n" << endl;
    return result; 
}
