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
int arr[6][6] = { {10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0} };
char board[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main() {
	int n, m; scanf("%d %d", &n, &m);
	MCMF mf(n*m*2,n*m*2-10,n*m*2-11);
	for (int i = 0; i < n; i++) scanf(" %s", &board[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mf.add_edge_to_sink(i*m + j, 1, 0);
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
				mf.add_edge_from_source(i*m + j, 1, 0);
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < m) {
						mf.add_edge(i*m + j, nx*m + ny, 1, -arr[board[i][j] - 'A'][board[nx][ny] - 'A']);
					}
				}
			}
		}
	}
	pair<int, int> ans = mf.flow();
	printf("%d\n", -ans.second);
}