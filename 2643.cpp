#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> vt;
int n;
int d[111][111];
int main() {
	scanf("%d", &n);
	vt.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		vt[i].first = max(a, b);
		vt[i].second = min(a, b);
	}
	sort(vt.begin(), vt.end());
	reverse(vt.begin(), vt.end());

	for (int i = 0; i < n; i++) {
		d[i][i] = 1;
		for (int j = i + 1; j < n; j++) {
			for (int k = i; k < j; k++) {
				if (vt[k].second >= vt[j].second) d[i][j] = max(d[i][j], d[i][k] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, d[i][j]);
		}
	}
	printf("%d\n", ans);
}