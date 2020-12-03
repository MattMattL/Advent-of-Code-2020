#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readFromFile()
{
	// open an external file
	ifstream file;

	file.open("./data.txt");

	if(!file.is_open())
	{
		cout << "no such external file found" << endl;
		return 0;
	}

	// read from file until reach the end
	int buffer;

	file >> buffer;
	cout << buffer << endl;

	while(!file.eof())
	{
		file >> buffer;

		if(file.eof())
			break;
		
		cout << buffer << endl;
	}

	// post init
	file.close();
}

int main()
{
	return 0;
}