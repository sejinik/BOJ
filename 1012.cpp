#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int arr[51][51];
bool check[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt;
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx <= 49 && 0 <= ny && ny <= 49) {
			if (arr[nx][ny] == 1 && check[nx][ny] == false)
				dfs(nx, ny);
		}
	}
	
}

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int M, N, K;
		scanf("%d %d %d", &M, &N, &K);

		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		cnt = 0;

		for (int i = 1; i <= K; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}