#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory.h>

#define ASCENDING 1
#define DESCENDING 2

using namespace std;


/* Class Definition */

template <class T>
class Data
{
private:
	vector<T> data;

	T terminator; // Deprecated

	void barf(string, string);

public:

	Data();
	~Data();

	// File IO
	void setTerminator(T); // Deprecated
	void read(string);

	// Data Manipulation
	T at(int);
	void set(int, T);
	void add_front(T);
	void add_back(T);
	int size();

	// Utilities
	void sort();
	void sort(int);
	void swap(int, int);
	T* toArray();
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
	ifstream file;
	file.open(location);

	if(!file)
		barf("read", "no such external file found");

	// count the number of data
	string buffer;
	int length = 0;

	while(getline(file, buffer))
		length++;

	file.close();

	// copy from file
	file.open(location);

	for(int i=0; i<length; i++)
	{
		T temp;

		file >> temp;
		data.push_back(temp);
	}

	file.close();
}

template <class T>
T Data<T>::at(int index)
{
	if(index < 0 || index >= size())
		barf("at", "index out of boundary");

	return data.at(index);
}

template <class T>
void Data<T>::set(int index, T value)
{
	if(index < 0 || index >= size())
		barf("set", "index out of boundary");

	data.at(index) = value;
}

template <class T>
int Data<T>::size()
{
	return data.size();
}

template <class T>
void Data<T>::sort()
{
	// default sorting option
	sort(ASCENDING);
}

template <class T>
void Data<T>::add_front(T value)
{
	data.insert(data.begin(), value);
}

template <class T>
void Data<T>::add_back(T value)
{
	data.push_back(value);
}

template <class T>
void Data<T>::sort(int mode)
{
	// O(N^2), but used only for implementation.
	for(int i=size()-2; i>=0; i--)
	{
		for(int j=0; j<=i; j++)
		{
			switch(mode)
			{
				case DESCENDING:
					if(data.at(j) < data.at(j+1))
						swap(j, j + 1);
					break;

				case ASCENDING:
					if(data.at(j) > data.at(j+1))
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
	if(i < 0 || i >= size())
		barf("swap", "first index out of boundary");
	else if(j < 0 || j >= size())
		barf("swap", "second index out of boundary");

	T temp = data.at(i);
	data.at(i) = data.at(j);
	data.at(j) = temp;
}

template <class T>
T* Data<T>::toArray()
{
	// arr returned needs to be manually deleted
	// using the delete command
	T *arr = new T[size()];

	memcpy(arr, &data.at(0), size() * sizeof(T*));

	return arr;
}

template <class T>
void Data<T>::print()
{
	for(int i=0; i<size(); i++)
		cout << data[i] << endl;

	cout << endl;
}
