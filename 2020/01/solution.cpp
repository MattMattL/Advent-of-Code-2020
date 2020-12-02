#include <iostream>
#include <fstream>
#include <string>
#include "../data.hpp"

using namespace std;

Data<int> data;

int multiplyTwoSum(int target, int lower, int upper)
{
	int result[2] = {0, 0};

	while(lower < upper)
	{
		int sum = data.at(lower) + data.at(upper);

		if(sum > target)
			upper--;
		else if(sum < target)
			lower++;
		else if(sum == target)
			return data.at(lower) * data.at(upper);
	}

	return 0;
}

int multiplyThreeSum(int target)
{
	for(int i=0; i<data.size() - 2; i++)
	{
		int product = multiplyTwoSum(target - data.at(i), i + 1, data.size() - 1);

		if(product)
			return data.at(i) * product;
	}

	return 0;
}

int main()
{
	data.setTerminator(-1);
	data.read("./data.txt");
	data.sort();

	// Question 1
	cout << multiplyTwoSum(2020, 0, data.size() - 1) << endl;

	// Question 2
	cout << multiplyThreeSum(2020) << endl;

	return 0;
}