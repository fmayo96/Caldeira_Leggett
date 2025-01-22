#include "Matrix.h"
#include "time_evol.h"
#include "global.h"
#include "findiff.h"
#include <fstream>
#include <vector>

void time_evol(Matrix& state, std::vector<double>& x, double tf, int Nt) {
	Matrix K1(state.size()), K2(state.size()), K3(state.size()), K4(state.size());
	double dt = tf / (Nt - 1);
	for (int i = 0; i < Nt; i++) {
		RK4_step(state, x, dt, K1, K2, K3, K4);
		if (i % WRITE_INTERVAL == 0) {
			std::ofstream file("state_"+zero_padd(i/WRITE_INTERVAL, 4)+".out", std::ios::binary);
			state.write_bin(file);
			file.close();
		}
	}
}

void RK4_step(Matrix& state, std::vector<double>& x, double dt, Matrix& K1, Matrix& K2, Matrix& K3, Matrix& K4) {
	eq_diff(state, x, K1);
	eq_diff(state + dt/2.0 * K1, x, K2);
	eq_diff(state + dt / 2.0 * K2, x, K3);
	eq_diff(state + dt * K3, x, K4);
	state = state + dt / 6.0 * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
}

static void eq_diff(const Matrix& state, std::vector<double>& x, Matrix& K) {
	double dx = x[1] - x[0]; 
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			K(i, j) = I / 2.0 * (diff_xx(state, dx, i, j) - diff_yy(state, dx, i, j))
			- gamma * (x[i] - x[j]) * (diff_x(state, dx, i, j) - diff_y(state, dx, i, j))
			-2 * T * pow(x[i]-x[j], 2);
		}
	}
}