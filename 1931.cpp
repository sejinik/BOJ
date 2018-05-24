#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> vt;

int main() {
	int n; scanf("%d", &n);
	vt.resize(n);
	for (int i = 0; i < n; i++) {
		int start, end; scanf("%d %d", &start, &end);
		vt[i].first = end, vt[i].second = start;
	}

	sort(vt.begin(), vt.end());
	int ans = 1;
	int end_time = vt[0].first;
	for (int i = 1; i < n; i++) {
		if (vt[i].second >= end_time) {
			ans += 1; end_time = vt[i].first;
		}
	}
	printf("%d\n", ans);
	return 0;
}