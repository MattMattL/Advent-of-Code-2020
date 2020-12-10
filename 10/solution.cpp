#include <iostream>
#include <fstream>
#include "../dataHelper.hpp"

using namespace std;

Data<int> data;

void countDifferences()
{
	int diff_1 = 0, diff_3 = 0;

	for(int i=0; i<data.size() - 1; i++)
	{
		switch(data.at(i + 1) - data.at(i))
		{
			case 1:
				diff_1++; break;
			case 3:
				diff_3++; break;
		}
	}

	// outlet to adopter
	switch(data.at(0))
	{
		case 1:
			diff_1++; break;
		case 3:
			diff_3++; break;
	}

	// adopter to device
	diff_3++;

	// Part 1 answer
	cout << diff_1 * diff_3 << endl;
}

int main()
{
	data.read("./data.txt");
	data.sort();

	countDifferences();

	return 0;
}