#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int hour, min, time;
	scanf("%d%d%d", &hour, &min, &time);

	min = min + time;

	while (min >= 60)
	{
		min = min - 60;
		hour++;

		if (hour >= 24)
			hour = hour - 24;
	}

	printf("%d %d\n", hour, min);

	return 0;

	
}