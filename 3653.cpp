#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void update(vector<int>&tree, int node, int start, int end, int index, int val) {
	if (index<start || index > end) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, val);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];
	int m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	int m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return m1 + m2;
}

int main() {
	int t; scanf(" %d", &t);
	while (t--) {
		int n, m; scanf(" %d %d", &n, &m);
		int h = (int)ceil(log2(n+m));
		int tree_size = (1 << (h + 1));
		vector<int> a(n+1);
		vector<int> tree(tree_size+1,0);
		for (int i = 1; i <= n; i++) {
			a[i] = m + i;
			update(tree, 1, 1, n + m, m + i, 1);
		}
		for (int i = 0; i < m; i++) {
			int x; scanf(" %d", &x);
			update(tree, 1, 1, n + m, a[x], 0);
			printf("%d ", query(tree, 1, 0, n + m, 0, a[x] - 1));
			update(tree, 1, 1, n + m, m - i, 1);
			a[x] = m - i;
		}
		puts("");
	}
}