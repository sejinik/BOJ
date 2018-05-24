#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1010][1010];
int dist[1010][1010];
int S;

void bfs(int _s, int _c) {
	queue<pair<int, int>> q;
	visited[_s][_c] = true;
	dist[_s][_c] = 1;
	q.push({ _s,_c });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == S) return; 

		if (x < 1 && x>1000 && y < 0 && y>1000) continue;

			if (!visited[x][x]) {
				visited[x][x] = true;
				dist[x][x] = dist[x][y] + 1;
				q.push({ x,x });
			}

			if (x + y <= 1000 && y != 0) {
				if (!visited[x + y][y]) {
					visited[x + y][y] = true;
					dist[x + y][y] = dist[x][y] + 1;
					q.push({ x + y,y });
				}
			}

			if (x - 1 >= 1) {
				if (!visited[x - 1][y] && x - 1 >= 1) {
					visited[x - 1][y] = true;
					dist[x - 1][y] = dist[x][y] + 1;
					q.push({ x - 1,y });
				}
			}
		}
	}
	


int main() {
	scanf("%d", &S);

	bfs(1, 0);

	int ans = 987654321;
	for (int i = 0; i <= S; i++) {
		if(dist[S][i] != 0)
			ans = min(ans, dist[S][i]);
	}
	printf("%d\n", ans-1);

	return 0;
}