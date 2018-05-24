#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

void init(vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = 1;
	}
	else {
		init(tree, node * 2, start, (start + end) / 2);
		init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(vector<int>&tree, int node, int start, int end, int index) {
	if (index <start || index >end) return;
	if (start == end) {
		tree[node] = 0;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, int node, int start, int end, int value) {
	if (start == end) {
		return start;
	}
	if (value <= tree[node * 2]) {
		return query(tree, node * 2, start, (start + end) / 2, value);
	}
	else {
		value -= tree[node * 2];
		return query(tree, node * 2 + 1, (start + end) / 2 + 1, end, value);
	}
}
int main() {
	scanf("%d", &n);
	vector<int> a(n + 1);
	vector<int> vt(n + 1);
	vector<int> ret(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	init(tree, 1, 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &vt[i]);
	}

	for (int i = n; i >= 1; i--) {
		int ans = query(tree, 1, 1, n, vt[i] + 1);
		ret[i] = a[ans];
		update(tree, 1, 1, n, ans);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", ret[i]);
	}
	return 0;
}