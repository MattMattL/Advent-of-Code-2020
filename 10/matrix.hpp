#include <iostream>

using namespace std;

template <class T>
class Matrix
{
private:
	T **matrix;

	int ROWS, COLS;
	
public:
	Matrix();
	Matrix(int, int);
	~Matrix();

	// Initialisation
	void setTo(T);
	void setToZero();
	void setToIdentity();

	// Arithmetic Operation
	Matrix<T> operator + (Matrix);
	Matrix<T> operator * (T);
	Matrix<T> operator * (Matrix);

	// Entry Manipulation
	T get(int, int);
	void set(int, int, T);
	T* at(int, int);

	// Utility
	int rows();
	int cols();
	void print();
};

template <class T>
Matrix<T>::Matrix()
{

}

template <class T>
Matrix<T>::Matrix(int rows, int cols) : ROWS(rows), COLS(cols)
{
	// ROWS = rows;
	// COLS = cols;

	matrix = new T*[ROWS];

	for(int i=0; i<ROWS; i++)
		matrix[i] = new T[COLS];
}

template <class T>
Matrix<T>::~Matrix()
{
	// for(int i=0; i<ROWS; i++)
		// delete matrix[i];

	// delete matrix;
}


/* Initialisation */

template <class T>
void Matrix<T>::setTo(T value)
{
	for(int i=0; i<ROWS; i++)
		for(int j=0; j<COLS; j++)
			matrix[i][j] = value;
}

template <class T>
void Matrix<T>::setToZero()
{
	for(int i=0; i<ROWS; i++)
		for(int j=0; j<COLS; j++)
			matrix[i][j] = 0;
}

template <class T>
void Matrix<T>::setToIdentity()
{
	for(int i=0; i<ROWS; i++)
		for(int j=0; j<COLS; j++)
			matrix[i][j] = (i == j)? 1 : 0;
}


/* Arithmetic Operation */

template <class T>
Matrix<T> Matrix<T>::operator + (Matrix mtx)
{
	Matrix<T> result(rows(), cols());

	if(rows() != mtx.rows() || cols() != mtx.cols())
	{
		cout << "[error] Matrix<?>::operator +" << endl;

		result.setToZero();
		return result;
	}

	for(int i=0; i<result.rows(); i++)
		for(int j=0; j<result.cols(); j++)
			result.set(i, j, get(i, j) + mtx.get(i, j));

	return result;
}

template <class T>
Matrix<T> Matrix<T>::operator * (T factor)
{
	Matrix<T> result(rows(), cols());

	for(int i=0; i<result.rows(); i++)
		for(int j=0; j<result.cols(); j++)
			result.set(i, j, factor * get(i, j));

	return result;
}

template <class T>
Matrix<T> Matrix<T>::operator * (Matrix mtx)
{
	Matrix<T> result(rows(), mtx.cols());

	if(cols() != mtx.rows())
	{
		cout << "[error] Matrix<?>::operator *" << endl;

		result.setToZero();
		return result;
	}

	for(int i=0; i<result.rows(); i++)
	{
		for(int j=0; j<result.cols(); j++)
		{
			T sum = 0;

			for(int k=0; k<cols(); k++)
				sum += get(i, k) * mtx.get(k, j);

			result.set(i, j, sum);
		}
	}

	return result;
}

/* Entry Manipulation */

template <class T>
T Matrix<T>::get(int row, int col)
{
	return matrix[row][col];
}

template <class T>
void Matrix<T>::set(int row, int col, T value)
{
	matrix[row][col] = value;
}

template <class T>
T* Matrix<T>::at(int row, int col)
{
	return &matrix[row][col];
}


/* Utility */

template <class T>
int Matrix<T>::rows()
{
	return ROWS;
}

template <class T>
int Matrix<T>::cols()
{
	return COLS;
}

template <class T>
void Matrix<T>::print()
{
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLS; j++)
			printf("%4.0f ", (double)get(i, j));

		printf("\n");
	}

	printf("\n");
}