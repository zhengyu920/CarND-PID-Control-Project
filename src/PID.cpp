#include "PID.h"


//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    i_error = 0;
    p_error = 0;
    d_error = 0;
    pre_time = 0;
    Kp = 0;
    Ki = 0;
    Kd = 0;
}

PID::~PID() {}

int PID::Init(double Kp, double Ki, double Kd) {
    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;
    pre_time = std::clock();
}

void PID::UpdateError(double cte) {
    double cur_time = std::clock();
    double dt = (cur_time - pre_time) / CLOCKS_PER_SEC;
    i_error += cte * dt;
    d_error = (cte - p_error) / dt;
    p_error = cte;
    pre_time = cur_time;
}

double PID::TotalError() {
    return - Kp * p_error - Ki * i_error - Kd * d_error;
}

void PID::PrintError() {
  std::cout << "P error: " << p_error << std::endl;
  std::cout << "I error: " << i_error << std::endl;
  std::cout << "D error: " << d_error << std::endl;
  std::cout << "---------" << std::endl;
}



