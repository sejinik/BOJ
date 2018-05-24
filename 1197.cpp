#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int start, end, cost;
	bool operator < (const Edge& other) const {
		return cost < other.cost;
	}
};
int p[10001];

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	p[y] = x;
}

int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		p[i] = i;
	}

	vector<Edge> vt(e);
	for (int i = 0; i < e; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		vt[i].start = x;
		vt[i].end = y;
		vt[i].cost = z;
	}

	sort(vt.begin(), vt.end());
	int ans = 0;
	for (int i = 0; i < e; i++) {
		Edge e = vt[i];
		int x = find(vt[i].start);
		int y = find(vt[i].end);
		if (x != y) {
			merge(vt[i].start, vt[i].end);
			ans += vt[i].cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}