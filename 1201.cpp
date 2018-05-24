﻿#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m, k; scanf(" %d %d %d", &n, &m, &k);
	vector<int> a(n);
	if (m + k - 1 > n || n > m*k) {
		puts("-1"); return 0;
	}
	for (int i = 0; i < n; i++) a[i] = i + 1;
	vector<int> g;
	g.push_back(0);
	g.push_back(k);
	n -= k;
	m -= 1;
	int gs = m == 0 ? 1 : n / m;
	int r = m == 0 ? 0 : n%m;
	for (int i = 0; i < m; i++) {
		g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
		if (r > 0) r--;
	}
	for (int i = 0; i < g.size() - 1; i++) {
		reverse(a.begin() + g[i], a.begin() +g[i + 1]);
	}
	for (int i = 0; i < a.size(); i++) printf("%d ", a[i]);
}