// Old solution for Question 1, which calls data.txt.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define KEYS 8

using namespace std;

vector<string> data;

string fields[KEYS] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};

void loadData()
{
	ifstream file;
	file.open("./data.txt");

	string buffer;

	while(getline(file, buffer))
		data.push_back(buffer);

	file.close();
}

bool contains(string str, string substr)
{
	return str.find(substr) != std::string::npos;
}

bool isValid(bool arr[])
{
	for(int i=0; i<KEYS-1; i++)
	{
		if(!arr[i])
			return false;
	}

	return true;
}

void checkForFields()
{
	int count = 0;
	bool flag[KEYS] = {};

	for(int i=0; i<data.size(); i++)
	{
		if(data.at(i) != "")
		{
			// scan current person's info
			for(int key=0; key<KEYS; key++)
			{
				if(contains(data.at(i), fields[key] + ":") && !flag[key])
					flag[key] = true;
			}
		}
		else
		{
			// check validity
			if(isValid(flag))
				count++;

			// reset for the next person
			for(int key=0; key<KEYS; key++)
				flag[key] = false;
		}
	}

	cout << "valid = " << count << endl;
}

int main()
{
	loadData();

	checkForFields();

	return 0;
}