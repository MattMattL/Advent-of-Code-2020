#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define KEYS 8

using namespace std;

string fields[KEYS] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
map<string, int> keyToIndex;

vector<vector<string> > data;

void loadData()
{
	ifstream file;
	file.open("./parsed.txt");

	string info;
	vector<string> buffer;

	while(getline(file, info))
	{
		if(info != "")
		{
			// add to vector
			buffer.push_back(info);
		}
		else
		{
			// reached the end; add to 'data' and reset
			data.push_back(buffer);
			buffer.clear();
		}
	}

	file.close();
}

bool isValidForQ1(bool arr[])
{
	for(int i=0; i<KEYS-1; i++)
	{
		if(!arr[i])
			return false;
	}

	return true;
}

bool isValidForQ2(string info)
{
	string key = info.substr(0, 3);

	int num;
	string unit;
	string colours[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

	switch(keyToIndex[key])
	{
		case 0: // Birth Year
			num = stoi(info.substr(4, 4));
			return (1920 <= num) && (num <= 2002);
		
		case 1: // Issue Year
			num = stoi(info.substr(4, 4));
			return (2010 <= num) && (num <= 2020);
		
		case 2: // Expiration Year
			num = stoi(info.substr(4, 4));
			return (2020 <= num) && (num <= 2030);
		
		case 3: // Height
			unit = info.substr(info.size() - 2, 2);

			if(unit != "cm" && unit != "in")
				return false;

			num = stoi(info.substr(4, info.size() - 6));
			
			if(unit == "cm")
				return (150 <= num) && (num <= 193);
			else
				return (59 <= num) && (num <= 76);

		case 4: // Hair Color
			if(info[4] != '#')
				return false;

			if(info.size() != 11)
				return false;

			for(int i=0; i<6; i++)
			{
				if((info[i + 5] < '0' || info[i + 5] > '9') &&
					(info[i + 5] < 'a' || info[i + 5] > 'f'))
				{
					cout << "wrong digit: " << info << " " << info[i + 5] << endl;
					return false;
				}
			}

			return true;

		case 5: // Eye Color
			for(int i=0; i<sizeof(colours)/sizeof(colours[0]); i++)
			{
				if(info.substr(4, 3) == colours[i])
					return true;
			}

			return false;

		case 6: // Passport ID
			if(info.size() != 13)
				return false;

			for(int i=0; i<9; i++)
			{
				if(info[i + 4] < '0' || info[i + 4] > '9')
					return false;
			}

			return true;

		case 7: // Country ID
			return true;

		default:
			return true;
	}
}

void checkValidity()
{
	int count = 0;

	bool flag[KEYS] = {};
	bool isValid;

	for(int p=0; p<data.size(); p++)
	{
		isValid = true;

		for(int k=0; k<data.at(p).size() && isValid; k++)
		{
			string keyAndData = data.at(p).at(k);

			// memorise provided keys for Question 1
			string key = keyAndData.substr(0, 3);
			flag[keyToIndex[key]] = true;

			// check validity for Question 2
			isValid &= isValidForQ2(keyAndData);
		}

		isValid &= isValidForQ1(flag);

		if(isValid)
			count++;

		// post-initialisation
		for(int k=0; k<KEYS; k++)
			flag[k] = false;
	}

	cout << count << endl;
}

int main()
{
	// initialise key-index map
	for(int key=0; key<KEYS; key++)
		keyToIndex[fields[key]] = key;

	// count valid passports
	loadData();
	checkValidity();

	return 0;
}