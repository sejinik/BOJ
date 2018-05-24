#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node {
	int x, y;
	bool operator < (const Node& other) const {
		if (y == other.y) return x < other.x;
		return y < other.y;
	}
};
int dist(Node a, Node b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool cmp(Node&a, Node&b) {
	return a.x < b.x;
}
int main() {
	int n; scanf(" %d", &n);
	vector<Node> vt(n);
	set<Node> s;
	for (int i = 0; i < n; i++) scanf(" %d %d", &vt[i].x, &vt[i].y);
	sort(vt.begin(), vt.end(),cmp);
	s.insert(vt[0]);
	s.insert(vt[1]);
	int pos = 0;
	int ans = dist(vt[0], vt[1]);
	for (int i = 2; i < n; i++) {
		while (pos < i) {
			int d = vt[i].x - vt[pos].x;
			if (d*d <= ans) break;
			else s.erase(vt[pos]), pos++;
		}
		int d = (int)sqrt((double)ans) + 1;
		auto l = s.lower_bound({ -100000,vt[i].y - d });
		auto r = s.upper_bound({ 100000,vt[i].y + d });
		for (auto it = l; it != r; it++) ans = min(ans, dist(*it, vt[i]));
		s.insert(vt[i]);
	}
	printf("%d\n", ans);
	return 0;
}