#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int t, n,m;
int a, b, c, d;

bool go(int x, int y, int r) {
	int q1 = (x - a)*(x - a) + (y - b)*(y - b);
	int q2 = (x - c)*(x - c) + (y - d)*(y - d);
	return ((q1 > r*r && q2 < r*r) || (q1 <r*r && q2 > r*r));
}
int main() {
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int x, y, r; scanf("%d %d %d", &x, &y, &r);
			if (go(x, y, r)) ans += 1;
		}
		printf("%d\n", ans);
	}
}