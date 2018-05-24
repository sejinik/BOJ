#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct MaximunFlow {
	int n,k;
	int source, sink;
	vector<vector<int>> graph;
	vector<bool> check;
	vector<int> pred;
	MaximunFlow(int n,int k) : n(n), k(k) {
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
		int fir = 0, sec = 0;
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i)) fir += 1;
		}
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i)) sec += 1;
		}
		if (sec <= k) return fir + sec;
		else return fir + k;
	}
};

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	MaximunFlow mf(max(n, m), k);
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