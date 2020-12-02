#include <iostream>
#include <fstream>
#include <string>

#define SIZE 1000

using namespace std;

bool isValidForQ1(int lower, int upper, char target, string password)
{
	// count the number of give character
	int valid = 0;
	for(char ch : password)
	{
		if(ch == target)
			valid++;
	}

	return (lower <= valid) && (valid <= upper);
}

bool isValidForQ2(int lower, int upper, char target, string str)
{
	return (str.at(lower - 1) == target) ^ (str.at(upper - 1) == target);
}

void countValidSets()
{
	ifstream file;
	file.open("./data.txt");

	int count = 0;

	int lower, upper;
	char ch, rubbish;
	string password;

	for(int i=0; i<SIZE; i++)
	{
		// read one line from the file
		file >> lower >> rubbish >> upper >> ch >> rubbish >> password;

		// count for Q1
		// count += isValidForQ1(lower, upper, ch, password)? 1 : 0;

		// count for Q2
		count += isValidForQ2(lower, upper, ch, password)? 1 : 0;		
	}

	cout << count << endl;

	file.close();
}

int main()
{
	countValidSets();

	return 0;
}