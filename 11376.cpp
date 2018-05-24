#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct MaximumFlow {
	int n;
	int source, sink;
	vector<vector<int>>graph;
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
	int n, m;
	scanf("%d %d", &n, &m);
	MaximumFlow mf(max(n, m));
	for (int i = 0; i < n; i++) {
		int cnt; scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int job; scanf("%d", &job);
			mf.add_edge(i, job - 1);
		}
	}
	printf("%d\n", mf.flow());
	return 0;
}