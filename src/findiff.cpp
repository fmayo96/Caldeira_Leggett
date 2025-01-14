#include "findiff.h"

using namespace std;
const int num_coeff = 5;
const double coeff_first[] = { 1 / 12.0, -2 / 3.0, 0, 2 / 3.0, -1 / 12.0 };
const double coeff_second[] = { -1 / 12.0, 4 / 3.0, -5/2.0, 4 / 3.0, -1 / 12.0 };

complex<double> diff_x(Matrix& state, double dx, int i, int j) {
	// computes the first derivative of state(i,j) with respect to x using centered finite differemces
	// with 4th order accuracy.
	int dim = state.size();
	complex<double> df_dx = 0.0;
	for (int n = 0; n < num_coeff; n++) {
		df_dx += coeff_first[n] * state((i - 2 + n + dim) % dim, j) / dx;
	}
	return df_dx;
}
complex<double> diff_y(Matrix& state, double dy, int i, int j) {
	// computes the first derivative of state(i,j) with respect to y using centered finite differemces
	// with 4th order accuracy.
	int dim = state.size();
	complex<double> df_dy = 0.0;
	for (int n = 0; n < num_coeff; n++) {
		df_dy += coeff_first[n] * state(i, (j - 2 + n + dim) % dim) / dy;
	}
	return df_dy;
}
complex<double> diff_xx(Matrix& state, double dx, int i, int j) {
	// computes the first derivative of state(i,j) with respect to x using centered finite differemces
	// with 4th order accuracy.
	int dim = state.size();
	complex<double> df_dxx = 0.0;
	for (int n = 0; n < num_coeff; n++) {
		df_dxx += coeff_second[n] * state((i - 2 + n + dim) % dim, j) / (dx*dx);
	}
	return df_dxx;
}
complex<double> diff_yy(Matrix& state, double dy, int i, int j) {
	// computes the first derivative of state(i,j) with respect to y using centered finite differemces
	// with 4th order accuracy.
	int dim = state.size();
	complex<double> df_dyy = 0.0;
	for (int n = 0; n < num_coeff; n++) {
		df_dyy += coeff_second[n] * state(i, (j - 2 + n + dim) % dim) / (dy*dy);
	}
	return df_dyy;
}