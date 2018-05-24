#include <iostream>
#include <algorithm>
using namespace std;
int n, m, par[200020], p[200020], q1[200020*2], q2[200020*2],cnt;
bool ans[200020*2];
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
	scanf(" %d %d", &n, &m);
	par[1] = 1;
	for (int i = 2; i <= n; i++) {
		int x; scanf(" %d", &x);
		p[i] = i;
		par[i] = x;
	}
	for (int i = 1; i <= n + m - 1; i++) {
		int x; scanf(" %d", &x);
		if (x == 0) scanf(" %d", &q1[i]);
		else scanf(" %d %d", &q1[i], &q2[i]);
	}

	for (int i = n + m - 1; i > 0; i--) {
		if (q2[i]) {
			if (find(q1[i]) == find(q2[i])) ans[cnt++] = 1;
			else ans[cnt++] = 0;
		}
		else merge(par[q1[i]], q1[i]);
	}
	for (int i = cnt - 1; i >= 0; i--) {
		if (ans[i])	puts("YES");
		else puts("NO");
	}
}