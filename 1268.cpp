#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int map[1010][5];
int ans[1010];
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %d", &map[i][j]);
		}
	}

	int maxc = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < 5; k++) {
				if (map[i][k] == map[j][k]) {
					ans[i]++; break;
				}
			}
		}
		maxc = max(maxc, ans[i]);
	}

	for (int i = 0; i < n; i++) {
		if (maxc == ans[i]) return !printf("%d\n", i + 1);
	}
}