#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000007

int n, m, k;

void init(vector<long long>&tree, vector<int>& a, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		init(tree, a, 2 * node, start, (start + end) / 2);
		init(tree, a, 2 * node + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
		tree[node] %= MOD;
	}
}

long long query(vector<long long>& tree,int node, int start, int end ,int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];
	long long m1 = query(tree, 2 * node, start, (start + end) / 2, i, j);
	long long m2 = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else {
		long long ans = m1*m2;
		ans %= MOD;
		return ans;
	}
}

void update(vector<long long>& tree, int node, int start, int end ,int index, int value) {
	if (index < start || index > end) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(tree, 2 * node, start, (start + end) / 2, index, value);
	update(tree, 2 * node + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = tree[2 * node] * tree[2 * node + 1];
	tree[node] %= MOD;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	vector<int> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	init(tree, a, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			update(tree, 1, 0, n - 1, y - 1, z);
		}
		else {
			printf("%lld\n", query(tree, 1, 0,n-1, y - 1, z - 1));
		}
	}
	return 0;
}