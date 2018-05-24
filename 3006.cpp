#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int update(vector<int>&tree, int node, int start, int end, int index, int val) {
	if (index > end || index < start) return 0;
	if (start == end) return tree[node] = val;
	update(tree, node * 2, start, (start + end) / 2, index, val);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	return tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return 0;
	if (i <= start && end <= j)return tree[node];
	return query(tree, node * 2, start, (start + end) / 2, i, j) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	int n; scanf(" %d", &n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int>a(n);
	vector<int>tree(tree_size);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		a[--x] = i;
		update(tree,1, 0, n - 1, i, 1);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int s, e;
		if (i & 1) s = a[n - cnt], e = n-1;
		else s = a[cnt], e = 0;
		printf("%d\n", query(tree, 1, 0, n - 1, min(s,e), max(s,e)) - 1);
		update(tree, 1, 0, n - 1, s, 0);
		if (!(i & 1)) cnt += 1;
	}
}