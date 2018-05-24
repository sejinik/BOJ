#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int shark[1010][3];
struct MaximumFlow {
	int n;
	int source, sink;
	vector<vector<int>> graph;
	vector<bool> check;
	vector<int> pred;
	MaximumFlow(int n) : n(n) {
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
			for (int j = 0; j < 2; j++) {
				fill(check.begin(), check.end(), false);
				if (dfs(i)) ans += 1;
			}
		}
		return ans;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	MaximumFlow mf(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &shark[i][0], &shark[i][1], &shark[i][2]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((shark[i][0] == shark[j][0]) && (shark[i][1] == shark[j][1]) && (shark[i][2] == shark[j][2])) {
				if (i > j) mf.add_edge(i, j); continue;
			}
			if ((shark[i][0] >= shark[j][0]) && (shark[i][1] >= shark[j][1]) && (shark[i][2] >= shark[j][2])) mf.add_edge(i, j);
		}
	}
	printf("%d\n", n - mf.flow());
	return 0;
}