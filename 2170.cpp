#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge {
	int start, end;
	bool operator < (const Edge& other) const {
		if (start == other.start) return end < other.end;
		return start < other.start;
	}
};

int n,ans;
int main() {
	scanf(" %d", &n);
	vector<Edge> vt(n);
	for (int i = 0; i < n; i++) scanf(" %d %d", &vt[i].start, &vt[i].end);
	sort(vt.begin(), vt.end());

	ans = 0;
	int l = -1e9 - 1, r = -1e9 - 1;
	for (int i = 0; i < n; i++) {
		if (r < vt[i].start) {
			ans += (r - l);
			l = vt[i].start; 
			r = vt[i].end;
		}
		else r = max(r, vt[i].end);
	}
	ans += (r - l);
	printf("%d\n", ans);
}