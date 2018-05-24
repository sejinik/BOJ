#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char arr[30][30];
bool visited[30][30];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;

int dfs(int x, int y) {
	int ans = 1;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (arr[nx][ny] == '0') continue;

		ans += dfs(nx, ny);
	}

	return ans;
}
int main() {
	vector<int> vt;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1') {
				if (!visited[i][j]) {
					int ans = dfs(i, j);
					vt.push_back(ans);
				}
			}
		}
	}

	sort(vt.begin(), vt.end());
	printf("%d\n", vt.size());
	
	for (int i = 0; i < vt.size(); i++) {
		printf("%d\n", vt[i]);
	}
	return 0;
}