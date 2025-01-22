#pragma once 

#include <complex>
#include "Matrix.h"
#include "utils.h"

using namespace std;

complex<double> diff_x(const Matrix& state, double dx, int i, int j);
complex<double> diff_y(const Matrix& state, double dy, int i, int j);
complex<double> diff_xx(const Matrix& state, double dx, int i, int j);
complex<double> diff_yy(const Matrix& state, double dy, int i, int j);


