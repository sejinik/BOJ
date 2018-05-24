#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int map[505][505];

int go1(int x, int y) {
	int ret = 0;
	if (y + 3 < m) {
		int sum = 0;
		for (int i = y; i <= y + 3; i++) 
			sum += map[x][i];
		ret = max(ret, sum);
	}
	if (x + 3 < n) {
		int sum = 0;
		for (int i = x; i <= x + 3; i++)
			sum += map[i][y];
		ret = max(ret, sum);

	}
	return ret;
}

int go2(int x, int y) {
	int ret = 0;
	if (x + 1 < n && y + 1 < m) {
		int sum = map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1];
		ret = max(ret, sum);
	}
	return ret;
}

int go3(int x, int y) {
	int ret = 0;
	if (x + 2 < n) {
		int sum = map[x][y] + map[x + 1][y] + map[x + 2][y];
		if (0 <= y - 1) ret = max({ ret,sum + map[x][y - 1],sum + map[x + 2][y - 1] });
		if (y + 1 < m) ret = max({ ret,sum + map[x][y + 1],sum + map[x + 2][y + 1] });
	}
	if (y + 2 < m) {
		int sum = map[x][y] + map[x][y + 1] + map[x][y + 2];
		if (0 <= x - 1) ret = max({ ret,sum + map[x - 1][y],sum + map[x - 1][y + 2] });
		if (x + 1 < n) ret = max({ ret,sum + map[x + 1][y],sum + map[x + 1][y + 2] });
	}
	return ret;
}

int go4(int x, int y) {
	int ret = 0;
	if (y + 1 < m) {
		int sum = map[x][y] + map[x][y + 1];
		if (0 <= x - 1 && x + 1 < n) ret = max({ ret,sum + map[x - 1][y] + map[x + 1][y + 1],sum + map[x - 1][y + 1] + map[x + 1][y] });
	}

	if (x + 1 < n) {
		int sum = map[x][y] + map[x + 1][y];
		if (0 <= y - 1 && y + 1 < m) ret = max({ ret,sum + map[x][y + 1] + map[x + 1][y - 1],sum + map[x][y - 1] + map[x + 1][y + 1] });
	}
	return ret;
}

int go5(int x, int y) {
	int ret = 0;
	if (y + 2 < m) {
		int sum = map[x][y] + map[x][y + 1] + map[x][y + 2];
		if (0 <= x - 1) ret = max(ret, sum + map[x - 1][y + 1]);
		if (x + 1 < n) ret = max(ret, sum + map[x + 1][y + 1]);
	}
	if (x + 2 < n) {
		int sum = map[x][y] + map[x + 1][y] + map[x + 2][y];
		if (0 <= y - 1) ret = max(ret, sum + map[x + 1][y - 1]);
		if (y + 1 < m) ret = max(ret, sum + map[x + 1][y + 1]);
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max({ ans,go1(i,j),go2(i,j),go3(i,j),go4(i,j),go5(i,j) });
		}
	}
	printf("%d\n", ans);
	return 0;
}