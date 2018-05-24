#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int d[100010];
bool check[100010];
vector<vector<pair<int,int>>> tree;
int n,f,s;

int dfs(int x) {
	check[x] = true;
	int ret = x;
	d[x] = 0;
	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i].first;
		int cost = tree[x][i].second;
		if (check[next]) continue;
		int ret_next = dfs(next);
		if (d[x] < d[next] + cost) {
			d[x] = d[next] + cost;
			ret = ret_next;
		}
	}
	return ret;
}

int main() {
	scanf(" %d", &n);
	tree.resize(n);

	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		int a, b;
		while (1) {
			scanf(" %d", &a);
			if (a == -1) break;
			scanf(" %d", &b);
			tree[x-1].push_back({ a - 1,b });
			tree[a - 1].push_back({ x - 1,b });
		} 
	}

	f = dfs(0);
	memset(d, 0, sizeof(d));
	memset(check, 0, sizeof(check));
	s = dfs(f);
	printf("%d\n", d[f]);
}