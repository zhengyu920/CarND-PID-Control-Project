#ifndef PID_H
#define PID_H

#include <vector>
#include <ctime>
#include <iostream>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double pre_time;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;



  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  int Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void PrintError();


};

#endif /* PID_H */
