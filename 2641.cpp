#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string ans[111];
vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else pi[i] = 0;
	}
	return pi;
}
bool kmp(string s, string p) {
	int n = s.size();
	int m = p.size();
	vector<int> pi = preprocessing(p);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) return true;
			else j += 1;
		}
	}
	return false;
}

int main() {
	int n; scanf("%d", &n);
	string s = "", rev = "";
	for (int i = 0; i < n; i++) {
		int a; scanf(" %d", &a);
		s += (char)(a + '0');
		a = (a + 2) % 4;
		if (!a) a = 4;
		rev += (char)(a + '0');
	}
	reverse(rev.begin(), rev.end());
	s += s; rev += rev;
	int m; scanf("%d", &m);
	int cnt = 0;
	while (m--) {
		string t = "";
		for (int i = 0; i < n; i++) {
			int a; scanf(" %d", &a);
			t += (char)(a + '0');
		}
		if (kmp(s, t)) {
			ans[cnt++] = t; continue;
		}
		if (kmp(rev, t)) ans[cnt++] = t;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", ans[i][j]);
		}
		puts("");
	}
}