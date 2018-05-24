#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct MCMF {
	struct Edge {
		int to, cap, cost;
		Edge*rev;
		Edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {}
	};
	int n;
	int source, sink;
	vector<vector<Edge*>> Graph;
	vector<bool> check;
	vector<int> dist;
	vector<pair<int, int>> from;
	int inf = 1e9;
	MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
		Graph.resize(n);
		check.resize(n);
		from.resize(n, { -1,-1 });
		dist.resize(n);
	}
	void add_edge(int u, int v, int cap, int cost) {
		Edge* ori = new Edge(v, cap, cost);
		Edge*rev = new Edge(u, 0, -cost);
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
	bool spfa(int&total_flow, int &total_cost) {
		fill(check.begin(), check.end(), false);
		fill(dist.begin(), dist.end(), inf);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		dist[source] = 0;
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int x = q.front();
			q.pop(); check[x] = false;
			for (int i = 0; i < Graph[x].size(); i++) {
				auto e = Graph[x][i];
				int y = e->to;
				if (e->cap > 0 && dist[x] + e->cost < dist[y]) {
					dist[y] = dist[x] + e->cost;
					from[y] = { x,i };
					if (!check[y]) {
						check[y] = true; q.push(y);
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
		total_flow += c;
		total_cost += c*dist[sink];
		return true;
	}
	pair<int, int> flow() {
		int total_flow = 0;
		int total_cost = 0;
		while (spfa(total_flow, total_cost));
		return { total_flow,total_cost };
	}
};

int main() {
	int t; scanf(" %d", &t);
	while (t--) {
		int n, m; scanf(" %d %d", &n, &m);
		MCMF mf(2*n+m+5,2*n+m+3,2*n+m+4);
		vector<int> cost(n + m + 1);
		vector<pair<pair<int, int>, pair<int, int>>> line(n + m + 1);
		for (int i = 1; i <= n + m; i++) {
			int a, b, c, d; scanf(" %d %d %d %d %d", &a, &b, &c, &d,&cost[i]);
			line[i].first.first = min(a, c);
			line[i].second.first = max(a, c);
			line[i].first.second = min(b, d);
			line[i].second.second = max(b,d);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = n + 1; j <= n + m; j++) {
				auto x = line[i], y = line[j];
				if (x.first.first <= y.first.first && y.first.first <= x.second.first) {
					if (y.first.second <= x.first.second && x.first.second <= y.second.second) {
						mf.add_edge(i+n, j+n, 1, -(cost[i] * cost[j]));
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) mf.add_edge(i, i + n, 1, 0);
		for (int i = 1; i <= n; i++) mf.add_edge_from_source(i, 1, 0);
		for (int i = 1+n; i <= n + m; i++) mf.add_edge_to_sink(i+n, 1, 0);
		pair<int, int> ans = mf.flow();
		printf("%d %d\n", ans.first, -ans.second);
	}
}