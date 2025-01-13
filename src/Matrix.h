#pragma once 

#include <vector>
#include <complex>
#include <fstream>

using namespace std;

class Matrix {
private:
	int dim;
	vector<vector<complex<double>>> elem;
public:
	Matrix(int dim) : dim(dim) {
		elem = vector<vector<complex<double>>>(dim, vector<complex<double>>(dim, 0.0));
	}
	complex<double>& operator()(int i, int j) {
		return elem[i][j];
	}
	int size() const { return dim; }
	void write_bin(std::ofstream& file) const {
		for (auto row = elem.begin(); row != elem.end(); row++) {
			file.write(reinterpret_cast<const char*>(row->data()), row->size() * sizeof(complex<double>));
		}
	}
	double trace() const {
		double tr = 0;
		for (int i = 0; i < dim; i++) {
			tr += elem[i][i].real();
		}
		return tr;
	}
};