#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;

void update(vector<int> &tree, int node, int start, int end, int index, int value) {
	if (index < start || index > end) return;
	if (start == end) {
		tree[node] += value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, int node, int start, int end, int index) {
	if (start == end) {
		return start;
	}
	if (tree[node * 2] >= index) {
		return query(tree, node * 2, start, (start + end) / 2, index);
	}
	else if (tree[node * 2] < index) {
		index -= tree[node * 2];
		return query(tree, node * 2 + 1, (start + end) / 2+1, end, index);
	}
}

int main() {
	scanf("%d", &n);
	vector<int> a(1000001);
	int h = (int)ceil(log2(1000000));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size+1);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int b;
			scanf("%d", &b);
			int ans = query(tree, 1, 1, 1000001, b);
			printf("%d\n", ans);
			update(tree, 1, 1, 1000001, ans, -1);
		}
		else {
			int y, z;
			scanf("%d %d", &y, &z);
			update(tree, 1, 1, 1000001, y, z);
		}
	}
	return 0;
}