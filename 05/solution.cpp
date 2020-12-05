#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int getSeatID(string str)
{
	// get row
	int lower = 0, upper = 127;

	for(int i=0; i<7; i++)
	{
		if(str[i] == 'B')
			lower = (lower + upper + 1) / 2;
		else
			upper = (lower + upper - 1) / 2;
	}

	int tempID = lower * 8;

	// get column
	lower = 0, upper = 7;

	for(int i=7; i<10; i++)
	{
		if(str[i] == 'R')
			lower = (lower + upper + 1) / 2;
		else
			upper = (lower + upper - 1) / 2;
	}

	return tempID + upper;
}

void getMaxID()
{
	ifstream file;
	file.open("./data.txt");

	int maxID = 0;
	string data;

	while(getline(file, data))
	{
		// get an ID and save if max
		int seatID = getSeatID(data);

		if(seatID > maxID)
			maxID = seatID;
	}

	cout << "Highest ID:" << maxID << endl;

	file.close();
}

void getConsecutiveID()
{
	// save ID's in a priority queue
	ifstream file;
	file.open("./data.txt");

	priority_queue<int> seatIDs;
	string data;

	while(getline(file, data))
		seatIDs.push(getSeatID(data));

	file.close();

	// find two consecutive ID's with difference = 1
	int comp1, comp2;

	comp1 = seatIDs.top();
	seatIDs.pop();

	comp2 = seatIDs.top();
	seatIDs.pop();

	while(!seatIDs.empty())
	{
		// Part 2 result
		if(comp1 - comp2 == 2)
		{
			cout << "My ID: " << comp1 - 1 << endl;
			return;
		}

		// shift for next round
		comp1 = comp2;
		comp2 = seatIDs.top();
		seatIDs.pop();
	}
}

int main()
{
	getMaxID();

	getConsecutiveID();

	return 0;
}