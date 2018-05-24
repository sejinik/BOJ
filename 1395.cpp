#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n, m;

void update_lazy(vector<int>& tree, vector<int>& lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		if (lazy[node] & 1) tree[node] = (end - start + 1)-tree[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<int>&tree, vector<int>&lazy, int node, int start, int end, int i, int j) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return;
	if (i <= start && end <= j) {
		tree[node] = (end-start+1)-tree[node];
		if (start != end) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return;
	}
	update_range(tree, lazy, node * 2, start, (start + end) / 2, i, j);
	update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, vector<int>& lazy, int node, int start, int end, int i, int j) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return query(tree, lazy, node * 2, start, (start + end) / 2, i, j) + query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	scanf("%d %d", &n, &m);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> a(n + 1);
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);
	
	for (int i = 0; i < m; i++) {
		int x, y, z; scanf(" %d %d %d", &x, &y, &z);
		if (x == 0) {
			update_range(tree, lazy, 1, 1, n, y, z);
		}
		else {
			printf("%d\n", query(tree, lazy, 1, 1, n, y, z));
		}
	}
	return 0;
}