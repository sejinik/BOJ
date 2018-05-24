#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long
int n;
ll ans;

void init(vector<ll>&tree, vector<ll>&a, ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = start;
	}
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		if (a[tree[node * 2]] <= a[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

ll query(vector<ll>& tree, vector < ll> &a , ll node, ll start, ll end, ll i, ll j) {
	if (j<start || i > end) return -1;
	if (i <= start && end <= j) return tree[node];
	ll m1 = query(tree, a,node * 2, start, (start + end) / 2, i, j);
	ll m2 = query(tree, a,node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else {
		if (a[m1] <= a[m2]) return m1;
		else return m2;
	}
}

void go(vector<ll> &tree, vector<ll> &a, ll node, ll start, ll end, ll i, ll j) {
	if (i > end || j < start) return;
	if (i > j) return;
	ll index = query(tree, a, node, start, end, i, j);
	ans = max(ans, (j-i+1)*a[index]);
	go(tree, a, node, start, end, i, index-1);
	go(tree, a, node, start, end, index + 1, j);
}

int main() {
	while (scanf("%d", &n)) {
		if (n == 0) return 0;
		ans = 0;
		vector<ll> a(n + 1);
		ll h = (int)ceil(log2(n));
		ll tree_size = (1 << (h + 1));
		vector<ll> tree(tree_size + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}

		init(tree, a, 1, 1, n);
		go(tree, a, 1, 1, n, 1, n);
		printf("%lld\n", ans);
	}
	return 0;
}