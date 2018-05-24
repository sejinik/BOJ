#include <cstdio>
#define MOD	1000000000

int n;
int d[101][10][1 << 10];

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= 9; i++) {
		d[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int cost = 1; cost < (1 << 10); cost++) {
			for (int j = 0; j <= 9; j++) {
				if (j) {
					d[i][j][cost | (1 << j)] += d[i - 1][j - 1][cost];
					d[i][j][cost | (1 << j)] %= MOD;
				}

				if (j < 9) {
					d[i][j][cost | (1 << j)] += d[i - 1][j + 1][cost];
					d[i][j][cost | (1 << j)] %= MOD;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i][(1 << 10) - 1];
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}