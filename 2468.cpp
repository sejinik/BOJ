#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int visited[105][105];
int arr[105][105];

int high[105];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int cnt;
int m_cnt;

void dfs(int x,int y, int high, int num) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (1 <= nx && nx <= num && 1 <= ny && ny <= num) {
			if (arr[nx][ny] > high && visited[nx][ny] == 0) {
				dfs(nx, ny, high, num);
			}
		}
	}
}

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			scanf("%d", &arr[i][j]);
			high[arr[i][j]]++;
		}
	}
	
	for (int k = 1; k <= 101; k++) {
		if (high[k] != 0) {
			for (int i = 1; i <= num; i++) {
				for (int j = 1; j <= num; j++) {
					if (visited[i][j] == 0 && arr[i][j] > k) {
						dfs(i, j, k,num);
						cnt++;
					}
				}
			}
			m_cnt = max(m_cnt, cnt);
			cnt=0 ;
			memset(visited, 0, sizeof(visited));
		}
	}

	if (m_cnt == 0)
		printf("1\n");
	else
	printf("%d\n", m_cnt);

	return 0;
}