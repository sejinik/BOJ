#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[110][110][110];
bool check[110][110][110];

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int M, N, H;
int day;

queue<pair<pair<int, int>, int>> q;
void dfs() {
	
	while (int s = q.size()) {
		while (s--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < M && 0 <= nz && nz < H) {
					if (!check[nx][ny][nz] && arr[nx][ny][nz] != -1) {
						check[nx][ny][nz] = true;
						arr[nx][ny][nz] = 1;
						q.push({ { nx,ny }, nz });
					}
				}
			}
		}
		day++;
	}
}

int main() {
	scanf("%d%d%d", &M, &N, &H);

	bool already = true;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[i][j][k]);

				if (arr[i][j][k] == 1) {
					check[i][j][k] = true;
					q.push({ { i,j }, k });
				}
				
				if (arr[i][j][k] == 0)
					already = false;
			}
		}
	}

	if (already) {
		puts("0");
		return 0;
	}

	dfs();
	
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j][k] == 0) {
					puts("-1");
					return 0;
				}
			}
		}
	}

	printf("%d\n", day-1);
	return 0;
}