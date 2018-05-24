#include <iostream>
#include <algorithm>
#include <set>	
#include <vector>
using namespace std;

int main() {
	int c, n;
	scanf(" %d %d", &c, &n);
	vector<pair<int, int>> cow(n);
	multiset<int> s;
	multiset<int>::iterator it;
	for (int i = 0; i < c; i++) {
		int x; scanf(" %d", &x);
		s.insert(x);
	}
	
	for (int i = 0; i < n; i++) scanf(" %d %d", &cow[i].second, &cow[i].first);
	sort(cow.begin(), cow.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		it = s.lower_bound(cow[i].second);
		if (it != s.end() && *it <= cow[i].first) {
			ans++; 
			s.erase(it);
		}
	}
	printf("%d\n", ans);
}