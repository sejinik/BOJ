#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


typedef struct SCORE
{
	string name,grade;
	int num;
	
}SCORE;

int main()
{
	
	float sum = 0, score = 0, sum_n=0;

	SCORE sco;
	double Tcase;
	cin >> Tcase;

	while (Tcase--)
	{
		cin >> sco.name >> sco.num >> sco.grade;
		if (sco.grade[0] == 'A')
			score = 4;
		else if (sco.grade[0] == 'B')
			score = 3;
		else if (sco.grade[0] == 'C')
			score = 2;
		else if (sco.grade[0] == 'D')
			score = 1;
		else if (sco.grade[0] == 'F')
			score = 0;

		if (sco.grade[1] == '+')
			score += 0.3f;
		else if (sco.grade[1] == '-')
			score -= 0.3f;

		sum = sum + score*sco.num;
		sum_n += sco.num;
	}
	sum = sum / sum_n;
	printf("%.2f\n", sum);

	return 0;
}