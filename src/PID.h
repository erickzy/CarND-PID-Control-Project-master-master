#ifndef PID_H
#define PID_H
#include <iostream>
using namespace std;

class PID {
public:

	int counter;
	int twiddle_counter;
  /*
  * Errors
  */
  double p_error_;
  double i_error_;
  double d_error_;
  double acumulated_error_;
  double best_acumulated_error_;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double best_Kp;
  double best_Ki;
  double best_Kd;
  double dKp;
  double dKi;
  double dKd;

  /*
  * Output
  */
  double output;

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
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  /*
  * Calculate the PID output.
  */
  double UpdateOutput();

};

#endif /* PID_H */
