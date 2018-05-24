#include <cstdio>
using namespace std;

int dp[10010] = { 1 };

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int cost;
		scanf("%d", &cost);
		for (int j = cost; j <= k; j++) {
			dp[j] += dp[j - cost];
		}
	}

	printf("%d\n", dp[k]);
	return 0;
}