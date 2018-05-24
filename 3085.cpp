#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char map[55][55];
int n;
int check() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				int cnt = 0;
				for (int k = j; ; k++) {
					if (map[i][k] == map[i][j])  cnt += 1;
					else {
						j = k; break;
					}
				}
				ret = max(ret, cnt);
			}
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				int cnt = 0;
				for (int k = i; ; k++) {
					if (map[k][j] == map[i][j]) cnt += 1;
					else {
						i = k; break;
					}
				}
				ret = max(ret, cnt);
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) scanf(" %s", &map[i]);
	int ans = check();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(map[i][j], map[i][j + 1]);
				ans = max(ans, check());
				swap(map[i][j], map[i][j + 1]);
			}
			if (i + 1 < n) {
				swap(map[i][j], map[i + 1][j]);
				ans = max(ans, check());
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}