#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

queue <pair<int, int>> q;

int arr[1001][1001];
bool check[1001][1001];
int day;
int sum;
int cnt;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int M, int N) {
	int x, y;
	while (int s = q.size()) {
		while (s--) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (arr[nx][ny] == 0 && check[nx][ny] == false) {
						q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
		}
		day++;
	}
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && check[i][j] == false) {
				check[i][j] = true;
				q.push(make_pair(i, j));
			}
				
		}
	}
	dfs(M, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == true)
				sum++;

			else if (arr[i][j] == -1)
				cnt++;
		}
	}
	if (sum == N*M || sum + cnt == N*M)
		printf("%d\n", day - 1);

	else if (sum + cnt != N*M) {
		printf("%d\n", -1);
	}
	else
		printf("%d\n", 0);
	
	return 0;
}
