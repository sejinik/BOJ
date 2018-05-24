#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[105][105];
bool visited[105][105];

int m, n, k;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int x, int y) {
	visited[x][y] = true;
	int ans = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (arr[nx][ny]) continue;
		if (visited[nx][ny]) continue;

		ans += dfs(nx, ny);
	}
	return ans;
}

int main() {
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				arr[j][i] = true;
			}
		}
	}


	vector<int> vt;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) {
				if (!visited[i][j]) {
					int temp = dfs(i, j);
					vt.push_back(temp);
				}
			}
		}
	}

	sort(vt.begin(), vt.end());
	printf("%d\n", vt.size());

	for (int i = 0; i < vt.size(); i++) {
		printf("%d ", vt[i]);
	}
	printf("\n");
	return 0;
}