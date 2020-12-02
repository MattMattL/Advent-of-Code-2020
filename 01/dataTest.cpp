#include <iostream>
#include <string>
#include "../data.hpp"

int main()
{
	Data<float> data;

	data.setTerminator(-1);
	data.read("./data.txt");

	data.print();
	
	data.set(0, -11);

	cout << "size = " << data.size() << endl;

	data.sort();

	for(int i=0; i<data.size(); i++)
		cout << data.at(i) << endl;
	cout << endl;

	return 0;
}