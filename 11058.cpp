#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n;
long long dp[101];

int main() {
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;

	for (int i = 5; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			dp[i] = max({ dp[i], dp[i - j] * (j - 1) ,dp[i-1]+1});
		}
	}
	printf("%lld\n", dp[n]);
	return 0;

}