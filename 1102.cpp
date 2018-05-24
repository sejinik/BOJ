#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, p;
int w[20][20];
int d[(1 << 16)];
int inf = 1e+9;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		d[i] = inf;
	}
	string str;
	cin >> str;
	scanf("%d", &p);
	int m = str.size();
	int turn_on = 0;
	for (int i = 0; i < m; i++) {
		if (str[i] == 'Y') {
			turn_on |= (1 << i);
		}
	}
	d[turn_on] = 0;
	for (int i = 0; i < (1 << n); i++) {
		if (d[i] == inf) continue;
		for (int j = 0; j < n; j++) {
			if (!(i&(1 << j))) {
				for (int k = 0; k < n; k++) {
					if (i&(1 << k)) {
						if (d[i | (1 << j)] == inf || d[i | (1 << j)] > d[i] + w[k][j])
							d[i | (1 << j)] = d[i] + w[k][j];
					}
				}
			}
		}
	}

	int ans = inf;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) cnt += 1;
		}
		if (cnt >= p)
			ans = min(ans, d[i]);
	}

	if (ans == inf) puts("-1");
	else printf("%d\n", ans);
	return 0;
}