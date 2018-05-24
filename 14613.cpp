#include <iostream>
#include <algorithm>
using namespace std;
double w, l, d;
double dp[22][3333];

int main() {
	scanf("%lf %lf %lf", &w, &l, &d);

	dp[0][2000] = 1.0;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1000; j <= 3000; j++) {
			if (dp[i - 1][j] == 0) continue;
			dp[i][j + 50] += dp[i - 1][j] * w;
			dp[i][j - 50] += dp[i - 1][j] * l;
			dp[i][j] += dp[i - 1][j] * d;
		}
	}
	double ans = 0.0;
	for (int j = 1000; j <= 3499; j++) {
		ans += dp[20][j];
		if (j == 1499 || j == 1999 || j == 2499 || j == 2999 || j == 3499) {
			printf("%.8lf\n", ans); ans = 0.0;
		}
	}
}