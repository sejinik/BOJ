#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct MaximumFlow {
	int n;
	vector<vector<int>> graph;
	vector<bool> check;
	vector<int> pred;
	MaximumFlow(int n) :n(n) {
		graph.resize(n);
		check.resize(n);
		pred.resize(n, -1);
	}
	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];
			if (check[next]) continue;
			check[next] = true;
			if (dfs(pred[next])) {
				pred[next] = x;
				return true;
			}
		}
		return false;
	}
	int flow() {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), 0);
			if (dfs(i)) ans += 1;
		}
		return ans;
	}
};
int n, m;
char map[55][55];
int arr[2][55][55];
int cnt[2];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int main() {
	memset(arr, -1, sizeof(arr));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf(" %s", &map[i]);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[j][k] == '*' && arr[i][j][k] == -1) {
					int x = j;
					int y = k;
					while (0 <= x && x < n && 0 <= y && y < m && map[x][y]=='*') {
						arr[i][x][y] = cnt[i];
						x += dx[i];
						y += dy[i];
					}
					cnt[i]++;
				}
			}
		}
	}
	MaximumFlow mf(max(cnt[0], cnt[1]));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') mf.add_edge(arr[0][i][j], arr[1][i][j]);
		}
	}
	printf("%d\n", mf.flow());
}