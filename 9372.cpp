#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int start, end, cost;
	bool operator < (const Edge& other) const {
		return cost < other.cost;
	}
};

int n, m;
int p[1001];

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[x] = y;
}

int main() {
	int tcase;
	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}

		vector<Edge> vt(m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &vt[i].start, &vt[i].end);
		}

		sort(vt.begin(), vt.end());

		int cnt = 0;
		for (int i = 0; i < m; i++) {
			Edge e = vt[i];
			int x = find(e.start);
			int y = find(e.end);

			if (x != y) {
				merge(x, y);
				cnt += 1;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}