#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long

void init(vector<ll>&tree, vector<ll>&a, ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = a[start];
		return;
	}
	init(tree, a, node * 2, start, (start + end) / 2);
	init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(vector<ll>&tree, ll node, ll start, ll end, ll index, ll val) {
	if (index <start || index > end) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, val);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(vector<ll>&tree, ll node, ll start, ll end, ll i, ll j) {
	if (i > end || j < start)	 return -1;
	if (i <= start && end <= j) return tree[node];
	ll m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	ll m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return m1 + m2;
}
int main() {
	ll n, m; scanf(" %lld %lld", &n, &m);
	ll h = (ll)ceil(log2(n));
	ll tree_size = (1 << (h + 1));
	vector<ll> a(n);
	vector<ll> tree(tree_size);
	for (ll i = 0; i < n; i++) scanf(" %lld", &a[i]);
	init(tree, a, 1, 0, n - 1);
	for (ll i = 0; i < m; i++) {
		ll x, y, a, b; scanf(" %lld %lld %lld %lld", &x, &y, &a, &b);
		x--; y--; a--;
		printf("%lld\n", query(tree, 1, 0, n - 1, min(x, y), max(x, y)));
		update(tree, 1, 0, n - 1, a, b);
	}
}