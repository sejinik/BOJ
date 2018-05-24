#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int update(vector<int>&tree, int node, int start, int end, int index) {
	if (index <start || index > end) return 0;
	if (start == end) return tree[node] = 1;
	update(tree, node * 2, start, (start + end) / 2, index);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
	return tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>&tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start)	 return 0;
	if (i <= start && end <= j) return tree[node];
	return query(tree, node * 2, start, (start + end) / 2, i, j) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	int n; scanf(" %d", &n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	map<int, int> mp;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	vector<int>tree(tree_size, 0);
	for (int i = 1; i <= n; i++) scanf(" %d", &a[i]);
	b = a;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 1; i <= n; i++) mp[a[i]] = i;
	for (int i = 1; i <= n; i++) b[i] = mp[b[i]];
	for (int i = 1; i <= n; i++) {
		printf("%d\n", i - query(tree, 1, 1, n, 1, b[i]));
		update(tree, 1, 1, n, b[i]);
	}

}