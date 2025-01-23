#include <iostream>
#include <complex>
#include <vector>
#include "Matrix.h"
#include "utils.h"
#include "time_evol.h"


using namespace std;

const complex<double> I(0, 1);

int main() { 
	double tf = 10.0;
	int Nt = 1000;
	int dim = 256;
	double sigma = 0.25, d = 1.0, L = 10.0;
	Matrix state(dim);
	vector<double> x = linspace(-L / 2.0, L / 2.0, dim);
	gaussian_state_coh(state, sigma, d, L);
	time_evol(state, x, tf, Nt);
	return 0;
}
 