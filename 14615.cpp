#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m,tcase;
bool visited1[100010];
bool visited2[100010];

vector<int> vt1[100010];
vector<int> vt2[100010];

void dfs1(int here) {
	visited1[here] = true;

	for (int i = 0; i < vt1[here].size(); i++) {
		int there = vt1[here][i];
		
		if (!visited1[there])
			dfs1(there);
	}
}

void dfs2(int here) {
	visited2[here] = true;

	for (int i = 0; i < vt2[here].size(); i++) {
		int there = vt2[here][i];

		if (!visited2[there])
			dfs2(there);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt1[u].push_back(v);
		vt2[v].push_back(u);
	}

	scanf("%d", &tcase);
	
	dfs1(1);
	dfs2(n);

	while (tcase--) {
		int num;
		scanf("%d", &num);

		if (visited1[num] && visited2[num])
			printf("Defend the CTP\n");
		else
			printf("Destroyed the CTP\n");
	}
	return 0;
}