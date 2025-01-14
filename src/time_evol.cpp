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

}

void eq_diff(Matrix& state, std::vector<double>& x) {

}