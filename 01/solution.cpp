#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int *data;
int length;

void loadData()
{
	ifstream file;
	
	// count the number of data
	file.open("./data.txt");

	if(!file)
		return;

	length = -1;
	int buffer = 0;

	while(buffer != -1)
	{
		length++;
		file >> buffer;
	}

	file.close();

	// load data
	file.open("./data.txt");

	data = new int[length];

	for(int i=0; i<length; i++)
	{
		file >> data[i];
	}

	file.close();
}

// O(N^2), but only for implementation.
void bubbleSort()
{
	for(int i=length-2; i>0; i--)
	{
		for(int j=0; j<=i; j++)
		{
			if(data[j] > data[j+1])
			{
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
}

int multiplyTwoSum(int target, int lower, int upper)
{
	int result[2] = {0, 0};

	while(lower < upper)
	{
		int sum = data[lower] + data[upper];

		if(sum > target)
			upper--;
		else if(sum < target)
			lower++;
		else if(sum == target)
			return data[lower] * data[upper];
	}

	return 0;
}

int multiplyThreeSum(int target)
{
	for(int i=0; i<length-2; i++)
	{
		int product = multiplyTwoSum(target - data[i], i + 1, length - 1);

		if(product)
			return data[i] * product;
	}

	return 0;
}

int main()
{
	loadData();
	bubbleSort();

	// Question 1
	cout << multiplyTwoSum(2020, 0, length - 1) << endl;

	// Question 2
	cout << multiplyThreeSum(2020) << endl;

	return 0;
}