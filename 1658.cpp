#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Dinic {
	struct Edge {
		int to, cap, flow;
		Edge* rev;
		Edge(int to, int cap) : to(to), cap(cap), flow(0), rev(0){}
		inline int residual() {
			if (flow < 0) return -flow;
			return cap - flow;
		}
	};
	const int inf = 1e+9;
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<int> lev;
	vector<int> idx;
	Dinic(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		lev.resize(n);
		idx.resize(n);
	}
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	bool bfs() {
		fill(lev.begin(), lev.end(), -1);
		lev[source] = 0;
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < graph[here].size(); i++) {
				int next = graph[here][i]->to;
				int sub = graph[here][i]->residual();
				if (lev[next] == -1 && sub > 0) {
					lev[next] = lev[here] + 1;
					q.push(next);
				}
			}
		}
		return lev[sink] == -1;
	}
	int dfs(int here, int amount) {
		if (here == sink) return amount;
		for (int &i = idx[here]; i < graph[here].size(); i++) {
			int next = graph[here][i]->to;
			int sub = graph[here][i]->residual();
			if (lev[next] == lev[here] + 1 && sub > 0) {
				int c = dfs(next, min(sub, amount));
				if (c > 0) {
					graph[here][i]->flow += c;
					graph[here][i]->rev->flow -= c;
					return c;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (true) {
			fill(idx.begin(), idx.end(), 0);
			if (bfs()) break;
			while (true) {
				int c = dfs(source, inf);
				if (c == 0) break;
				ans += c;
			}
		}
		return ans;
	}
};

int n, m;
const int inf = 1e+9;

int main() {
	scanf(" %d %d", &m, &n);
	Dinic mf(n + 2, 0, n + 1);
	vector<int> cnt(m + 1);
	for (int i = 1; i <= m; i++) scanf("%d", &cnt[i]);
	vector<vector<int>> keys(m + 1);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int w; scanf("%d", &w);
			keys[w].push_back(i);
		}
		scanf("%d", &a);
		mf.add_edge(i, n + 1, a);
	}
	for (int i = 1; i <= m; i++) {
		if (keys[i].empty()) continue;
		for (int j = 0; j < keys[i].size()-1; j++) {
			mf.add_edge(keys[i][j], keys[i][j + 1], inf);
		}
		mf.add_edge(0, keys[i][0], cnt[i]);
	}
	printf("%d\n", mf.flow());
	return 0;
}