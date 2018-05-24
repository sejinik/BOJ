#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int d[55][55];
int map[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int from_x, from_y, to_x, to_y;
bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}
void Cost_change(int x, int y) {
	map[x][y] = 5000;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inRange(nx,ny) && map[nx][ny] != -1 && map[nx][ny] != 5000) map[nx][ny] = 1;
	}
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; scanf(" %1c", &c);
			if (c == 'g') Cost_change(i, j);
			else if (c == 'S') {
				map[i][j] = -1;
				from_x = i;
				from_y = j;
			}
			else if (c == 'F') {
				map[i][j] = -1;
				to_x = i;
				to_y = j;
			}
		}
	}
	map[from_x][from_y] = map[to_x][to_y] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{from_x,from_y} });
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[x][y] != -1) continue;
		d[x][y] = cost;

		if (x == to_x && y == to_y) break;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inRange(nx, ny)) {
				int ncost = -cost - map[nx][ny];
				if (d[nx][ny] == -1) pq.push({ ncost,{nx,ny} });
			}
		}
	}
	printf("%d %d\n", d[to_x][to_y] / 5000, d[to_x][to_y] % 5000);
	return 0;
}