#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main() {
	int n, m; scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		s.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int x; scanf(" %d", &x);
		if (s.count(x)) s.erase(x);
	}

	int ans = s.size();
	if (ans == 0) puts("0");
	else {
		printf("%d\n", ans);
		for (auto it = s.begin(); it != s.end(); it++) printf("%d ", *it);
	}
}
