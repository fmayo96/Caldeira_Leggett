#pragma once 

#include "utils.h"
#include "Matrix.h"
#include <vector>


void time_evol(Matrix& state, std::vector<double>& x, double tf, int Nt);
void RK4_step(Matrix& state, std::vector<double>& x, double dt, Matrix& K1, Matrix& K2, Matrix& K3, Matrix& K4);
void eq_diff(const Matrix& state, std::vector<double>& x, Matrix& K);