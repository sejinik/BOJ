#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace  std;

int main() {
	queue<pair<int, int>> q;
	int n, m, k; scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d %d", &a, &b); q.push({ a,b });
	}
	int to_x, to_y; scanf("%d %d", &to_x, &to_y);
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (to_x == 1) {
			if (x == 1) ans += abs(to_y - y);
			else if (x == 2) ans += min(to_y + y, abs(m * 2 - (to_y + y))) + n;
			else if (x == 3) ans += (y + to_y);
			else ans += (m - to_y) + y;
		}
		else if (to_x == 2) {
			if (x == 2) ans += abs(to_y - y);
			else if (x == 1) ans += min(to_y + y, abs(m * 2 - (to_y + y))) + n;
			else if (x == 3) ans += (to_y + (n - y));
			else ans += (m - to_y) + (n - y);
		}
		else if (to_x == 3) {
			if (x == 3) ans += abs(to_y - y);
			else if (x == 4) ans += min(to_y + y, abs(n * 2 - (to_y + y))) + m;
			else if (x == 1) ans += (y + to_y);
			else ans += (n - to_y) + y;
		}
		else {
			if (x == 4) ans += abs(to_y - y);
			else if (x == 3) ans += min(to_y + y, abs(n * 2 - (to_y + y))) + m;
			else if (x == 1) ans += ((m - y) + to_y);
			else ans += (n - to_y) + (m - y);
		}
	}
	printf("%d\n", ans);
	return 0;
}
