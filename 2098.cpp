#include <iostream>
#include <algorithm>
using namespace std;
int n;
int w[16][16];
int d[16][(1 << 16)];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			d[i][j] = 1e+9;
		}
	}
	d[0][1] = 0;

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 1; j < n; j++) {
			if (i&(1 << j)) {
				for (int k = 0; k < n; k++) {
					if (k != j && w[k][j] != 0 && i&(1 << k))
						d[j][i] = min(d[j][i], d[k][i - (1 << j)] + w[k][j]);
				}
			}
		}
	}
	int ans = 1e+9;
	for (int i = 1; i < n; i++) {
		if (w[i][0] == 0) continue;
		ans = min(ans, d[i][(1 << n) - 1] + w[i][0]);
	}
	printf("%d\n", ans);
	return 0;
}