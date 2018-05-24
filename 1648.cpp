#include <iostream>
#include <algorithm>
using namespace std;
int mod = 9901;
int n, m;
int d[14 * 14 + 1][(1 << 14)];

int main() {
	scanf("%d %d", &n, &m);

	d[0][0] = 1;
	for (int i = 0; i < n*m; i++) {
		for (int j = 0; j < (1<<m); j++) {
			if (j & 1) {
				d[i + 1][j >> 1] += d[i][j];
				d[i][j] %= mod;
			}
			else {
				if (!(j & 3) && (i%m) != (m - 1)) {
					d[i + 1][(j >> 1) + 1] += d[i][j];
					d[i][j] %= mod;
				}
				if (!(j & 1)) {
					d[i + 1][(j >> 1) + (1 << (m - 1))] += d[i][j];
					d[i][j] %= mod;
				}
			}
		}
	}
	printf("%d\n", d[n*m][0] %=mod);
	return 0;
}
