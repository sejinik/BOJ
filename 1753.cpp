#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int v, e, k;
int arr[20002];

vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

int main() {
	scanf("%d %d %d", &v, &e, &k);
	vt.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v,w });
	}

	memset(arr, -1, sizeof(arr));
	pq.push({ 0,k });
	
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (arr[here] != -1)
			continue;

		arr[here] = cost;
		
		for (int i = 0; i < vt[here].size(); i ++ ) {
			int there = vt[here][i].first;
			int acost = -vt[here][i].second - cost;

			if (arr[there] != -1)
				continue;
			pq.push({ acost,there });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (arr[i] == -1)
			puts("INF");
		else
			printf("%d\n", arr[i]);
	}
	return 0;
	
}