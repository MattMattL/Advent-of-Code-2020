#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Bitmask
{
public:
	string mask;
	vector<int> address;
	vector<long long int> value;

	Bitmask()
	{
		clear();
	}

	void clear()
	{
		mask.clear();
		address.clear();
		value.clear();
	}
};

vector<Bitmask> bitmask;

void loadData()
{
	ifstream file;
	file.open("./data.txt");

	string fileInput;
	Bitmask tempMask;

	while(getline(file, fileInput))
	{
		if(fileInput.rfind("mask", 0) == 0)
		{
			// push previous mask and memory
			bitmask.push_back(tempMask);
			tempMask.clear();

			// save mask, LSB at [0]
			string mask = fileInput.substr(7, 36);

			for(int i=0; i<36; i++)
				tempMask.mask += mask[36 - i - 1];
		}
		else
		{
			// save address
			int i;
			string strNum = "";
			
			for(i=4; '0' <= fileInput[i] && fileInput[i] <= '9'; i++)
				strNum += fileInput[i];

			tempMask.address.push_back(stoll(strNum));

			// save the value at the address
			strNum = "";

			for(i+=4; '0' <= fileInput[i] && fileInput[i]; i++)
				strNum += fileInput[i];

			tempMask.value.push_back(stoll(strNum));
		}
	}

	bitmask.push_back(tempMask);
	bitmask.erase(bitmask.begin());

	file.close();
}
