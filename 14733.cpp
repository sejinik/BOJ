#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

void update(vector<int>&tree, vector<int>&tree_cnt, int node, int start, int end, int i, int j, int val) {
	if (i > end || j < start) return;
	if (i <= start && end <= j) tree_cnt[node] += val;
	else {
		update(tree, tree_cnt, node * 2, start, (start + end) / 2, i, j, val);
		update(tree, tree_cnt, node * 2 + 1, (start + end) / 2 + 1, end, i, j, val);
	}
	if (tree_cnt[node]) tree[node] = (end - start + 1);
	else tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	int n; scanf(" %d", &n);
	vector<pair<pair<int,int>,pair<int,int>>> a(n * 2);
	vector<int> tree(1000400);
	vector<int> tree_cnt(1000400);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
		x1 += 50000;
		y1 += 50000;
		x2 += 50000;
		y2 += 50000;
		a[cnt++] = { {x1,1},{y1,y2 - 1} };
		a[cnt++] = { {x2,-1},{y1,y2 - 1} };
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for (int i = 0; i < cnt - 1; i++) {
		update(tree, tree_cnt, 1, 0, 100000, a[i].second.first, a[i].second.second, a[i].first.second);
		ll res = (ll)a[i + 1].first.first - (ll)a[i].first.first;
		ans += res*(ll)tree[1];
	}
	printf("%lld\n", ans);
}