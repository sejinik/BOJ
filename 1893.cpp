#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
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

bool kmp(string s, string p) {
	int ret = 0;

	vector<int> pi = preprocessing(p);
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ret += 1;
				j = pi[j];
			}
			else j += 1;
		}
	}

	if (ret == 1) return true;
	return false;
}

int main() {
	int n;
	scanf("%d ", &n);
	while (n--) {
		map<char, int> num_mp;
		map<int, char> char_mp;
		string A, W, S;
		getline(cin, A);
		getline(cin, W);
		getline(cin, S);
		int n = A.size();
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			num_mp[A[i]] = i;
			char_mp[i] = A[i];
		}

		for (int i = 0; i < n; i++) {
			string temp = S;
			for (int j = 0; j < S.size(); j++) {
				temp[j] = char_mp[(num_mp[S[j]] + i)%n];
			}
			if (kmp(temp, W)) ans.push_back((n-i)%n);
		}

		sort(ans.begin(), ans.end());
		if (ans.empty()) puts("no solution");
		else if (ans.size() == 1) {
			printf("unique: %d\n", ans[0]);
		}
		else {
			printf("ambiguous: ");
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}