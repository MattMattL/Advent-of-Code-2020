#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>

using namespace std;

int rows, cols;

vector<string> data;
vector<string> nextData;

bool isInBoundary(int i, int j)
{
	return (0 <= i && i < rows) && (0 <= j && j < cols);
}

bool equal(vector<string> vec1, vector<string> vec2)
{
	if(vec1.size() != vec2.size())
		return false;

	for(int i=0; i<vec1.size(); i++)
	{
		if(vec1.at(i) != vec2.at(i))
			return false;
	}

	return true;
}

int occupiedAround(int i, int j)
{
	int count = 0;
	
	if(isInBoundary(i+1, j+1)) { if(data.at(i+1).at(j+1) == '#') count++; }
	if(isInBoundary(i+1, j+0)) { if(data.at(i+1).at(j+0) == '#') count++; }
	if(isInBoundary(i+1, j-1)) { if(data.at(i+1).at(j-1) == '#') count++; }
	if(isInBoundary(i+0, j+1)) { if(data.at(i+0).at(j+1) == '#') count++; }
	if(isInBoundary(i+0, j-1)) { if(data.at(i+0).at(j-1) == '#') count++; }
	if(isInBoundary(i-1, j+1)) { if(data.at(i-1).at(j+1) == '#') count++; }
	if(isInBoundary(i-1, j+0)) { if(data.at(i-1).at(j+0) == '#') count++; }
	if(isInBoundary(i-1, j-1)) { if(data.at(i-1).at(j-1) == '#') count++; }

	return count;
}

char getFirstObj(int i, int j, int dRow, int dCol)
{
	i += dRow;
	j += dCol;

	while(isInBoundary(i, j))
	{
		if(data.at(i).at(j) != '.')
			return data.at(i).at(j);

		i += dRow;
		j += dCol;
	}

	return '.';
}

int occupiedInLine(int i, int j)
{
	int count = 0;

	if(isInBoundary(i+1, j+1)) { if(getFirstObj(i, j,  1,  1) == '#') count++; }
	if(isInBoundary(i+1, j+0)) { if(getFirstObj(i, j,  1,  0) == '#') count++; }
	if(isInBoundary(i+1, j-1)) { if(getFirstObj(i, j,  1, -1) == '#') count++; }
	if(isInBoundary(i+0, j+1)) { if(getFirstObj(i, j,  0,  1) == '#') count++; }
	if(isInBoundary(i+0, j-1)) { if(getFirstObj(i, j,  0, -1) == '#') count++; }
	if(isInBoundary(i-1, j+1)) { if(getFirstObj(i, j, -1,  1) == '#') count++; }
	if(isInBoundary(i-1, j+0)) { if(getFirstObj(i, j, -1,  0) == '#') count++; }
	if(isInBoundary(i-1, j-1)) { if(getFirstObj(i, j, -1, -1) == '#') count++; }

	return count;
}

void updateSeats()
{
	rows = nextData.size();
	cols = nextData.at(0).size();

	while(!equal(data, nextData))
	{
		// copy back to 'data' for next round
		data.clear();

		for(int i=0; i<rows; i++)
			data.push_back(nextData.at(i));

		// update seats
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				// Part 1
				// if(data.at(i).at(j) == 'L')
				// 	if(occupiedAround(i, j) == 0)
				// 		nextData.at(i).at(j) = '#';

				// if(data.at(i).at(j) == '#')
				// 	if(occupiedAround(i, j) >= 4)
				// 		nextData.at(i).at(j) = 'L';

				// Part 2
				if(data.at(i).at(j) == 'L')
					if(occupiedInLine(i, j) == 0)
						nextData.at(i).at(j) = '#';

				if(data.at(i).at(j) == '#')
					if(occupiedInLine(i, j) >= 5)
						nextData.at(i).at(j) = 'L';
			}
		}
	}

	// print result
	int count = 0;

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(data.at(i).at(j) == '#')
				count++;
		}
	}

	cout << count << endl;
}

int main()
{
	// load data
	ifstream file;
	file.open("./data.txt");

	string buffer;

	while(getline(file, buffer))
		nextData.push_back(buffer);

	file.close();

	// run
	updateSeats();

	return 0;
}