#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << setprecision(3);
	cout << fixed;

	int C;// �׽�Ʈ���̽�
	int N;// �л���
	double score[1000] = { 0 };//����
	double ave2[1000] = { 0 };
	double ave1 = 0;
	double sum = 0;

	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> N;
		sum = 0;
		ave1 = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> score[j];
			sum = sum + score[j];
		}

		for (int k = 0; k < N; k++)
		{
			if ((sum / (double)N) < score[k])
				ave1 = ave1 + (100 / (double)N);
		}
		ave2[i] = ave1;
	}

	for (int i = 0; i < C; i++)
	{
		cout << ave2[i] << endl;
	}


	return 0;



}