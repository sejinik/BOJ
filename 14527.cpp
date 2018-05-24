#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	vector<pair<int, int>> vt(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vt[i].first = y;
		vt[i].second = x;
	}

	sort(vt.begin(), vt.end());
	int ans = 0;
	int left = 0;
	int right = n - 1;

	while (1) {
		if (left > right) break;
		ans = max(ans, vt[left].first + vt[right].first);
		if (vt[left].second == vt[right].second) {
			left += 1;
			right -= 1;
		}
		else if (vt[left].second > vt[right].second) {
			vt[left].second -= vt[right].second;
			right -= 1;
		}
		else {
			vt[right].second -= vt[left].second;
			left += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}