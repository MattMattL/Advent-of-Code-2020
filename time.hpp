#include <iostream>
#include <time.h>

class Time
{
private:
	double tick;
	double timePassed;

public:
	Time()
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

	void printExecutionTime()
	{
		double executionTime = timePassed / CLOCKS_PER_SEC;
		printf("\nexecution time : %.4f s\n", executionTime);
	}

};