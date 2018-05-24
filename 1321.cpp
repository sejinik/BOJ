#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;

void init(vector<int>&tree, vector<int>&a, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(vector<int>&tree, int node, int start, int end, int index, int value) {
	if (index > end || index < start) return;
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
	if (tree[node*2] >= index) {
		return query(tree, node * 2, start, (start+end)/2, index);
	}
	else if (tree[node*2] < index) {
		index -= tree[node*2];
		return query(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}
int main() {
	scanf("%d", &n);
	vector<int > a(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int>tree(tree_size+1);
	init(tree, a, 1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y, z;
			scanf("%d %d", &y, &z);
			update(tree, 1, 1, n, y, z);
		}
		else {
			int y;
			scanf("%d", &y);
			printf("%d\n", query(tree, 1, 1, n, y));
		}
	}
	return 0;
}