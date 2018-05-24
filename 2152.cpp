#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 100000
int num[MAX + 1];
int low[MAX + 1];
bool check[MAX + 1];
int com[MAX + 1];
int dist[MAX + 1];
int ind[MAX + 1];
int cost[MAX + 1];
vector<vector<int>> graph;
stack<int>st;
int n, m, cnt, sn, s, t;

void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	st.push(x);
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (num[y] == 0) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (check[y]) low[x] = min(low[x], num[y]);
	}
	if (num[x] == low[x]) {
		while (!st.empty()) {
			int y = st.top();
			st.pop();
			com[y] = sn;
			check[y] = false;
			if (x == y)break;
		}
		sn++;
	}
}
int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);
	graph.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		graph[a].push_back(b);
	}
	for (int i = 0; i < n; i++)
		if (num[i] == 0) dfs(i);

	vector<vector<int>> scc(sn);

	memset(check, 0, sizeof(check));
	s--; t--;
	check[com[s]] = true;
	for (int i = 0; i < n; i++) {
		cost[com[i]]++;
		for (int j = 0; j < graph[i].size(); j++) {
			int y = graph[i][j];
			if (com[i] == com[y]) continue;
			scc[com[i]].push_back(com[y]);
			ind[com[y]]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < sn; i++) {
		dist[i] = cost[i];
		if (ind[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < scc[x].size(); i++) {
			int y = scc[x][i];
			
			ind[y]--;
			if (ind[y] == 0) q.push(y);
			
			if (check[x]) {
				check[y] = true;
				dist[y] = max(dist[y], dist[x] + cost[y]);
			}
		}
	}
	if (check[com[t]]) printf("%d\n", dist[com[t]]);
	else puts("0");
	return 0;
}