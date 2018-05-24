#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, k;

void init(vector<long long>&tree, vector<long long>&a, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
	}
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long value) {
	if (index <start || index >end) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

long long query(vector<long long>& tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return -4200000000;
	if (i <= start && end <= j) return tree[node];
	long long m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	long long m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -4200000000) return m2;
	else if (m2 == -4200000000) return m1;
	else return m1*m2;
}
int main() {
	while (scanf("%d %d", &n, &k) != EOF) {
		vector<char> vt;
		vector<long long> a(n + 1);
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		vector<long long> tree(tree_size + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			if (a[i] > 0) a[i] = 1;
			else if (a[i] == 0) a[i] = 0;
			else a[i] = -1;
		}
		init(tree, a, 1, 1, n);
		for (int i = 0; i < k; i++) {
			char c;
			scanf(" %c", &c);
			if (c == 'C') {
				int x;
				long long y;
				scanf("%d %lld", &x, &y);
				if (y > 0) y = 1;
				else if (y == 0) y = 0;
				else y = -1;
				update(tree, 1, 1, n, x, y);
			}
			else {
				int x, y;
				scanf("%d %d", &x, &y);
				long long ans = query(tree, 1, 1, n, x, y);

				if (ans > 0)
					vt.push_back('+');
				else if (ans < 0)
					vt.push_back('-');
				else
					vt.push_back('0');
			}
		}
		for (int i = 0; i < vt.size(); i++) {
			printf("%c", vt[i]);
		}
		printf("\n");
	}
	return 0;
}