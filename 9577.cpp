#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct MaximumFlow {
	int n,p;
	int source, sin;
	vector<vector<int>> graph;
	vector<bool> check;
	vector<int> pred;
	MaximumFlow(int n,int p) : n(n) ,p(p) {
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
	bool can() {
		for (int i = 0; i < p; i++) if (pred[i] == -1) return false;
		return true;
	}
	int flow() {
		int ans = 0;
		int pos = -1;
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i)) {
				ans += 1; 
				if (ans == p) {
					if (can()) {
						pos = i + 1; break;
					}
				}
			}
		}
		return pos;
	}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int m, n, t1, t2, a,num; 
		scanf("%d %d", &n, &m);
		MaximumFlow mf(111,n);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &t1, &t2,&a);
			while (a--) {
				scanf("%d", &num);
				for (int j = t1; j < t2; j++) mf.add_edge(j, num-1);
			}
		}
		printf("%d\n", mf.flow());
	}
	return 0;
}