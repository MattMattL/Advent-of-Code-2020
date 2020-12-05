#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// open files
	ifstream fileIn;
	fileIn.open("./data.txt");

	ofstream fileOut;
	fileOut.open("./parsed.txt", fstream::out);

	// replace spaces with newlines
	string buffer;

	while(getline(fileIn, buffer))
	{
		for(int i=0; i<buffer.size(); i++)
		{
			if(buffer[i] == ' ')
				buffer[i] = '\n';
		}

		fileOut << buffer << endl;
	}

	// post-init
	fileIn.close();
	fileOut.close();

	return 0;
}
