#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct MaximumFlow {
	int n;
	vector<vector<int>> graph;
	vector<bool> check;
	vector<int> pred;
	MaximumFlow(int n) : n(n) {
		graph.resize(n);
		check.resize(n);
		pred.resize(n,-1);
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
int map[111][111];
int arr[2][111][111];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int cnt[2];

int main() {
	memset(arr, -1, sizeof(arr));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &map[i][j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[j][k] == 0 && arr[i][j][k] == -1) {
					int x = j;
					int y = k;
					while (0 <= x && x < n && 0 <= y && y < m && map[x][y] != 2) {
						if (map[x][y] == 0) arr[i][x][y] = cnt[i];
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
			if (map[i][j] == 0) mf.add_edge(arr[0][i][j], arr[1][i][j]);
		}
	}
	printf("%d\n", mf.flow());
}