#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct MCMF {
	struct Edge {
		int to, cap, cost;
		Edge* rev;
		Edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost){}
	};
	int n, source, sink;
	int inf = 1e9;
	vector<vector<Edge*>> Graph;
	vector<bool> check;
	vector<int> dist;
	vector<pair<int, int>> from;
	MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
		Graph.resize(n);
		check.resize(n);
		dist.resize(n);
		from.resize(n, { -1,-1 });
	}
	void add_edge(int u, int v, int cap, int cost) {
		Edge* ori = new Edge(v, cap, cost);
		Edge* rev = new Edge(u, 0, -cost);
		ori->rev = rev;
		rev->rev = ori;
		Graph[u].push_back(ori);
		Graph[v].push_back(rev);
	}
	void add_edge_from_source(int v, int cap, int cost) {
		add_edge(source, v, cap, cost);
	}
	void add_edge_to_sink(int u, int cap, int cost) {
		add_edge(u, sink, cap, cost);
	}
	bool spfa(int&tf, int&tc) {
		fill(check.begin(), check.end(), false);
		fill(dist.begin(), dist.end(), inf);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		queue<int> q;
		q.push(source); check[source] = true; 
		dist[source] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			check[x] = false;
			for (int i = 0; i < Graph[x].size(); i++) {
				auto e = Graph[x][i];
				int y = e->to;
				if (e->cap > 0 && dist[y] > dist[x] + e->cost) {
					dist[y] = dist[x] + e->cost;
					from[y] = { x,i };
					if (!check[y]) {
						q.push(y); check[y] = true;
					}
				}
			}
		}
		if (dist[sink] == inf) return false;
		int x = sink;
		int c = Graph[from[x].first][from[x].second]->cap;
		while (from[x].first != -1) {
			c = min(c, Graph[from[x].first][from[x].second]->cap);
			x = from[x].first;
		}
		x = sink;
		while (from[x].first != -1) {
			auto e = Graph[from[x].first][from[x].second];
			e->cap -= c;
			e->rev->cap += c;
			x = from[x].first;
		}
		tf += c;
		tc += c*dist[sink];
		return true;
	}
	pair<int, int> flow() {
		int tf = 0, tc = 0;
		while (spfa(tf, tc));
		return { tf,tc };
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int inf = 1e9;
	MCMF mf(n + m + 3, n + m + 1, n + m + 2);
	for (int i = 1; i <= n; i++) {
		int x; scanf(" %d", &x);
		mf.add_edge_to_sink(i, x, 0);
	}
	for (int i = n + 1; i <= n + m; i++) {
		int x; scanf(" %d", &x);
		mf.add_edge_from_source(i, x, 0);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int x; scanf(" %d", &x);
			mf.add_edge(i + n, j, inf, x);
		}
	}
	pair<int, int> ans = mf.flow();
	printf("%d\n", ans.second);
}