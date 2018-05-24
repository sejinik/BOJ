#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t, n, m, cnt;
int inf = 1000000000;
bool prime[10010];
int arr[10010];
int d[10010];
bool go(int x, int y) {
	int ret = 0;
	while (x != 0) {
		if (x % 10 != y % 10) ret += 1;
		x /= 10; y /= 10;
	}
	if (ret <= 1) return true;
	else return false;
}
int main() {
	for (int i = 2; i <= 10000; i++) {
		if (!prime[i]) {
			if (i > 1000) {
				arr[cnt++] = i;
			}			
			for (int j = i * 2; j<= 10000; j += i)
				prime[j] = true;
		}
	}
	vector<vector<pair<int, int>>> vt(cnt);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (go(arr[i], arr[j])) {
				vt[i].push_back({ j,1 });
			}
		}
	}

	scanf("%d", &t);
	while (t--) {
		memset(d, -1, sizeof(d));
		scanf("%d %d", &n, &m);
		int x = lower_bound(arr, arr + cnt, n) - arr;
		int y = lower_bound(arr, arr + cnt, m) - arr;
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,x });
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			if (d[here] != -1) continue;
			d[here] = cost;
			for (int i = 0; i < vt[here].size(); i++) {
				int next = vt[here][i].first;
				int ncost = -cost - vt[here][i].second;
				if (d[next] != -1) continue;
				pq.push({ ncost,next });
			}
		}
		if (d[y] == -1) puts("Impossible");
		else printf("%d\n", d[y]);
	}
	return 0;
}