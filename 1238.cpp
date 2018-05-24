#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, x;

int temp[1010];
int dist1[1010];
int dist2[1010];

vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

int main() {
	memset(dist1, -1, sizeof(dist1));
	memset(dist2, -1, sizeof(dist2));

	scanf("%d%d%d", &n, &m, &x);
	vt.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vt[u].push_back({ v,w });
	}

	//x에서 최단거리부터 구하기
	pq.push({ 0,x });
	
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist2[here] != -1)
			continue;

		dist2[here] = cost;

		for (int i = 0; i < vt[here].size(); i++) {
			int next = vt[here][i].first;
			int ncost = -vt[here][i].second - cost;

			if (dist2[next] != -1)
				continue;
			pq.push({ ncost,next });
		}
	}
	
	//x까지 최단거리 구하기
	for (int i = 1; i <= n; i++) {
		memset(temp, -1, sizeof(temp));
		priority_queue<pair<int, int>> pq2;

		pq2.push({ 0, i });
		while (!pq2.empty()) {
			int here = pq2.top().second;
			int cost = -pq2.top().first;
			pq2.pop();

			if (temp[here] != -1)
				continue;
			temp[here] = cost;
			
			if (here == x) {
				dist1[i] = cost;
			}

			for (int i = 0; i < vt[here].size(); i++) {
				int next = vt[here][i].first;
				int ncost = -vt[here][i].second - cost;

				if (temp[next] != -1)
					continue;

				pq2.push({ ncost,next });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist1[i] + dist2[i]);
	}
	printf("%d\n", ans);
	return 0;
}