#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Instruction
{
private:

public:
	string operation;
	int argument;

	// add variables here
	int executions;

	Instruction()
	{
		operation = "";
		argument = 0;

		executions = 0;
	}
};

class BootMachine
{
private:

public:
	vector<Instruction> boot_code;
	int accumulator, pointer;

	int read(string location)
	{
		ifstream file;
		file.open(location);

		if(!file)
		{
			cout << "[error] file does not exist" << endl;
			return 1;
		}

		string buffer;

		while(getline(file, buffer))
		{
			Instruction code;
			int i;
			string token = "";

			for(i=0; buffer[i] != ' ' && buffer[i] != '\0'; i++)
				code.operation += buffer[i];

			for(i += 1; buffer[i] != ' ' && buffer[i] != '\0'; i++)
				token += buffer[i];

			code.argument = stoi(token);

			boot_code.push_back(code);
		}

		file.close();

		return 0;
	}

	int run()
	{
		accumulator = 0;
		pointer = 0;

		while(pointer < boot_code.size())
		{
			string op = boot_code.at(pointer).operation;
			int arg = boot_code.at(pointer).argument;

			if(boot_code.at(pointer).executions)
			{
				// Question 1 answer
				// cout << accumulator << endl;
				return 0;
			}

			boot_code.at(pointer).executions++;

			if(op == "acc")
			{
				accumulator += arg;
				pointer++;
			}
			else if(op == "jmp")
			{
				pointer += arg;
			}
			else if(op == "nop")
			{
				pointer++;
			}
		}

		return 1;
	}

	void reset()
	{
		boot_code.clear();
	}
};
