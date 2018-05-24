#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;

void min_init(vector<int>& min_tree, vector<int>&a, int node, int start, int end) {
	if (start == end) {
		min_tree[node] = a[start];
	}
	else {
		min_init(min_tree, a, 2 * node, start, (start + end) / 2);
		min_init(min_tree, a, 2 * node + 1, (start + end) / 2 + 1, end);
		min_tree[node] = min(min_tree[2 * node], min_tree[2 * node + 1]);
	}
}

void max_init(vector<int>& max_tree, vector<int>& a, int node, int start, int end) {
	if (start == end) {
		max_tree[node] = a[start];
	}
	else {
		max_init(max_tree, a, 2 * node, start, (start + end) / 2);
		max_init(max_tree, a, 2 * node + 1, (start + end) / 2 + 1, end);
		max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
	}
}

int min_query(vector<int>& min_tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return min_tree[node];
	int m1 = min_query(min_tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = min_query(min_tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}

int max_query(vector<int>& max_tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return max_tree[node];
	int m1 = max_query(max_tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = max_query(max_tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return max(m1, m2);
}
int main() {
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> max_tree(tree_size);
	vector<int> min_tree(tree_size);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	min_init(min_tree, a, 1, 0, n - 1);
	max_init(max_tree, a, 1, 0, n - 1);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d %d\n", min_query(min_tree, 1, 0, n - 1, x - 1, y - 1), max_query(max_tree, 1, 0, n - 1, x - 1, y - 1));
	}
	return 0;
}