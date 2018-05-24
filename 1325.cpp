#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> vt;

bool visited[10010];
int h_num[10010];
int pcnt;
int m_pcnt;

void dfs(int here) {
	visited[here] = true;
	pcnt++;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!visited[there]) {
			dfs(there);
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	
	vt.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		pcnt = 0;
		dfs(i);
		h_num[i] = pcnt;
		m_pcnt = max(pcnt, m_pcnt);
	}

	for (int i = 1; i <= n; i++) {
		if (m_pcnt == h_num[i])
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}