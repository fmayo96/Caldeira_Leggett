#pragma once 

#include <complex>
#include "Matrix.h"
#include "utils.h"

using namespace std;

complex<double> diff_x(Matrix& state, double dx, int i, int j);
complex<double> diff_y(Matrix& state, double dy, int i, int j);
complex<double> diff_xx(Matrix& state, double dx, int i, int j);
complex<double> diff_yy(Matrix& state, double dy, int i, int j);


