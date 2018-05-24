#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
set<string> s;
vector<pair<pair<string, string>, pair<int, int>>> vt(16);
int main() {
	int t; scanf(" %d", &t);
	while (t--) {
		s.clear();
		for (int i = 0; i < 16; i++) {
			string a, b; int c, d;
			cin >> a >> b >> c >> d;
			vt[i] = { {a,b},{c,d} };
			s.insert(a);
			s.insert(b);
		}

		for (int i = 0; i < 16; i++) {
			string a = vt[i].first.first;
			string b = vt[i].first.second;
			int c = vt[i].second.first;
			int d = vt[i].second.second;
			if (c > d && s.count(b)) s.erase(b);
			if (c < d && s.count(a)) s.erase(a);
		}
		auto it = s.begin();
		cout << *it << "\n";
	}
}