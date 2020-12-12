#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void moveByInput()
{
	ifstream file;
	file.open("./data.txt");

	int x = 0, y = 0, angle = 0;

	char direction = '0';
	int amount;

	file >> direction >> amount;

	while(direction != 'Z')
	{
		switch(direction)
		{
			case 'N':
				y += amount; break;
			case 'E':
				x += amount; break;
			case 'W':
				x -= amount; break;
			case 'S':
				y -= amount; break;

			case 'R':
				angle += 360 - amount; angle %=360; break;
			case 'L':
				angle += amount; angle %= 360; break;
			case 'F':
				switch(angle)
				{
					case 0: x += amount; break;
					case 90: y += amount; break;
					case 180: x -= amount; break;
					case 270: y -= amount; break;
					default: cout << "wrong angle: " << angle << endl;
				}
				break;
		}

		file >> direction >> amount;
	}

	file.close();

	cout << abs(x) + abs(y) << endl;
}

void rotate(double *dx, double *dy, double angle)
{
	double oldX = *dx;
	double oldY = *dy;

	angle *= M_PI / 180;

	*dx = oldX * cos(angle) - oldY * sin(angle);
	*dy = oldX * sin(angle) + oldY * cos(angle);
}

void moveByWaypoint()
{
	ifstream file;
	file.open("./data.txt");

	double x = 0, y = 0;
	double dx = 10, dy = 1;
	double angle = 0;

	char direction = '0';
	int amount;

	file >> direction >> amount;

	while(direction != 'Z')
	{
		switch(direction)
		{
			case 'N':
				dy += amount; break;
			case 'E':
				dx += amount; break;
			case 'W':
				dx -= amount; break;
			case 'S':
				dy -= amount; break;

			case 'R':
				rotate(&dx, &dy, -amount); break;
			case 'L':
				rotate(&dx, &dy, amount); break;
			case 'F':
				x += amount * dx;
				y += amount * dy;
				break;
		}

		file >> direction >> amount;
	}

	file.close();

	cout << abs(x) + abs(y) << endl;
}

int main()
{
	// Part 1
	moveByInput();

	// Part 2
	moveByWaypoint();

	return 0;
}