#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
#define INF 1e+9
int c, n, o;
void update_lazy(vector<int>&tree, vector<int>&lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update_max_range(vector<int>&tree, vector<int>&lazy, int node, int start, int end, int i, int j, int val) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return;
	if (i <= start&& end <= j) {
		tree[node] += val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	update_max_range(tree, lazy, node * 2, start, (start + end) / 2, i, j, val);
	update_max_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j, val);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
void update_min_range(vector<int>& tree, vector<int>&lazy, int node, int start, int end, int i, int j, int val) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return;
	if (i <= start && end <= j) {
		tree[node] += val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	update_min_range(tree, lazy, node * 2, start, (start + end) / 2, i, j, val);
	update_min_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j, val);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int max_query(vector<int>&tree, vector<int>& lazy, int node, int start, int end, int i,int j) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return max(max_query(tree, lazy, node * 2, start, (start + end) / 2, i,j), max_query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i,j));
}
int min_query(vector<int>&tree, vector<int>&lazy, int node, int start, int end, int i, int j) {
	update_lazy(tree, lazy, node, start, end);
	if (i > end || j < start) return INF;
	if (i<=start && end<=j) return tree[node];
	return min(min_query(tree, lazy, node * 2, start, (start + end) / 2, i,j), min_query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i,j));
}

int main() {
	scanf("%d %d %d", &c, &n, &o);
	int h = (int)ceil(log2(c));
	int tree_size = (1 << (h + 1));
	vector<int> max_tree(tree_size);
	vector<int> min_tree(tree_size);
	vector<int> max_lazy(tree_size);
	vector<int> min_lazy(tree_size);
	
	char str[22];
	for (int i = 0; i < o; i++) {
		scanf(" %s", &str);
		if (str[0] == 's') {
			int pos; scanf("%d", &pos);
			printf("%d\n", max_query(max_tree, max_lazy, 1, 0, c - 1, pos,pos));
		}
		else if (str[0] == 'g') {
			int s, e, v; scanf(" %d %d %d", &s, &e, &v);
			if (v > 0) {
				int pv = max_query(max_tree, max_lazy, 1, 0, c - 1, s, e);
				if (pv + v > n) {
					v = n - pv;
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, s, e, v);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, s, e, v);
				}
				else {
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, s, e, v);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, s, e, v);
				}
				printf("%d\n", v);
			}
			else {
				int pv = min_query(min_tree, min_lazy, 1, 0, c - 1, s, e);
				if (pv == INF) pv = 0;
				if (pv + v < 0) {
					v = -pv;
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, s, e, v);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, s, e, v);
				}
				else {
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, s, e, v);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, s, e, v);
				}
				printf("%d\n", v);
			}
		}
		else {
			int pos, val; scanf("%d %d", &pos, &val);
			if (val > 0) {
				int pv = max_query(max_tree, max_lazy, 1, 0, c - 1, pos, pos);
				if (val + pv > n) {
					val = n - pv;
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, pos, pos, val);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, pos, pos, val);
				}
				else {
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, pos, pos, val);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, pos, pos, val);
				}
				printf("%d\n", val);
			}
			else {
				int pv = min_query(min_tree, min_lazy, 1, 0, c - 1, pos, pos);
				if (val + pv < 0) {
					val = -pv;
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, pos, pos, val);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, pos, pos, val);
				}
				else {
					update_max_range(max_tree, max_lazy, 1, 0, c - 1, pos, pos, val);
					update_min_range(min_tree, min_lazy, 1, 0, c - 1, pos, pos, val);
				}
				printf("%d\n", val);
			}
		}
	}
	return 0;
}