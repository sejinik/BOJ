#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int vt[100010];
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

int query(vector<int>& tree, int node, int start, int end, int index) {
	if (start == end) {
		return start;
	}
	if (index <= tree[node * 2]) {
		return query(tree, node * 2, start, (start + end) / 2, index);
	}
	else {
		index -= tree[node * 2];
		return query(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}

void update(vector<int>&tree, int node, int start, int end, int index) {
	if (index <start || index > end) return;
	if (start == end) {
		tree[node] = 0;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	scanf("%d", &n);
	vector<int> a(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(tree, 1, 1, n);

	for (int i = 1; i <= n; i++) {
		int ans = query(tree, 1, 1, n, a[i] + 1);
		vt[ans] = i;
		update(tree, 1, 1, n, ans);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", vt[i]);
	}
	return 0;
}