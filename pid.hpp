#pragma once


class PID
{
public:
    //member function
    PID(double Kp, double Ki, double Kd, double threshold);
    ~PID();
    void init(); //set error & preInput to 0
    double pidXY(double x, double y, double minSpeed);  //pid in 2D help you to use easily
    double pidCtrl(double input, double minSpeed);  //pid as you known

private:
    //member variale
    double error;
    double preInput;
    double kp;
    double ki;
    double kd;
    double thres;

};

