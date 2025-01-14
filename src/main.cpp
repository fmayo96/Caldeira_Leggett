// Caldeira_Leggett.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <complex>
#include <vector>
#include "Matrix.h"
#include "utils.h"


using namespace std;

const complex<double> I(0, 1);

int main()
{ 
	double tf = 10.0;
	int Nt = 1000;
	int dim = 1 << 10;
	double sigma = 0.25, d = 1.0, L = 10.0;
	Matrix state(dim);
	gaussian_state(state, sigma, d, L);

	ofstream my_file("test.out", ios::binary);
	state.write_bin(my_file);
	my_file.close();
	return 0;
}
 