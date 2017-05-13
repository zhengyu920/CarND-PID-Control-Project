#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    p_error = 0;
    d_error = 0;
    p_error = 0;
    Kp = 0;
    Ki = 0;
    Kd = 0;
}

PID::~PID() {}

int PID::Init(double Kp, double Ki, double Kd) {
    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;
}

void PID::UpdateError(double cte) {
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::TotalError() {
    return - Kp * p_error - Ki * i_error - Kd * d_error;
}



