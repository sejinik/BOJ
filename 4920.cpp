#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define NUM -100000000
int n;
int map[101][101];

int go1(int x, int y) {
	int ret = NUM;
	if (y + 3 < n) {
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
	int ret = NUM;
	if (x + 1 < n && y + 1 < n) {
		int sum = map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1];
		ret = max(ret, sum);
	}
	return ret;
}

int go3(int x, int y) {
	int ret = NUM;
	if (x + 2 < n) {
		int sum = map[x][y] + map[x + 1][y] + map[x + 2][y];
		if (0 <= y - 1) ret = max({ ret,sum + map[x + 2][y - 1] });
		if (y + 1 < n) ret = max({ ret,sum + map[x][y + 1] });
	}
	if (y + 2 < n) {
		int sum = map[x][y] + map[x][y + 1] + map[x][y + 2];
		if (0 <= x - 1) ret = max({ ret,sum + map[x - 1][y]});
		if (x + 1 < n) ret = max({ ret,sum + map[x + 1][y + 2] });
	}
	return ret;
}

int go4(int x, int y) {
	int ret = NUM;
	if (x + 1 < n && y + 2 < n) ret = max(ret, map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	if (0 <= y - 1 && x + 2 < n) ret = max(ret, map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 2][y - 1]);
	return ret;
}

int go5(int x, int y) {
	int ret = NUM;
	if (y + 2 < n) {
		int sum = map[x][y] + map[x][y + 1] + map[x][y + 2];
		if (0 <= x - 1) ret = max(ret, sum + map[x - 1][y + 1]);
		if (x + 1 < n) ret = max(ret, sum + map[x + 1][y + 1]);
	}
	if (x + 2 < n) {
		int sum = map[x][y] + map[x + 1][y] + map[x + 2][y];
		if (0 <= y - 1) ret = max(ret, sum + map[x + 1][y - 1]);
		if (y + 1 < n) ret = max(ret, sum + map[x + 1][y + 1]);
	}
	return ret;
}

int main() {

	int cnt = 1;
	while (true) {
		memset(map, 0, sizeof(map));
		scanf(" %d",&n);
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %d", &map[i][j]);
			}
		}

		int ans = NUM;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max({ ans,go1(i,j),go2(i,j),go3(i,j),go4(i,j),go5(i,j) });
			}
		}
		printf("%d. %d\n",cnt++, ans);
	}
}