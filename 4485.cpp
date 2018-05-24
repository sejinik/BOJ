#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

bool visited[130][130];
int arr[130][130];
int dist[130][130];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 1;

int main() {
	while (1) {
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		memset(dist, -1, sizeof(dist));
		scanf("%d", &n);

		if (n == 0) return 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -arr[0][0],{0,0} });


		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();

			visited[x][y] = true;
			
			if (dist[x][y] != -1)
				continue;
			dist[x][y] = cost;
			if (x == n - 1 && y == n - 1) break;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int ncost =  -arr[nx][ny] - cost;

				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (!visited[nx][ny]) {
						pq.push({ ncost,{nx,ny} });
					}
				}
			}
		}
		printf("Problem %d: %d\n",cnt++,dist[n-1][n-1]);
	}
	

}