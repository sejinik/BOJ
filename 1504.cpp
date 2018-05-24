#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, E;
int a, b;

int abn;
int ban;

int dist[805];

vector<vector<pair<int,int>>> vt;

void dij(vector<vector<pair<int, int>>> &a, int here) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,here });

	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[x] != -1)
			continue;

		dist[x] = cost;

		for (int i = 0; i < a[x].size(); i++) {
			int nx = a[x][i].first;
			int ncost = -a[x][i].second - cost;

			if (dist[nx] != -1)
				continue;

			pq.push({ ncost,nx });
		}
	}
	
}
int main() {
	scanf("%d%d", &N, &E);
	vt.resize(N + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vt[u].push_back({ v,w });
		vt[v].push_back({ u,w });
	}

	scanf("%d%d", &a, &b);

	bool checka = true, checkb = true;
	memset(dist, -1, sizeof(dist));
	dij(vt,1);
	abn += dist[a];
	ban += dist[b];
	if (dist[a] == -1)
		checka = false;
	if (dist[b] == -1)
		checkb = false;

	memset(dist, -1, sizeof(dist));
	dij(vt,a);
	abn += dist[b];
	ban += dist[b];
	
	if (dist[b] == -1)
		checka = checkb = false;

	memset(dist, -1, sizeof(dist));
	dij(vt,N);
	abn += dist[b];
	ban += dist[a];
	if (dist[b] == -1)
		checka = false;
	if (dist[b] == -1)
		checkb = false;

	if (checka && checkb)
		printf("%d\n", min(abn, ban));
	else if (checka && !checkb)
		printf("%d\n", abn);
	else if (checkb && !checka)
		printf("%d\n", ban);
	else
		puts("-1");

	return 0;
}