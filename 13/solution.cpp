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

	busIDs.push_back(stoi(buffer));

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

void getFactors(double *l, double *k, double bus1, double bus2, double gap)
{
	// finds the lowest integers l, k such that k * bus2 - l * bus1 == gap

	*l = 0;
	*k = 0.1;

	while(*k != floor(*k))
	{
		(*l)++;

		// k * B(i+N) - l * B(i) = N
		*k = (*l * bus1 + gap) / bus2;
	}
}

double gcd(double a, double b)
{
	if(b < a)
	{
		double temp = a;
		a = b;
		b = temp;
	}

	return (b == 0)? a : gcd(b, (int)a % (int)b); // gcd(b, a % b) for type double
}

double lcm(double a, double b)
{
	return a * a / gcd(a, b);
}

void findContestAnswer()
{
	// vector<double> time;

	// for(int i=1; i<busIDs.size(); i++)
	// {
	// 	if(!busIDs.at(i))
	// 		continue;

	// 	double l, k;

	// 	getFactors(&l, &k, (double)busIDs.at(0), (double)busIDs.at(i), (double)i);
	// 	time.push_back(k * busIDs.at(i));

	// 	printf("%.0f\t * %d\t - %.0f\t * %d\t = %d\n", k, busIDs.at(i), l, busIDs.at(0), i);
	// }

	// for(int i=0; i<time.size(); i++)
	// 	cout << " " << time.at(i) << endl;
}

int main()
{
	loadData();

	// Part 1
	findEarliestBus();

	// Part 2
	// findContestAnswer();

	return 0;
}