#include <iostream>
using namespace std;

int dp[30][30];

int main() {


	for (int i = 1; i <= 29; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i < 30; i++) {
		for (int j = i; j < 30; j++) {
			for (int k = 1; k < j; k++) {
				dp[i][j] += dp[i-1][k];
			}
		}
	}

	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", dp[a][b]);
	}

	return 0;
}