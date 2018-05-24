#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char arr[303][303];
int map[303][303];
int d[303][303];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, st, fr, ST, FR;
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d %d %d %d %d", &n, &m, &st, &fr, &ST, &FR);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == '0') continue;
			map[i][j] = 1;
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{st-1,fr-1} });
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[x][y] != -1) continue;
		d[x][y] = cost;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncost = -cost - map[nx][ny];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] == -1) pq.push({ ncost,{nx,ny} });
			}
		}
	}
	printf("%d\n", d[ST - 1][FR - 1]);
	return 0;
}