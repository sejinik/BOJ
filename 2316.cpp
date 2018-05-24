#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Dinic {
	struct Edge {
		int to, cap, flow;
		Edge* rev;
		Edge(int to, int cap) : to(to), cap(cap), flow(0), rev(0) {}
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
	scanf("%d %d", &n, &m);
	Dinic mf(n * 2+2, 1, 2+n);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		mf.add_edge(a + n, b, inf);
		mf.add_edge(b + n, a, inf);
	}
	mf.add_edge(1, 1 + n, inf);
	mf.add_edge(2, 2 + n, inf);
	for (int i = 3; i <= n; i++) mf.add_edge(i, i + n, 1);
	printf("%d\n", mf.flow());
}