#pragma once

#include <vector>
#include <string>
#include "Matrix.h"

template<typename T>
std::vector<T> linspace(T start, T end, int len) {
	std::vector<T> lin(len, 0.0);
	for (int i = 0; i < len; i++) {
		lin[i] = (end - start) * static_cast<T>(i) / (len - 1) + start;
	}
	return lin;
}

void gaussian_state_coh(Matrix& state, double sigma, double d, double L);
void gaussian_state(Matrix& state, double sigma, double d, double L);
std::string zero_padd(int num, int len);
