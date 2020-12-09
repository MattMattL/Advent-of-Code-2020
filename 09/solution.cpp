#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>

#define PREAMBLE 25

using namespace std;

vector<double> data;

void loadData()
{
	ifstream file;
	file.open("./data.txt");

	string buffer;

	while(getline(file, buffer))
		data.push_back(stod(buffer));

	file.close();
}

void sort(double *arr, int size)
{
	// O(N^2) only for implementation, could be replaced with NlogN
	for(int i=size-2; i>=0; i--)
	{
		for(int j=0; j<=i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

double checkPartialSum(double target)
{
	int lower = 0, upper = 1;
	double sum = data.at(0) + data.at(1);

	// calculate partial sum
	while(upper < data.size())
	{
		if(sum < target)
		{
			upper++;
			sum += data.at(upper);
		}
		else if(sum > target)
		{
			sum -= data.at(lower);
			lower++;

			// keep 'upper - lower = 1'
			if(lower >= upper)
			{
				upper++;
				sum += data.at(upper);
			}
		}
		else // (sum == target)
		{
			int size = upper - lower + 1;
			double *arr = new double[size];

			memcpy(arr, &data.at(lower), size * sizeof(double));
			sort(arr, size);

			return arr[0] + arr[size - 1];
		}
	}

	return 0;
}

void checkTwoSum()
{
	for(int i=0; i<data.size() - PREAMBLE; i++)
	{
		// copy partial array
		double preambles[PREAMBLE];

		memcpy(preambles, &data.at(i), PREAMBLE * sizeof(double));
		sort(preambles, PREAMBLE);

		// find two sum
		int min = 0, max = PREAMBLE - 1;
		double target = data.at(i + PREAMBLE);
		double sum;

		while(min < max)
		{
			sum = preambles[min] + preambles[max];

			if(sum < target)
				min++;
			else if(sum > target)
				max--;
			else
				break;
		}

		// check conditions
		if(sum != target)
		{
			// Part 1 answer
			printf("%.0f\n", target);

			memcpy(preambles, &data.at(i), PREAMBLE * sizeof(double));
			
			// Part 2 answer
			printf("%.0f\n", checkPartialSum(target));

			return;
		}
	}
}

int main()
{
	loadData();

	// Q1 and Q2
	checkTwoSum();

	return 0;
}
