#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int height[9],temp;
	int sum=0,s_height=0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height[i]);
		sum = sum + height[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1 + i; j < 9; j++)
		{
			s_height = sum;
			s_height = s_height - height[i] - height[j];

			if (s_height == 100)
			{
				height[i] = 0;
				height[j] = 0;
				break;
			}

		}
		if (height[i] == 0)
			break;
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (height[i] > height[j])
			{
				temp = height[i];
				height[i] = height[j];
				height[j] = temp;
			}
		}
	}

	for (int i = 2; i < 9; i++)
		printf("%d\n", height[i]);

	return 0;
}