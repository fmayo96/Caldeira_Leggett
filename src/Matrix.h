#pragma once 

#include <vector>
#include <complex>
#include <fstream>
#include <iostream>

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
	complex<double> operator()(int i, int j) const {
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
	Matrix operator+(const Matrix& other) {
		if (dim != other.size()) throw invalid_argument("Matrices must have the same dimension for addition.");
		Matrix res(dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				res(i, j) = this->elem[i][j] + other.elem[i][j];
			}
		}
		return res;
	}
	void print() const {
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				cout << elem[i][j] << " ";
			}
			cout << "\n";
		}
	}
	friend Matrix operator*(complex<double> x, const Matrix& M) {
		Matrix res(M.size());
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M.size(); j++) {
				res(i, j) = x * M(i, j);
			}
		}
		return res;
	}
};

