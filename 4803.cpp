#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> Graph;
vector<int> vt;
int deg[505];
bool check[505];
int n, m, v, e;

void dfs(int x) {
	v += 1;
	check[x] = true;
	vt.push_back(x);
	for (int i = 0; i < Graph[x].size(); i++) {
		int next = Graph[x][i];
		if (!check[next])	 dfs(next);
	}
}
int main() {
	int c = 1;
	while (scanf(" %d %d", &n, &m) != -1) {
		if (n == 0 && m == 0) return 0;
		memset(check, 0, sizeof(check));
		memset(deg, 0, sizeof(deg));
		Graph.resize(n);
		for (int i = 0; i < m; i++) {
			int a, b; scanf(" %d %d", &a, &b);
			a--; b--;
			Graph[a].push_back(b);
			Graph[b].push_back(a);
			deg[a]++; deg[b]++;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (check[i]) continue;
			v = 0, e = 0;
			vt.clear();
			dfs(i);
			for (int i = 0; i < vt.size(); i++) e += deg[vt[i]];
			e /= 2;
			if (v == (e + 1)) ans += 1;
		}
		
		printf("Case %d: ", c++);
		if (ans == 0) puts("No trees.");
		else if (ans == 1) puts("There is one tree.");
		else printf("A forest of %d trees.\n",ans);
		Graph.clear();
	}
}