#include <iostream>
#include<algorithm>
#include <utility>	
#include <queue>
using namespace std;


int arr[102][102];
int check[102][102];
int dist;
int min_dist;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y, int N, int M) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = 1;

	while (int s = q.size()) {
		while (s--) {
			x = q.front().first;
			y = q.front().second;
			if (x == N && y == M)
				return;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
					if (arr[nx][ny] == 1 && check[nx][ny] == 0) {
						q.push(make_pair(nx, ny));
						check[nx][ny] = 1;
					}
				}
			}
		}
		dist++;
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs(1, 1, N, M);
	printf("%d\n", dist+1);
	return 0;
}