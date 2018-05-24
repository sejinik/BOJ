#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

vector<int> kmp(string s, string p) {
	vector<int> pi = preprocessing(p);
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j += 1;
			}
		}
	}
	return ans;
}

int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	vector<int> match = kmp(s, p);
	int m = match.size();
	printf("%d\n", m);
	for (int i = 0; i < m; i++) printf("%d ", match[i] + 1);
	printf("\n");
	return 0;
}