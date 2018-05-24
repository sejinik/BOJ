#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
struct Biprate {
	int n;
	vector<vector<int>> Graph;
	vector<bool> check;
	vector<int> pred;
	Biprate(int n) :n(n) {
		Graph.resize(n);
		check.resize(n);
		pred.resize(n, -1);
	}
	void add_edge(int u, int v) {
		Graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int i = 0; i < Graph[x].size(); i++) {
			int y = Graph[x][i];
			if (check[y]) continue;
			check[y] = true;
			if (dfs(pred[y])) {
				pred[y] = x;
				return true;
			}
		}
		return false;
	}
	int flow() {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i)) ans += 1;
		}
		return ans;
	}
};

struct node {
	int h, m, a, b, c, d;
};

int DIST(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

bool go(int a, int b, int c, int d, int use,int dist) {
	b += use;
	while (b >= 60) {
		b -= 60; a += 1;
	}
	if (a > c || (a==c && b>d)) return false;
	int fir = a * 60 + b;
	int sec = c * 60 + d;

	if (fir + dist + 1 <= sec) return true;
	else return false;
}

int used[505];
int main() {
	int t; scanf(" %d", &t);
	while (t--) {
		memset(used, 0, sizeof(used));
		int n; scanf(" %d", &n);
		Biprate mf(n * 2);
		vector<node> vt(n);
		for (int i = 0; i < n; i++) {
			scanf(" %2d:%2d %d %d %d %d", &vt[i].h, &vt[i].m, &vt[i].a, &vt[i].b, &vt[i].c, &vt[i].d);
			used[i] = DIST(vt[i].a, vt[i].b, vt[i].c, vt[i].d);
		}
		
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				int dist = DIST(vt[i].c, vt[i].d, vt[j].a, vt[j].b);
				if (go(vt[i].h, vt[i].m, vt[j].h, vt[j].m, used[i], dist)) mf.add_edge(i, j + n);
			}
		}
		printf("%d\n", n - mf.flow());
	}
}