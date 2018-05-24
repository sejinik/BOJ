#include <iostream>
#include <algorithm>	
#include <cstring>
using namespace std;
#define inf -1e9
int n, m;
int map[1010][1010];
int d[1010][1010][3];
bool check[1010][1010];
int dx[3] = { 1,0,0 };
int dy[3] = { 0,-1,1 };

int go(int x, int y, int dir) {
	if (check[x][y]) return inf;
	if (x == n - 1 && y == m - 1) return map[x][y];
	int&ret = d[x][y][dir];
	if (ret != inf) return ret;
	check[x][y] = true;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			ret = max(ret, go(nx, ny, i) + map[x][y]);
		}
	}
	check[x][y] = false;
	return ret;
}
int main() {
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			for (int k = 0; k < 3; k++) {
				d[i][j][k] = inf;
			}
		}
	}

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &map[i][j]);
		}
	}
	printf("%d\n", go(0, 0, 0));
}