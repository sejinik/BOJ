#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int t, n;
set<int> s;

int main() {
	scanf("%d", &t);
	while (t--) {
		s.clear();
		scanf("%d", &n);
		vector<int> vt(n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			s.insert(a); vt[i] = a;
		}
		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			for (int j = i +1; j < n; j++) {
				int a = min(vt[i], vt[j]);
				int b = max(vt[i], vt[j]);
				int c = (b - a) / 2;
				if (abs(c + a) != abs(b - c)) continue;
				if (s.count(a + c) && s.count(b - c)) ans++;
			}
		}
		printf("%d\n", ans);
	}
}