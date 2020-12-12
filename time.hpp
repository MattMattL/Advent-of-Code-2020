#include <iostream>
#include <time.h>

class Timer
{
private:
	double tick;
	double timePassed;

public:
	Timer()
	{

	}

	void startClock()
	{
		tick = clock();
	}

	void endClock()
	{
		timePassed = clock() - tick;
	}

	void print()
	{
		double executionTime = timePassed / CLOCKS_PER_SEC;
		printf("\nexecution time : %.4f s\n", executionTime);
	}

};