#include "utils.h"
#include "matrix.h"
#include <cmath>
#include <iostream>
void gaussian_state_coh(Matrix& state, double sigma, double d, double L) {
	//Populates Matrix state with a coherent superposition of two gaussian states.
	// sigma [double]: variance of the gaussians.
	// d [double]: separation of the gaussian centres.
	// L [double]: size of the box containing the system.
	std::vector<double> x = linspace<double>(-L/2.0, L/2.0, state.size());
	double tr, dx = x[1] - x[0];
	
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			state(i, j) = (exp(-pow(x[i] - d / 2.0, 2) / (2 * sigma * sigma))
				+ exp(-pow(x[i] + d / 2.0, 2) / (2 * sigma * sigma)))
				* (exp(-pow(x[j] - d / 2.0, 2) / (2 * sigma * sigma))
					+ exp(-pow(x[j] + d / 2.0, 2) / (2 * sigma * sigma)));
		}
	}
	tr = state.trace();
	
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			state(i, j) /= (tr * dx);
		}
	}
}

void gaussian_state(Matrix& state, double sigma, double d, double L) {
	//Populates Matrix state with a a incoherent superposition of two gaussian states.
	// sigma [double]: variance of the gaussians.
	// d [double]: separation of the gaussian centres.
	// L [double]: size of the box containing the system.
	std::vector<double> x = linspace<double>(-L / 2.0, L / 2.0, state.size());
	double tr, dx = x[1] - x[0];

	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			state(i, j) = exp(-pow(x[i] - d / 2.0, 2) / (2 * sigma * sigma))
				* exp(-pow(x[j] - d / 2.0, 2) / (2 * sigma * sigma))
				+ exp(-pow(x[i] + d / 2.0, 2) / (2 * sigma * sigma))
				* exp(-pow(x[j] + d / 2.0, 2) / (2 * sigma * sigma));
		}
	}
	tr = state.trace();

	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			state(i, j) /= (tr * dx);
		}
	}
}

std::string zero_padd(int num, int len) {
	std::string snum = std::to_string(num);
	if (snum.length() > len) throw std::out_of_range("number is larger than padding length");
	while (snum.length() < len) {
		snum = "0" + snum;
	}
	return snum;
}
