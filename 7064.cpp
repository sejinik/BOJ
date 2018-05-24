#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Biprate {
	int n;
	vector<vector<int>> Graph;
	vector<bool> check;
	vector<int> pred;
	Biprate(int n) : n(n) {
		Graph.resize(n);
		check.resize(n);
		pred.resize(n, -1);
	}
	void add_edge(int u, int v) {
		Graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1)return true;
		for (int i = 0; i < Graph[x].size(); i++) {
			int next = Graph[x][i];
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
			fill(check.begin(), check.end(), false);
			if (dfs(i)) ans += 1;
		}
		return ans;
	}
};

int main() {
	int t; scanf(" %d", &t);
	while (t--) {
		int n, m; scanf(" %d %d", &n, &m);
		Biprate mf(n * 2);
		for (int i = 0; i < m; i++) {
			int x, y; scanf(" %d %d", &x, &y);
			x--; y--;
			mf.add_edge(x, y + n);
		}
		printf("%d\n", n - mf.flow());
	}
}