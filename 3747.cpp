#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int num[2002];
int low[2002];
bool check[2002];
int com[2002];
int cnt, sn, n, m;
vector<vector<int>> graph;
stack<int> st;

int op(int x) {
	if (x <= n) return x + n;
	return x - n;
}

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
	if (low[x] == num[x]) {
		while (!st.empty()) {
			int y = st.top();
			st.pop();
			com[y] = sn;
			check[y] = false;
			if (x == y) break;
		}
		sn++;
	}
}
int main() {
	while (scanf("%d %d", &n, &m) != -1) {
		while (!st.empty()) st.pop();
		memset(num, 0, sizeof(num));
		memset(low, 0, sizeof(low));
		memset(check, 0, sizeof(check));
		memset(com, 0, sizeof(com));
		cnt = sn = 0;
		graph.clear();
		graph.resize(n * 2 + 3);
		for (int i = 0; i < m; i++) {
			int c=0, d=0;
			string a, b; cin >> a >> b;
			for (int j = 1; j < a.size(); j++) {
				c *= 10;
				c += a[j] - '0';
			}
			for (int j = 1; j < b.size(); j++) {
				d *= 10;
				d += b[j] - '0';
			}
			if (a[0] == '-') c = c + n;
			if (b[0] == '-') d = d + n;
			graph[op(c)].push_back(d);
			graph[op(d)].push_back(c);
		}

		for (int i = 1; i <= n * 2; i++)
			if (num[i] == 0) dfs(i);

		bool go = true;
		for (int i = 1; i <= n; i++)
			if (com[i] == com[i + n]) go = false;
		if (go)puts("1");
		else puts("0");
	}
}