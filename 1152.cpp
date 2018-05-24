#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	char str[1000000];
	int Count = 0;
	int i = 0;

	cin.getline(str,sizeof(str));

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			Count++;

			if (str[i - 1] == ' ' || i==0)
				Count--; 

			if (i == strlen(str) - 1)
				Count--;
		}

		
	}

	cout << Count + 1 << endl;

	return 0;

}