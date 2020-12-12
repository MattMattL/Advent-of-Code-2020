#include <iostream>
#include <fstream>
#include "../dataHelper.hpp"

using namespace std;

Data<int> data;

void countDifferences()
{
	data.add_front(0);
	data.add_back(data.at(data.size() - 1) + 3);

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
