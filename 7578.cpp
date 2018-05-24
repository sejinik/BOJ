#include <iostream>
#include <algorithm>
#include <vector>
#include <map>	
#include <cmath>
using namespace std;
#define ll long long
void update(vector<int>&tree, int n, int s, int e, int i) {
	if (i<s || i>e) return;
	if (s == e) {
		tree[n] = 1; return;
	}
	update(tree, n * 2, s, (s + e) / 2, i);
	update(tree, n * 2 + 1, (s + e) / 2 + 1, e, i);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int query(vector<int>&tree, int n, int s, int e, int i, int j) {
	if (i > e || j < s) return 0;
	if (i <= s && e <= j) return tree[n];
	return query(tree, n * 2, s, (s + e) / 2, i, j) + query(tree, n * 2 + 1, (s + e) / 2 + 1, e, i, j);
}
int main() {
	int n; scanf(" %d", &n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) scanf(" %d", &a[i]);
	for (int i = 1; i <= n; i++) scanf(" %d", &b[i]);
	vector<int> tree(tree_size);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) mp[b[i]] = i;
	for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (ll)query(tree, 1, 1, n, a[i], n);
		update(tree, 1, 1, n, a[i]);
	}
	printf("%lld\n", ans);
}