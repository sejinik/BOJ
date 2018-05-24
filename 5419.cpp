#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define ll long long
struct Node {
	int x, y;
	bool operator < (const Node& other) const {
		return y < other.y;
	}
};

int update(vector<int>&tree, int node, int start, int end, int index) {
	if (index <start || index >end) return 0;
	if (start == end) return tree[node] += 1;
	update(tree, node * 2, start, (start + end) / 2, index);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, int node, int start, int end, int i, int j) {
	if (j<start || i > end) return 0;
	if (i <= start && end <= j) return tree[node];
	return query(tree, node * 2, start, (start + end) / 2, i, j) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

bool cmp(const Node&a, const Node&b) {
	if (a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}

int main() {
	int t; scanf(" %d", &t);
	while (t--) {
		int n; scanf(" %d", &n);
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		vector<Node> a(n);
		vector<Node> b(n);
		vector<int>tree(tree_size);
		for (int i = 0; i < n; i++) scanf(" %d %d", &a[i].x, &a[i].y);
		sort(a.begin(), a.end());
		b = a;
		map<int, int> mp;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mp.count(a[i].y)) continue;
			mp[a[i].y] = cnt++;
		}
		for (int i = 0; i < n; i++) b[i].y = mp[b[i].y];
		sort(b.begin(), b.end(), cmp);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (ll)query(tree, 1, 0, n - 1, b[i].y, n - 1);
			update(tree, 1, 0, n - 1, b[i].y);
		}
		printf("%lld\n", ans);
	}
}