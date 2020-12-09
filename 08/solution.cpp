#include <iostream>
#include <fstream>
#include <vector>
#include "boot_machine.hpp"

using namespace std;

int main()
{
	BootMachine machine;
	machine.read("./data.txt");

	int i = 0;

	while(i++ < machine.boot_code.size())
	{
		machine.reset();
		machine.read("./data.txt");

		if(machine.boot_code.at(i).operation == "jmp")
			machine.boot_code.at(i).operation = "nop";
		else if(machine.boot_code.at(i).operation == "nop")
			machine.boot_code.at(i).operation = "jmp";
		else
			continue;

		if(machine.run())
			break;
	}

	// Question 2 answer
	cout << machine.accumulator << endl;

	return 0;
}