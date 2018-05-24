#include <iostream>
#include <cstring>
using namespace std;

char arr1[110][110];
bool visited1[110][110];
bool visited2[110][110];

int N;
int cnt1;
int cnt2;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs1(int x, int y) { // 적록색약
	visited1[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visited1[nx][ny]) continue;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (arr1[nx][ny] != arr1[x][y]) continue;

		dfs1(nx, ny);
	}
}

void dfs2(int x, int y) {
	visited2[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visited2[nx][ny]) continue;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

		if (arr1[x][y] == 'R') 
			if (arr1[nx][ny] == 'B') continue;
		if (arr1[x][y] == 'G')
			if (arr1[nx][ny] == 'B') continue;
		if (arr1[x][y] == 'B')
			if (arr1[x][y] != arr1[nx][ny]) continue;
		
		dfs2(nx, ny);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr1[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited1[i][j]) {
				dfs1(i, j);
				cnt1++;
			}

			if (!visited2[i][j]) {
				dfs2(i, j);
				cnt2++;
			}
		}
	}

	printf("%d ", cnt1);
	printf("%d\n", cnt2);
	return 0;


	
}