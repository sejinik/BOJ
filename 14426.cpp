#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Node {
	bool vaild;
	int children[26];
	Node() {
		vaild = false;
		for (int i = 0; i < 26; i++) children[i] = -1;
	}
};

int init(vector<Node>&trie) {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

void add(vector<Node>&trie, int node, string& s, int index) {
	if (index == s.size()) {
		trie[node].vaild = true;
		return;
	}
	int c = s[index] - 'a';
	if (trie[node].children[c] == -1) {
		int next = init(trie);
		trie[node].children[c] = next;
	}
	add(trie, trie[node].children[c], s, index + 1);
}

bool check(vector<Node>&trie, int node, string&s, int index) {
	if (node == -1) return false;
	if (index == s.size()) return true;
	int c = s[index] - 'a';
	int child = trie[node].children[c];
	return check(trie, child, s, index + 1);
}

int main() {
	int ans = 0;
	int n, m; scanf(" %d %d", &n, &m);
	vector<Node> trie;
	int root = init(trie);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		add(trie, root, s, 0);
	}
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (check(trie, root, s, 0))	ans++;
	}
	printf("%d\n", ans); return 0;
}