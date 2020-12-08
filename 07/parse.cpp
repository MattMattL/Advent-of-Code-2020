#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenise(string str)
{
	vector<string> tokens;
	string buffer = "";

	for(int i=0; i<str.size(); i++)
	{
		if(str[i] != ' ')
		{
			if(str[i] != ',' && str[i] != '.')
				buffer += str[i];
		}
		else
		{
			tokens.push_back(buffer);
			buffer = "";
		}
	}

	tokens.push_back(buffer);

	return tokens;
}

void parseData()
{
	// open files
	ifstream fileIn;
	fileIn.open("./data.txt");

	ofstream fileOut;
	fileOut.open("./parsed.txt", fstream::out);

	// parse string
	string oneline;

	while(getline(fileIn, oneline))
	{
		vector<string> tokens = tokenise(oneline);

		// write the first bag
		fileOut << tokens.at(0) << " " << tokens.at(1) << " ";

		// write the rest
		if(tokens.at(4) == "no")
		{
			fileOut << "0" << endl;
		}
		else
		{
			fileOut << tokens.size() / 4 - 1 << endl;

			for(int i=1; i<tokens.size() / 4; i++)
			{
				fileOut << tokens.at(i * 4) << " ";
				fileOut << tokens.at(i * 4 + 1) << " ";
				fileOut << tokens.at(i * 4 + 2) << endl;
			}
		}

		fileOut << endl;
	}

	// post-init
	fileIn.close();
	fileOut.close();
}

int main()
{
	parseData();

	return 0;
}