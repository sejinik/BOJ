#include <iostream>
#include <string>
using namespace std;

int main()
{
	int Tcase;
	int score,sum;
	string str;
	
	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> str;
		sum = 0;
		score = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'O')
			{
				score++;
				sum = sum + score;
			}
			else
				score = 0;
		}
		cout << sum << endl;
	}

	return 0;
}