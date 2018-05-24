#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;

void init(vector<int>& tree, vector<int>& a, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(vector<int>& tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];
	int m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	int m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}

void update(vector<int>& tree, int node, int start, int end, int index, int value) {
	if (index < start || index > end) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	scanf("%d", &n);
	vector<int> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	init(tree, a, 1, 0, n - 1);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			update(tree,1, 0, n - 1, y - 1, z);
		}
		else {
			printf("%d\n", query(tree, 1, 0, n - 1, y - 1, z - 1));
		}
	}
	return 0;
}