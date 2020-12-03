#include <iostream>
#include <fstream>
#include <string>

#define SIZE 1000

using namespace std;

bool isValidForQ1(int lower, int upper, char target, string password)
{
	// count the number of same characters as target
	int valid = 0;

	for(char ch : password)
	{
		if(ch == target)
			valid++;
	}

	// true if it's in range
	return (lower <= valid) && (valid <= upper);
}

bool isValidForQ2(int lower, int upper, char target, string str)
{
	// true of either matches with the target chararacter
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

		// Question 1
		// if(isValidForQ1(lower, upper, ch, password))
		// 	count++;

		// Question 2
		if(isValidForQ2(lower, upper, ch, password))
			count++;
	}

	cout << count << endl;

	file.close();
}

int main()
{
	countValidSets();

	return 0;
}