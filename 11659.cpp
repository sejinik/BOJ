#include <iostream>
#include <cstdio>
using namespace std;

int pSUM[100010];
int num[100010];

int main()
{
	int N, M, i, j;
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
		pSUM[i] = num[i] + pSUM[i - 1];
	}

	while (M--)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", pSUM[j] - pSUM[i - 1]);
	}

	return 0;
	
}