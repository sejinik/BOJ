#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int t, n, m,fs,fc,ss,sc;
int map[111][111], d[111][111][3], sum[111][111];
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
void ds(int a, int b, int order) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{a,b} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (d[x][y][order] != -1) continue;
		d[x][y][order] = cost;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncost = (map[nx][ny] == '#') ? -cost - 1 : -cost;
			if (0 <= nx && nx <= n + 1 && 0 <= ny && ny <= m+1) {
				if (map[nx][ny] == '*') continue;
				if (d[nx][ny][order] == -1) pq.push({ ncost,{nx,ny} });
			}
		}
	}
}
int main() {
	scanf(" %d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(sum, 0, sizeof(sum));
		memset(d, -1, sizeof(d));
		fs = 0;
		scanf(" %d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '$') {
					if (fs == 0) fs = i, fc = j;
					else ss = i, sc = j;
				}
			}
		}
		ds(0, 0, 0);
		ds(fs, fc, 1);
		ds(ss, sc, 2);
		int ans = 1e9;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k < 3; k++) sum[i][j] += d[i][j][k];
				if (map[i][j] == '#') sum[i][j] -= 2;
				if (map[i][j] == '*') continue;
				ans = min(ans, sum[i][j]);
			}
		}
		printf("%d\n", ans);
	}
}