#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define ROWS 323
#define COLS 31

using namespace std;

vector<string> map;

void loadData()
{
	ifstream file;
	file.open("./data.txt");

	for(int i=0; i<ROWS; i++)
	{
		string column;

		getline(file, column);
		map.push_back(column);
	}

	file.close();
}

int countOverlaps(int dRow, int dCol)
{
	int row = 0, col = 0, trees = 0;

	while(row < ROWS)
	{
		if(map.at(row % ROWS).at(col % COLS) == '#')
			trees++;

		row += dRow;
		col += dCol;
	}

	return trees;
}

int main()
{
	loadData();

	// Question 1
	cout << "Q1: trees = " << countOverlaps(1, 3) << endl;

	// Question 2
	int product = countOverlaps(1, 1);
	product *= countOverlaps(1, 3);
	product *= countOverlaps(1, 5);
	product *= countOverlaps(1, 7);
	product *= countOverlaps(2, 1);

	cout << "Q2: product = " << product << endl;

	return 0;
}