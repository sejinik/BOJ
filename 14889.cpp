#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int arr[22][22], n;

int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}

	int ans = 1e9;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		vector<int> a, b;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) a.push_back(j);
			else b.push_back(j);
		}
		if (a.size() == b.size()) {
			int t = 0, f = 0, as = a.size(), bs = b.size();
			for (int i = 0; i < as; i++) {
				for (int j = 0; j < as; j++) {
					if (i == j) continue;
					t += arr[a[i]][a[j]];
					f += arr[b[i]][b[j]];
				}
			}
			ans = min(ans, abs(t - f));
		}
	}
	printf("%d\n", ans);
}