#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s, p;
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

int kmp(string s, string p) {
	vector<int> pi = preprocessing(p);
	int ret = 0;
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ret++; 
				j = pi[m - 1];
			}
			else j++;
		}
	}
	return ret;
}
int main() {
	cin >> s >> p;
	printf("%d\n", kmp(s, p));
}