#include <iostream>
using namespace std;

int dp[1000010][2];

int main() {
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;

	int num;
	scanf("%d", &num);

	for (int i = 3; i <= num; i++) {
		dp[i][0] = (dp[i - 2][1] + dp[i - 2][0]);
		dp[i][0] %= 15746;
		dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] %= 15746;
	}

	printf("%d\n", (dp[num][0] + dp[num][1])%15746);
	return 0;
}