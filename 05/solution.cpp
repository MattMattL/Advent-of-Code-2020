#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int getIndex(string str, int iMin, int iMax, bool returnLower, char skipLowerHalf)
{
	int lower = 0, upper = pow(2, iMax - iMin) - 1;

	for(int i=iMin; i<iMax; i++)
	{
		if(str[i] == skipLowerHalf)
			lower = (lower + upper + 1) / 2;
		else
			upper = (lower + upper - 1) / 2;
	}

	return (returnLower)? lower : upper;
}

int getSeatID(string str)
{
	return getIndex(str, 0, 7, true, 'B') * 8 + getIndex(str, 7, 10, false, 'R');
}

int main()
{
	// save ID's in a priority queue
	ifstream file;
	file.open("./data.txt");

	priority_queue<int> seatIDs;
	string data;

	while(getline(file, data))
		seatIDs.push(getSeatID(data));

	file.close();

	// Part 1
	cout << "Highest ID: " << seatIDs.top() << endl;

	// Part 2
	int comp = seatIDs.top();
	seatIDs.pop();

	while(comp - seatIDs.top() != 2 && !seatIDs.empty())
	{
		comp = seatIDs.top();
		seatIDs.pop();
	}

	cout << "My ID: " << comp - 1 << endl;

	return 0;
}