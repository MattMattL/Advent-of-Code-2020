#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int arrivalTime;
vector<int> busIDs;

void loadData()
{
	ifstream file;
	file.open("./data.txt");

	file >> arrivalTime;

	string data, buffer = "";;
	file >> data;

	for(int i=0; i<data.size(); i++)
	{
		if('0' <= data[i] && data[i] <= '9')
		{
			buffer += data[i];
		}
		else if(data[i] == 'x')
		{
			busIDs.push_back(0);
		}
		else if(!buffer.empty())
		{
			busIDs.push_back(stoi(buffer));
			buffer = "";
		}
	}

	file.close();
}

void findEarliestBus()
{
	int id = -1;
	int waitingTime = INT_MAX;

	for(int i=0; i<busIDs.size(); i++)
	{
		if(!busIDs.at(i))
			continue;

		double lapse = ceil((double)arrivalTime / (double)busIDs.at(i));
		int timeGap = lapse * busIDs.at(i) - arrivalTime;

		if(timeGap < waitingTime)
		{
			id = busIDs.at(i);
			waitingTime = timeGap;
		}
	}

	// Part 1 answer
	cout << id * waitingTime << endl;
}

int main()
{
	loadData();

	// Part 1
	findEarliestBus();

	return 0;
}