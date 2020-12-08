#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Bag
{
private:

public:
	vector<Bag> subBags;

	int size, num;
	string name;

	bool hasShinyGold;

	Bag(int num, string name)
	{
		this->num = num;
		this->size = num;
		this->name = name;

		this->hasShinyGold = false;
	}
};

vector<Bag> bags;

void loadData()
{
	ifstream file;
	file.open("./parsed.txt");

	int num;
	string colour1, colour2;

	file >> colour1 >> colour2 >> num;

	while(colour1 != "end_of_line")
	{
		Bag bigBag(num, colour1 + " " + colour2);

		for(int i=0; i<num; i++)
		{
			int num;

			file >> num >> colour1 >> colour2;

			Bag tinyBag(num, colour1 + " " + colour2);
			bigBag.subBags.push_back(tinyBag);
		}

		bags.push_back(bigBag);

		file >> colour1 >> colour2 >> num;
	}

	file.close();
}

int indexOf(string key)
{
	for(int i=0; i<bags.size(); i++)
	{
		if(bags.at(i).name == key)
			return i;
	}

	cout << "[error] <indexOf> vector contains no such element" << endl;
	return -1;
}

bool searchShinyGold(string colour)
{
	Bag *bag = &bags.at(indexOf(colour));

	// return if already been checked
	if(bag->hasShinyGold)
		return true;

	bool flag = false;

	for(int i=0; i<bag->size; i++)
	{
		Bag subBag = bag->subBags.at(i);

		// this branch contains shiny gold
		if(subBag.name == "shiny gold")
		{
			bag->hasShinyGold = true;
			return true;
		}

		// search recursively
		flag |= searchShinyGold(bag->subBags.at(i).name);
	}

	// flag and return
	if(flag)
	{
		bag->hasShinyGold = true;
		return true;
	}
	
	// this branch contains no shiny gold
	return false;
}

void countShinyGold()
{
	int count = 0;

	for(int i=0; i<bags.size(); i++)
		searchShinyGold(bags.at(i).name);

	for(int i=0; i<bags.size(); i++)
	{
		if(bags.at(i).hasShinyGold)
			count++;
	}

	cout << count << endl;
}

int countBagsInside(string colour)
{
	Bag bag = bags.at(indexOf(colour));
	int sum = 0;

	for(int i=0; i<bag.size; i++)
	{
		sum += bag.subBags.at(i).num * countBagsInside(bag.subBags.at(i).name);
		sum += bag.subBags.at(i).num;
	}

	return sum;
}

int main()
{
	loadData();

	// Question 1
	countShinyGold();

	// Question 2
	cout << countBagsInside("shiny gold") << endl;

	return 0;
}
