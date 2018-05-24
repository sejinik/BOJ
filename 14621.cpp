#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge {
	int start, end, cost;
	bool operator < (const Edge& other)	const {
		return cost < other.cost;
	}
};
int p[1010];
bool gen[1010];
int n, m;

int find(int x) {
	if (x == p[x]) return x;
	else return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(p[x]);
	y = find(p[y]);
	if (x == y) return;
	p[y] = x;
}

int main() {
	scanf("%d %d", &n, &m);
	vector<Edge> vt(m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < n; i++) {
		char a; scanf(" %c", &a);
		if (a == 'M') gen[i+1] = true;
	}
	for (int i = 0; i < m; i++) scanf("%d %d %d", &vt[i].start, &vt[i].end, &vt[i].cost);
	sort(vt.begin(), vt.end());
	int ans = 0;
	for (int i = 0; i < m; i++) {
		Edge s = vt[i];
		if (gen[s.start] == gen[s.end]) continue;
		if (find(s.start) == find(s.end)) continue;
		merge(s.start, s.end);
		ans += s.cost;
	}
	for (int i = 1; i <= n; i++) {
		if (find(1) != find(i)) {
			puts("-1"); return 0;
		}
	}
	printf("%d\n", ans);
}