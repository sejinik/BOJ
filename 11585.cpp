#include <iostream>	
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else pi[i] = 0;
	}
	return pi;
}

int kmp(string s, string p) {
	int cnt = 0;
	vector<int> pi = preprocessing(p);
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				cnt += 1;
				j = pi[m - 1];
			}
			else j += 1;
		}
	}
	return cnt;
}

int gcd(int x, int y) {
	if (x % y == 0) return y;
	else return gcd(y, x%y);
}

int main() {
	string s = "", p = "";
	int n;
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		char a;
		scanf(" %c", &a);
		p += a;
	}
	for (int i = 0; i < n; i++) {
		char a;
		scanf(" %c", &a);
		s += a;
	}
	s += s.substr(0, s.size() - 1);
	int ans = kmp(s, p);
	int g = gcd(n, ans);
	printf("%d/%d\n", ans / g, n / g);
	return 0;
}