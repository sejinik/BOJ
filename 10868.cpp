#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;

void init(vector<int>& tree, vector<int>&a, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		init(tree, a, 2 * node, start, (start + end) / 2);
		init(tree, a, 2 * node + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(vector<int>& tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];

	int m1 = query(tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else	return min(m1, m2);
}
int main() {
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	init(tree, a, 1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", query(tree, 1, 0, n - 1, x - 1, y - 1));
	}
}