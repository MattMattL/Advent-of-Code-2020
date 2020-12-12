#include <iostream>
#include <fstream>
#include <cmath>
#include "../dataHelper.hpp"
#include "./matrix.hpp"

using namespace std;

Data<int> data;

Matrix<double> setMatrix()
{
	Matrix<double> matrix(data.size(), data.size());

	matrix.setToZero();

	for(int i=0; i<matrix.rows(); i++)
	{
		for(int j=0; j<i; j++)
		{
			if(0 <= data.at(i) - data.at(j) && data.at(i) - data.at(j) <= 3)
				matrix.set(i, j, 1);
		}
	}

	matrix.print();

	return matrix;
}

bool isZero(Matrix<double> matrix)
{
	for(int i=0; i<matrix.rows(); i++)
	{
		for(int j=0; j<matrix.cols(); j++)
		{
			if(matrix.get(i, j))
				return false;
		}
	}

	return true;
}

void calculateSeries(Matrix<double> A)
{
	// calculate B = 1 + A + A^2 + A^3 +...

	Matrix<double> B(data.size(), data.size());
	Matrix<double> I(data.size(), data.size());

	B.setToZero();
	I.setToIdentity();

	B = B + I;

	while(!isZero(A))
	// for(int i=0; i<10; i++)
	{
		B = B + A;
		A = A * A;

		A.print();
		B.print();

		cout << endl;
	}
}

int main()
{
	data.read("./data.txt");
	data.sort();

	data.add_front(0);
	data.add_back(data.at(data.size() - 1) + 3);

	Matrix<double> A = setMatrix(); // Adjacency matrix

	calculateSeries(A);

	return 0;
}