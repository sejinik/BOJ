#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1000000
#define INF 1e+9
vector<int> graph[MAX];
vector<int> child[MAX];
vector<bool> check(MAX);
int n,d[MAX][2];

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];
		if (!check[next]) {
			child[x].push_back(next);
			dfs(next);
		}
	}
}

int go(int pos, bool par) {
	int&ret = d[pos][par];
	if (ret != -1)return ret;

	int notpick = INF, pick = 1;
	for (int i = 0; i < child[pos].size(); i++) {
		int next = child[pos][i];
		pick += go(next, true);
	}
	if (par) {
		notpick = 0;
		for (int i = 0; i < child[pos].size(); i++) {
			int next = child[pos][i];
			notpick += go(next, false);
		}
	}
	return ret = min(pick, notpick);
}

int main() {
	memset(d, -1, sizeof(d));
	scanf(" %d", &n);
	for (int i = 0; i < n-1; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		a -= 1;
		b -= 1;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(0);
	printf("%d\n", go(0, true));
	return 0;
}