#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t, a, b, c;
int dist[10010];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &c);
		vector<vector<pair<int,int>>> vt(a + 1);
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < b; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vt[y].push_back({ x,z });
		}
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,c });
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			if (dist[here] != -1) continue;
			dist[here] = cost;
			for (int i = 0; i < vt[here].size(); i++) {
				int next = vt[here][i].first;
				int ncost = -cost - vt[here][i].second;
				if (dist[next] != -1) continue;
				pq.push({ ncost,next });
			}
		}
		int ans = 0, cnt = 0;
		for (int i = 1; i <= a; i++) {
			if (dist[i] != -1) cnt += 1;
			ans = max(ans, dist[i]);
		}
		printf("%d %d\n", cnt, ans);
	}
	return 0;
}