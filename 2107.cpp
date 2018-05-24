#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
struct Node {
	int start, end;
	bool operator < (const Node& other) const {
		return end < other.end;
	}
};
bool cmp( Node & a, Node &b) {
	return a.start < b.start;
}
int query(vector<int>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return 0;
	if (i <= start && end <= j)	return tree[node];
	return query(tree, node * 2, start, (start + end) / 2, i, j) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
void update(vector<int>&tree, int node, int start, int end,int index,int val) {
	if (index <start || index > end) return;
	if (start == end) {
		tree[node] = val; return;
	}
	update(tree, node * 2, start, (start + end) / 2, index,val);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index,val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	int n; scanf(" %d", &n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<Node> a(n + 1);
	vector<Node> b(n + 1);
	vector<int> tree(tree_size);
	for (int i = 1; i <= n; i++) {
		scanf(" %d %d", &a[i].start, &a[i].end);
		update(tree, 1, 1, n, i, 1);
	}
	b = a;
	sort(a.begin(), a.end());
	map<int, int> mp;
	for (int i = 1; i <= n; i++) mp[a[i].end] = i;
	for (int i = 1; i <= n; i++) b[i].end = mp[b[i].end];
	sort(b.begin(), b.end(), cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, query(tree, 1, 1, n, i, b[i].end) -1);
		update(tree, 1, 1, n, i,0);
	}
	printf("%d\n", ans);
}