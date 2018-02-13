#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p_error_ = 0;
	i_error_ = 0;
	d_error_ = 0;
	output = 0;
	acumulated_error_ = 0;
	counter = 0;
	twiddle_counter = 0;
	(*this).Kp = Kp;
	(*this).Ki = Ki;
	(*this).Kd = Kd;
	dKp = 0.2;
	dKi = 0.001;
	dKd = 1;
}

void PID::UpdateError(double cte) {
	i_error_ += cte;
	d_error_ = cte - p_error_;
	p_error_ = cte;
	acumulated_error_ += cte * cte;
	counter += 1;
}

double PID::UpdateOutput() {

	output = -Kp * p_error_ - Kd * d_error_ - Ki * i_error_;

	return output;
}

double PID::TotalError() {

	return acumulated_error_;
}


