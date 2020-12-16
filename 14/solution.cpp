#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "bitmask.hpp"

using namespace std;

vector<pair<int, long long int> > memory; // pair<address, value>

string decToBin(long long int num)
{
	// LSB at [0]

	string bit = "";

	while(num)
	{
		bit += num % 2 + '0';
		num >>= 1;
	}

	while(bit.size() < 36)
		bit += "0";

	return bit;
}

long long int binToDec(string bit)
{
	// LSB at [0]
	long long int num = 0;

	for(int i=0; i<bit.size(); i++)
	{
		if(bit[i] == '1')
			num += pow(2, i);
	}

	return num;
}

bool hasAddress(int address)
{
	for(int i=0; i<memory.size(); i++)
	{
		if(memory.at(i).first == address)
			return true;
	}

	return false;
}

void sumNumsInMemory()
{
	for(int i=bitmask.size() - 1; i>=0; i--)
	{
		Bitmask currMask = bitmask.at(i);

		for(int j=0; j<currMask.address.size(); j++)
		{
			// optimisation:
			// add only if the address has not been initialised
			if(!hasAddress(currMask.address.at(j)))
			{
				// apply mask
				string bit = decToBin(currMask.value.at(j));

				for(int k=0; k<36; k++)
				{
					if(currMask.mask[k] != 'X')
						bit[k] = currMask.mask[k];
				}

				// add to memory
				pair<int, long long int> tempMemory;

				tempMemory.first = currMask.address.at(j);
				tempMemory.second = binToDec(bit);

				memory.push_back(tempMemory);
			}
		}
	}

	// Part 1 answer
	long long int sum = 0;

	for(int i=0; i<memory.size(); i++)
		sum += memory.at(i).second;

	cout << sum << endl;
}

int main()
{
	loadData();

	// Part 1
	sumNumsInMemory();

	// Part 2

	return 0;
}