#include <iostream>
using namespace std;

int main()
{
	int score,S=0,T=0,res;
	
	for (int i = 0; i < 8; i++)
	{
		cin >> score;
		
		if (i < 4)
			S = S + score;

		else
			T = T + score;
	}

	if (S >= T)
		cout << S << endl;
	else
		cout << T << endl;

	return 0;
}