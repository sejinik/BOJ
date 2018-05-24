#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int INF = 1e+9;
int d[(1 << 15)][15];
int map[15][15];
int n;

int main() {
	for (int i = 0; i < (1 << 15); i++) {
		for (int j = 0; j < 15; j++) {
			d[i][j] = INF;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1d", &map[i][j]);
		}
	}

	d[1][0] = 0;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 1; j < n; j++) {
			if (!(i&(1 << j))) {
				for (int k = 0; k < n; k++) {
					if ((i&(1 << k)) && k != j && d[i][k] <= map[k][j]) {
						d[i | (1 << j)][j] = min(d[i | (1 << j)][j], map[k][j]);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < 15; j++) {
			if (d[i][j] != INF) {
				int cnt = 0;
				for (int k = 1; k < (1 << n); k *= 2) {
					if (i&k) cnt += 1;
				}
				ans = max(ans, cnt);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}