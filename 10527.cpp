#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
map<string, int> mp1;
map<string, int > mp2;
set < string> st;
int main() {
	int n; scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (!mp1.count(s)) mp1[s] = 1;
		else mp1[s]++;
		st.insert(s);
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (!mp2.count(s)) mp2[s] = 1;
		else mp2[s]++;
		st.insert(s);
	}

	int ans = 0;
	set<string>::iterator it;
	for (it = st.begin(); it != st.end(); it++) {
		ans += min(mp1[*it], mp2[*it]);
	}
	printf("%d\n", ans);
}