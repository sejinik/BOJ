#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void update(vector<int>&tree, vector<int>&tree_cnt, int node, int start, int end, int i, int j, int val) {
	if (i > end || j < start) return;
	if (i <= start && end <= j) tree_cnt[node] += val;
	else {
		update(tree, tree_cnt, node * 2, start, (start + end) / 2, i, j, val);
		update(tree, tree_cnt, node * 2 + 1, (start + end) / 2 + 1, end, i, j, val);
	}

	if (tree_cnt[node]) tree[node] = (end - start + 1);
	else {
		if (start == end) tree[node] = 0;
		else tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	int n; scanf(" %d", &n);
	int h = (int)ceil(log2(30030));
	int tree_size = (1 << (h + 1));
	vector<pair<pair<int, int>, pair<int, int>>> a(n * 2);
	vector<int> tree(tree_size);
	vector<int> tree_cnt(tree_size);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int X1, Y1, X2, Y2; scanf(" %d %d %d %d", &X1, &Y1, &X2, &Y2);
		a[cnt++] = { {X1,1},{Y1,Y2-1} };
		a[cnt++] = { {X2,-1},{Y1,Y2-1} };
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i <cnt-1; i++) {
		update(tree, tree_cnt, 1, 0, 30000, a[i].second.first, a[i].second.second, a[i].first.second);
		ans += (a[i + 1].first.first - a[i].first.first)*(tree[1]);
	}
	printf("%d\n", ans);
}