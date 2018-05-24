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
char map[111][111];
bool check[111][111];
int d[111][111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

int main() {
	while (scanf(" %d %d", &n, &m) != -1) {
		if (n == 0 && m == 0) return 0;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) scanf(" %s", &map[i]);
		MCMF mf(n*m + 3, n*m + 1, n*m + 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'm') {
					mf.add_edge_from_source(i*m + j, 1, 0);
					memset(check, 0, sizeof(check));
					memset(d, 0, sizeof(d));
					queue<pair<int, int>> q;
					q.push({ i,j }); check[i][j] = true;
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						if (map[x][y] == 'H') mf.add_edge(i*m + j, x*m+y, 1, d[x][y]);
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (0 <= nx && nx < n && 0 <= ny && ny < m) {
								if (!check[nx][ny]) {
									check[nx][ny] = true;
									d[nx][ny] = d[x][y] + 1;
									q.push({ nx,ny });
								}
							}
						}
					}
				}
				else if (map[i][j] == 'H') mf.add_edge_to_sink(i*m + j, 1, 0);
			}
		}
		pair<int, int> ans = mf.flow();
		printf("%d\n",ans.second);
	}
}