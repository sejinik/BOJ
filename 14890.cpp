#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, l;
int map[111][111];
bool rc[111][111];
bool cc[111][111];
bool r(int x) {
	for (int i = 0; i < n-1; i++) {
		int diff = map[x][i] - map[x][i + 1];
		if (diff == 0) continue;
		if (diff != 1 && diff != -1) return false;
		if (diff == -1) {
			int pos = i - l + 1;
			if (pos < 0) return false;
			while (map[x][pos] == map[x][i] && pos < i) {
				if (rc[x][pos]) return false;
				rc[x][pos] = true;
				pos++;
			}
			if (pos != i || rc[x][pos]) return false;
			rc[x][pos] = true;
		}
		else {
			int pos = i + 1, len = 0;
			while (map[x][pos] == map[x][i + 1] && len < l) {
				if (rc[x][pos]) return false;
				rc[x][pos] = true;
				pos++, len++;
			}
			if (pos > n || len != l) return false;
			i = i + l - 1;
		}
	}
	return true;
}
bool c(int x) {
	for (int i = 0; i < n - 1; i++) {
		int diff = map[i][x] - map[i+1][x];
		if (diff == 0) continue;
		if (diff != 1 && diff != -1) return false;
		if (diff == -1) {
			int pos = i - l + 1;
			if (pos < 0) return false;
			while (map[pos][x] == map[i][x] && pos < i) {
				if (cc[pos][x]) return false;
				cc[pos][x] = true;
				pos++;
			}
			if (pos != i || cc[pos][x]) return false;
			cc[pos][x] = true;
		}
		else {
			int pos = i + 1, len = 0;
			while (map[pos][x] == map[i + 1][x] && len < l) {
				if (cc[pos][x]) return false;
				cc[pos][x] = true;
				pos++, len++;
			}
			if (pos > n || len != l) return false;
			i = i + l - 1;
		}
	}
	return true;
}
int main() {
	scanf(" %d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &map[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (r(i)) ans += 1;
		if (c(i)) ans += 1; 
	}
	printf("%d\n", ans);
}