#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int arr[111][111];
int dist[111][111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	memset(dist, -1, sizeof(dist));
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1) arr[i][j] = 5000;
		}
	}
	
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({0,{0,0} });
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		
		if (dist[x][y] != -1) continue;
		dist[x][y] = cost;
		if (dist[n - 1][m - 1] != -1) break;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncost = -cost - arr[nx][ny];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist[nx][ny] != -1) continue;
				pq.push({ ncost,{nx,ny} });
			}
		}
	}

	dist[n - 1][m - 1] /= 5000;
	cout << dist[n - 1][m - 1] << "\n";
	return 0;
}