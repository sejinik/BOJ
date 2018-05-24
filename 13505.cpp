#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
struct Node {
	bool vaild;
	int children[2];
	Node() {
		vaild = false;
		memset(children, -1, sizeof(children));
	}
};

int init(vector<Node>&trie) {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

void add(vector<Node>&trie, int node, int num,int bit) {
	if (bit == -1) {
		trie[node].vaild = true;
		return;
	}
	int c = (num >> bit) & 1;
	if (trie[node].children[c] == -1) {
		int next =  init(trie);
		trie[node].children[c] = next;
	}
	add(trie, trie[node].children[c], num, bit - 1);
}

int find(vector<Node>&trie, int node, int num, int bit) {
	if (bit == -1) return 0;
	int c = (num >> bit) & 1;
	c = 1 - c;
	if (trie[node].children[c] == -1) c = 1 - c;
	if (trie[node].children[c] == -1) return 0;
	int next = 0;
	if (c == 1) next = 1 << bit;
	return next | find(trie, trie[node].children[c], num, bit - 1);
}
int main() {
	int ans = 0;
	vector<Node> trie;
	int root = init(trie);
	int n; scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf(" %d", &a);
		add(trie, root, a, 31);
		int temp = find(trie, root, a, 31) ^ a;
		ans = max(ans, temp);
	}
	printf("%d\n", ans);
}