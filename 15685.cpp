#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool map[111][111];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void go(int x, int y, int d, int g) {
	int nx = x, ny = y;
	map[nx][ny] = 1;
	if (0 <= nx + dx[d] &&nx+dx[d] <= 100 && 0 <= ny + dy[d] && ny+dy[d]<= 100)
		map[nx + dx[d]][ny + dy[d]] = 1;
	vector<int> vt;
	vt.push_back(d);
	int c = 1;
	while (g--) c *= 2;
	while (vt.size() != c) {
		int n = vt.size();
		for (int i = n - 1; i >= 0; i--) {
			vt.push_back((vt[i] + 1) % 4);
		}
		int s = (n == 1) ? 0 : n;
		for (int i = s; i < vt.size(); i++) {
			map[nx][ny] = 1;
			nx += dx[vt[i]];
			ny += dy[vt[i]];
			map[nx][ny] = 1;
		}
	}
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		scanf(" %d %d %d %d", &y, &x, &d, &g);
		go(x, y, d, g);
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) ans++;
		}
	}
	printf("%d\n", ans);
}