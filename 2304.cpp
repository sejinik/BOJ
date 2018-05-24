#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,maxh;
struct Edge {
	int x, h;
	bool operator < (const Edge& other)	 const {
		return x < other.x;
	}
};

vector<Edge> vt;
int main() {
	int ans = 0;
	int pos = 0;
	scanf(" %d", &n);
	vt.resize(n);
	for (int i = 0; i < n; i++) {
		int x, h; scanf(" %d %d", &x, &h);
		vt[i] = { x,h };
		maxh = max(maxh, h);
	}
	
	sort(vt.begin(), vt.end());
	for (int i = 0; i < n; i++) {
		if (maxh == vt[i].h) {
			pos = i; break;
		}
	}
	int X = vt[0].x, H = vt[0].h;
	for (int i = 1; i < n; i++) {
		if (vt[i].h > H) {
			ans += (vt[i].x - X)*H;
			H = vt[i].h;
			X = vt[i].x;
		}
		if (i==pos) break;
	}
	ans += maxh;
	reverse(vt.begin(), vt.end());
	pos = n - pos - 1;
	X = vt[0].x;
	H = vt[0].h;
	for (int i = 1; i < n; i++) {
		if (vt[i].h > H || i==pos) {
			ans += (X - vt[i].x	)*H;
			H = vt[i].h;
			X = vt[i].x;
		}
		if (i == pos) break;
	}
	printf("%d\n", ans);
}