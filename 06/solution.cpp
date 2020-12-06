#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numValidForQ1(int arr[])
{
	int count = 0;

	for(int i=0; i<26; i++)
	{
		if(arr[i] > 0)
			count++;
	}


	return count;
}

int numValidForQ2(int arr[], int num)
{
	int count = 0;

	for(int i=0; i<26; i++)
	{
		if(arr[i] >= num)
			count++;
	}

	return count;
}

void loadData()
{
	ifstream file;
	file.open("./data.txt");

	int sum1 = 0, sum2 = 0;

	string str;
	int peopInGroup = 0;
	int alphabet[26] = {};

	while(getline(file, str))
	{
		if(str != "")
		{
			// count letters
			for(int i=0; i<str.size(); i++)
				alphabet[str[i] - 'a']++;

			peopInGroup++;
		}
		else
		{
			// add to total sum
			sum1 += numValidForQ1(alphabet);
			sum2 += numValidForQ2(alphabet, peopInGroup);

			// initialise for the next group
			for(int i=0; i<26; i++)
				alphabet[i] = 0;

			peopInGroup = 0;
		}
	}

	cout << sum1 << endl;
	cout << sum2 << endl;

	file.close();
}

int main()
{
	loadData();

	return 0;
}