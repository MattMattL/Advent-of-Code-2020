#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countValidAnswers(int arr[], int num)
{
	int count = 0;

	for(int i=0; i<26; i++)
	{
		if(arr[i] >= num)
			count++;
	}

	return count;
}

int main()
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
			sum1 += countValidAnswers(alphabet, 1);
			sum2 += countValidAnswers(alphabet, peopInGroup);

			// initialise for the next group
			for(int i=0; i<26; i++)
				alphabet[i] = 0;

			peopInGroup = 0;
		}
	}

	cout << sum1 << endl;
	cout << sum2 << endl;

	file.close();

	return 0;
}