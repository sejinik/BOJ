#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct MaximumFLow {
	struct Edge {
		int to;
		int capacity;
		Edge * rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {

		}
	};
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	MaximumFLow(int n, int source, int sink) :n(n), source(source), sink(sink) {
		graph.resize(n);
	}
	void add_Edge(int u, int v, int cap) {
		Edge * ori = new Edge(v, cap);
		Edge * rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int bfs() {
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
			if (c > graph[from[x].first][from[x].second]->capacity)
				c = graph[from[x].first][from[x].second]->capacity;
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
		while (true) {
			int f = bfs();
			if (f == 0)break;
			ans += f;
		}
		return ans;
	}
};

int cow, house;
int main() {
	scanf("%d %d", &cow, &house);
	MaximumFLow mf(cow + house + 2, 0, cow + house + 1);
	for (int i = 1; i <= cow; i++) {
		mf.add_Edge(0, i, 1);
	}
	for (int i = cow + 1; i <= cow + house; i++) {
		mf.add_Edge(i, cow + house + 1,1);
	}
	for (int i = 1; i <= cow; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; j++) {
			int num;
			scanf("%d", &num);
			mf.add_Edge(i, cow + num, 1);
		}
	}
	printf("%d\n", mf.flow());
	return 0;
}