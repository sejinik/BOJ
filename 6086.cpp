#include <iostream>
#include <string>	
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct MaximunFlow {
	struct Edge {
		int to;
		int capacity;
		Edge * rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {

		};
	};
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	MaximunFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge * ori = new Edge(v, cap);
		Edge * rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int dfs() {
		vector<bool> check(n, false);
		vector<pair<int, int>> from(n, { -1,-1 });
		queue<int> q;
		q.push(source);
		check[source] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
					q.push(graph[x][i]->to);
					check[graph[x][i]->to] = true;
					from[graph[x][i]->to] = { x,i };
				}
			}
		}
		if (!check[sink]) return 0;
		int x = sink;
		int c = graph[from[x].first][from[x].second]->capacity;
		while (from[x].first != -1) {
			if (c > graph[from[x].first][from[x].second]->capacity) {
				c = graph[from[x].first][from[x].second]->capacity;
			}
			x = from[x].first;
		}
		x = sink;
		while (from[x].first != -1) {
			Edge * e = graph[from[x].first][from[x].second];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].first;
		}
		return c;
	}
	int flow() {
		int ans = 0;
		while (1) {
			int f = dfs();
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int m;
int main() {
	scanf("%d", &m);
	MaximunFlow mf(52, 0, 'Z'-'A');
	for (int i = 0; i < m; i++) {
		char c1, c2;
		int cost,n1,n2;
		scanf(" %c %c %d", &c1, &c2, &cost);
		if ('a' <= c1 && c1 <= 'z') 
			n1 = c1 - 'a'+26;
		else 
			n1 = c1 - 'A';
		if ('a' <= c2 && c2 <= 'z') 
			n2 = c2 - 'a'+26;
		else 
			n2 = c2 - 'A';
		mf.add_edge(n1, n2, cost);
		mf.add_edge(n2, n1, cost);
	}
	printf("%d\n", mf.flow());
	return 0;
}