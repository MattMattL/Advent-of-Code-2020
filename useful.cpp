#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readFromFile()
{
	int value;

	file >> value;
	cout << value << endl;

	while(!file.eof())
	{
		file >> value;

		if(file.eof())
			break;
		
		cout << value << endl;
	}
}

// for files with a single value per line
void readFromFile_()
{
	string buffer;
	int value;

	while(getline(file, buffer))
	{
		value = stoi(buffer);
		cout << value << endl;
	}
}

int main()
{
	return 0;
}