#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 500050
bool check[MAX + 1];
int num[MAX + 1];
int low[MAX + 1];
int com[MAX + 1];

int ind[MAX + 1];
int d[MAX + 1];
int cost[MAX + 1];
bool rest[MAX + 1];
bool go[MAX + 1];
int n, m, s, p, cnt, sn;
vector<int> graph[MAX + 1];
vector<vector<int>> ans;
stack<int> st;

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
		vector<int> scc;
		while (!st.empty()) {
			int y = st.top();
			st.pop();

			check[y] = false;
			scc.push_back(y);
			com[y] = sn;
			if (x == y) break;
		}
		ans.push_back(scc);
		sn++;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		graph[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		if (num[i] == 0) dfs(i);
	}
	for (int i = 0; i < n; i++) {
		int price; scanf("%d", &price);
		cost[com[i]] += price;
	}
	scanf("%d %d", &s, &p);
	for (int i = 0; i < p; i++) {
		int pos; scanf("%d", &pos);
		rest[com[pos - 1]] = true;
	}
	vector<int> vt[MAX + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (com[i] != com[next]) {
				ind[com[next]]++;
				vt[com[i]].push_back(com[next]);
			}
		}
	}
	queue<int> q;
	for (int i = 0; i < sn; i++) {
		d[i] = cost[i];
		if (i == com[s - 1]) {
			go[i] = true;
		}
		if (ind[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < vt[here].size(); i++) {
			int next = vt[here][i];
			ind[next]--;
			if (ind[next] == 0) q.push(next);
			if (go[here]) {
				go[next] = true;
				d[next] = max(d[next], d[here] + cost[next]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < sn; i++) {
		if (go[i] == true && rest[i] == true) ans = max(ans, d[i]);
	}
	printf("%d\n", ans);
	return 0;
}