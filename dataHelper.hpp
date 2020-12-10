#include <iostream>
#include <fstream>
#include <string>

#define ASCENDING 1
#define DESCENDING 2

using namespace std;


/* Class Definition */

template <class T>
class Data
{
private:
	T *data;
	int length;

	T terminator;

	void barf(string, string);

public:

	Data();
	~Data();

	// File IO
	void setTerminator(T); // Deprecated
	void read(string);

	// Setters & Getters
	T at(int);
	void set(int, T);
	int size();

	// Utilities
	void sort();
	void sort(int);
	void swap(int, int);
	void print();
};


/* Implementations */

template <class T>
Data<T>::Data()
{

}

template <class T>
Data<T>::~Data()
{
	delete(data);
}

template <class T>
void Data<T>::barf(string fcn, string msg)
{
	cout << "[error] ";
	cout << "<Data::" << fcn << "> ";
	cout << msg << endl;

	exit(-1);
}

// Deprecated
template <class T>
void Data<T>::setTerminator(T terminatorIn)
{
	terminator = terminatorIn;
}

template <class T>
void Data<T>::read(string location)
{
	// count the number of data
	ifstream file;
	file.open(location);

	if(!file)
	{
		cout << "[error] wrong file path" << endl;
		return;
	}

	length = 0;
	string buffer;

	while(getline(file, buffer))
		length++;

	file.close();

	// load data
	file.open(location);
	data = new T[length];

	for(int i=0; i<length; i++)
		file >> data[i];

	file.close();
}

template <class T>
T Data<T>::at(int index)
{
	if(index < 0 || index >= length)
		barf("at", "index out of boundary");

	return data[index];
}

template <class T>
void Data<T>::set(int index, T value)
{
	if(index < 0 || index >= length)
		barf("set", "index out of boundary");

	data[index] = value;
}

template <class T>
int Data<T>::size()
{
	return length;
}

template <class T>
void Data<T>::sort()
{
	// default sorting option
	sort(ASCENDING);
}

template <class T>
void Data<T>::sort(int mode)
{
	// O(N^2), but used only for implementation.
	for(int i=length-2; i>=0; i--)
	{
		for(int j=0; j<=i; j++)
		{
			switch(mode)
			{
				case DESCENDING:
					if(data[j] < data[j+1])
						swap(j, j + 1);
					break;

				case ASCENDING:
					if(data[j] > data[j+1])
						swap(j, j + 1);
					break;

				default:
					barf("sort", "no such sorting option");
			}
			
		}
	}
}

template <class T>
void Data<T>::swap(int i, int j)
{
	if(i < 0 || i >= length)
		barf("swap", "first index out of boundary");
	else if(j < 0 || j >= length)
		barf("swap", "second index out of boundary");

	T temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

template <class T>
void Data<T>::print()
{
	for(int i=0; i<length; i++)
		cout << data[i] << endl;

	cout << endl;
}
