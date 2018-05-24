#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int tcase, n, m;

void max_init(vector<long long>& tree, vector<long long>& a, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		max_init(tree, a, node * 2, start, (start + end) / 2);
		max_init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

void min_init(vector<long long>&tree, vector<long long>&a, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		min_init(tree, a, node * 2, start, (start + end) / 2);
		min_init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

void max_update(vector<long long>&tree, vector<long long>&a, int node, int start, int end, int index, long long value) {
	if (index <start || index > end) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	max_update(tree, a, node * 2, start, (start + end) / 2, index, value);
	max_update(tree, a, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void min_update(vector<long long>& tree, vector<long long> &a, int node, int start, int end, int index, long long value) {
	if (index <start || index > end)return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	min_update(tree, a, node * 2, start, (start + end) / 2, index, value);
	min_update(tree, a, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

long long max_query(vector<long long>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];
	long long m1 = max_query(tree, node * 2, start, (start + end) / 2, i, j);
	long long m2 = max_query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return max(m1, m2);
}

long long min_query(vector<long long>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];
	long long m1 = min_query(tree, node * 2, start, (start + end) / 2, i, j);
	long long m2 = min_query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1)return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}
int main() {
	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d %d", &n, &m);
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}

		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		vector<long long> max_tree(tree_size);
		vector<long long> min_tree(tree_size);
		max_init(max_tree, a, 1, 0, n - 1);
		min_init(min_tree, a, 1, 0, n - 1);

		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			if (x == 1) {
				if (min_query(min_tree, 1, 0, n - 1, y, z) == y && max_query(max_tree, 1, 0, n - 1, y, z) == z) {
					puts("YES");
				}
				else
					puts("NO");
			}
			else {
				swap(a[y], a[z]);
				max_update(max_tree, a, 1, 0, n - 1, y, a[y]);
				max_update(max_tree, a, 1, 0, n - 1, z, a[z]);
				min_update(min_tree, a, 1, 0, n - 1, y, a[y]);
				min_update(min_tree, a, 1, 0, n - 1, z, a[z]);
			}
		}
	}
	return 0;
}