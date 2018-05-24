#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n, m;

int init(vector<int>& tree, vector<int>&a, int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	return tree[node] = init(tree, a, node * 2, start, (start + end) / 2) ^ init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(vector<int>&tree, vector<int>& lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		int c = end - start + 1;
		if(c&1) tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<int>&tree, vector<int>& lazy, int node, int start, int end, int i, int j, int val) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return;
	if (i <= start && end <= j) {
		int c = end - start + 1;
		if (c & 1) tree[node] ^= val;
			if (start != end) {
				lazy[node * 2] ^= val;
				lazy[node * 2 + 1] ^= val;
			}		
		return;
	}
	update_range(tree, lazy, node * 2, start, (start + end) / 2, i, j, val);
	update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j, val);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(vector<int>&tree, vector<int>&lazy, int node, int start, int end, int i, int j) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return query(tree, lazy, node * 2, start, (start + end) / 2, i, j) ^ query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	scanf("%d", &n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> a(n);
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);
	for (int i = 0; i < n; i++) scanf(" %d", &a[i]);
	init(tree, a, 1, 0, n-1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int ch; scanf("%d", &ch);
		if (ch == 1) {
			int x, y, z; scanf("%d %d %d", &x, &y, &z);
			if (x > y) swap(x, y);
			update_range(tree, lazy, 1, 0, n-1, x, y, z);
		}
		else {
			int x, y; scanf("%d %d", &x, &y);
			if (x > y) swap(x, y);
			printf("%d\n", query(tree, lazy, 1, 0, n-1, x, y));
		}
	}
	return 0;
}