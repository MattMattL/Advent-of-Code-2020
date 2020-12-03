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

	if(!file)
	{
		cout << "no external file found" << endl;
		exit(-1);
	}

	for(int i=0; i<ROWS; i++)
	{
		string column;

		getline(file, column);
		map.push_back(column);
	}

	file.close();
}

int* index(int row, int col)
{
	int *arr = new int[2];

	arr[0] = row % ROWS;
	arr[1] = col % COLS;

	return arr;
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
	int product = 1;

	product *= countOverlaps(1, 1);
	product *= countOverlaps(1, 3);
	product *= countOverlaps(1, 5);
	product *= countOverlaps(1, 7);
	product *= countOverlaps(2, 1);

	cout << "Q2: product = " << product << endl;

	return 0;
}