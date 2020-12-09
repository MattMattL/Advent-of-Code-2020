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

void sort(double *arr)
{
	// O(N^2) only for implementation, could be replaced with NlogN
	for(int i=PREAMBLE-2; i>=0; i--)
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

void checkTwoSum()
{
	for(int i=0; i<data.size() - PREAMBLE; i++)
	{
		// copy partial array
		double preambles[PREAMBLE];

		memcpy(preambles, &data.at(i), PREAMBLE * sizeof(double));
		sort(preambles);

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
			// Question 1 answer
			printf("%.0f\n", target);
			return;
		}
	}
}

int main()
{
	loadData();

	// Q1
	checkTwoSum();

	return 0;
}
