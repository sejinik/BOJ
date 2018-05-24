#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<int> vt;
	set<pair<int, int>> s;
	int c = 0;
	for (int i = 0; a[i]; i++) {
		if (a[i] == ' ') {
			vt.push_back(c);
			c = 0; continue;
		}
		c *= 10; c += a[i] - '0';
	}
	if (c != 0) vt.push_back(c);
	int t = stoi(b);
	int n = vt.size();
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (i == j) continue;
			if (vt[i] + vt[j] == t) s.insert({ min(vt[i],vt[j]),max(vt[i],vt[j]) });
		}
	}
	set<pair<int, int>>::iterator it;
	for (it = s.begin(); it != s.end(); it++) printf("%d %d\n", (*it).first, (*it).second);
	printf("%d\n", s.size());
}
