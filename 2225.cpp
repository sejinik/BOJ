#include <iostream>
using namespace std;
#define NUM 1000000000;
long long d[201][201];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	d[0][0] = 1;

	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 0; k <= i; k++) {
				d[i][j] += d[i - k][j - 1];
				d[i][j] %= NUM;
			}
		}
	}

	printf("%lld\n", d[N][K]);
	return 0;
}