#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
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

int n, p,inf=1e9;
int arr[55][55];
int main() {
	scanf(" %d %d", &n, &p);
	MCMF mf(n * 2 + 4, n * 2 + 1, n * 2 + 2);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int x; scanf(" %d", &x);
			mf.add_edge(i + n, j, arr[i][j], -x);
			mf.add_edge(i + n, j, p, 0);
		}
	}
	for (int i = 0; i < n; i++) mf.add_edge(i, i + n, p, 0);
	mf.add_edge_from_source(0, inf, 0);
	mf.add_edge_to_sink(n * 2 - 1, inf, 0);
	pair<int, int> ans = mf.flow();
	printf("%d\n", -ans.second);
}