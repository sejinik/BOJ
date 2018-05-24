#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int update(vector<int>&tree, int node, int start, int end, int index, int val) {
	if (index > end || index < start) return 0;
	if (start == end) return tree[node] = val;
	update(tree, node * 2, start, (start + end) / 2, index, val);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	return tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(vector<int>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return max(query(tree, node * 2, start, (start + end) / 2, i, j), query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}

int main() {
	int n, m; scanf(" %d %d", &n, &m); m--;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> a(n);
	vector<int> tree(tree_size);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &a[i]);
		update(tree, 1, 0, n - 1, i, a[i]);
	}
	for (int i = m; i < n - m; i++) {
		printf("%d ", query(tree, 1, 0, n - 1, i - m, i + m));
	}
	puts("");
}