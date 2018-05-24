#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int inf = 1000000000;
int n, m;
int d[1010];
int from[1010];
int ans[1010];
int cnt;
vector < vector<pair<int, int>>> vt;
void print(int st, int ed) {
	if (st != ed) {
		print(st, from[ed]);
	}
	ans[cnt++] = ed;
}
int main() {
	for (int i = 0; i <= 1005; i++) d[i] = inf;
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vt[x].push_back({ y,z });
	}
	int start, endd;
	scanf("%d %d", &start, &endd);
	priority_queue<int> pq;
	pq.push(start);
	d[start] = 0;
	while (!pq.empty()) {
		int here = pq.top();
		pq.pop();

		for (int i = 0; i < vt[here].size(); i++) {
			int next = vt[here][i].first;
			int ncost = vt[here][i].second;
			if (d[next] > d[here] + ncost) {
				d[next] = d[here] + ncost;
				from[next] = here;
				pq.push(next);
			}
		}
	}
	printf("%d\n", d[endd]);
	print(start, endd);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}