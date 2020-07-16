#include <cmath>
#include <cstdio>
#include <iostream>

#include "pid.hpp"

using namespace std;

PID::PID(double Kp, double Ki, double Kd, double threshold) {
    this->kp = Kp;
    this->ki = Ki;
    this->kd = Kd;
    this->thres = threshold;
    this->error = 0;
    this->preInput = 0;
    this->integral = 0;
}

PID::~PID() {}

PID::PID(const std::string cfg) {}
void PID::init() {
    this->error = 0;
    this->preInput = 0;
    this->integral = 0;
}

double* PID::pidXY(double x, double y, double offset) {
    double result;
    double* out = new double[2];

    result = pidCtrl(sqrt((x * x) + (y * y)), offset);

    // cout << x << endl << y << endl;
    // cout <<"$$$$$"<<result<<"$$$$$"<< endl;

    out[0] = result * cos(atan2(y, x));
    out[1] = result * sin(atan2(y, x));

    return out;
}

double PID::pidCtrl(double input, double offset) {
    double newError;
    double P;
    double I;
    double D;
    double result;

    // cout <<"######"<< input <<"##########"<<endl;

    newError = input;
    // newError = input - this-> preInput;
    integral = integral + newError;

    P = (input - thres) * this->kp;
    I = integral * this->ki;
    D = (newError - error) * this->kd;

    error = newError;
    preInput = input;

    result = P + I + D + offset;
    // cout << result << "\n" << endl;
    return result;
}
