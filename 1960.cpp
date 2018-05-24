#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x, int c) {
        if (check[x]) return 0;
        check[x] = true;
        if (x == sink) {
            return c;
        }
        for (int i=0; i<graph[x].size(); i++) {
            if (graph[x][i]->capacity > 0) {
                int nc = graph[x][i]->capacity;
                if (c != 0 && c < nc) {
                    nc = c;
                }
                int f = dfs(graph[x][i]->to, nc);
                if (f) {
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ans = 0;
        while (true) {
            fill(check.begin(),check.end(),false);
            int f = dfs(source, 0);
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};

int map[555][555];

int main() {
	int n; scanf("%d", &n);
	MaximumFlow mf(555,0,n*2+1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mf.add_edge(i, j + n,1);

	int r = 0, c = 0;
	for (int i = 1; i <= n*2; i++) {
		int cap; scanf(" %d", &cap);
		if (i <= n) mf.add_edge(0, i, cap), r += cap;
		else mf.add_edge(i, n * 2 + 1, cap), c += cap;
	}

	int ans = mf.flow();
	int end_from = 0;
	int end_to = 0;
	for (int i = 0; i < mf.graph[0].size(); i++) end_from += mf.graph[0][i]->rev->capacity;
	for (int i = 0; i < mf.graph[n * 2 + 1].size(); i++) end_to += mf.graph[n * 2 + 1][i]->capacity;
	if ((ans == end_from) && (ans == end_to) &&(r==c) &&(r==ans)) {
		puts("1");
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < mf.graph[i].size()-1; j++) {
				if (mf.graph[i][j]->capacity == 1) map[i][mf.graph[i][j]->to-n] = 1;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d", !map[i][j]);
			}
			printf("\n");
		}
	}
	else puts("-1");
}