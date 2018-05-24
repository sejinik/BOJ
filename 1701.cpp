#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int preprocessing(string p) {
	int ret = 0;
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
		else 
			pi[i] = 0;

		ret = max(ret, pi[i]);
	}
	return ret;
}

int main() {
	string str;
	getline(cin, str);
	int m = str.size();
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int temp = preprocessing(str.substr(i, m));
		ans = max(ans, temp);
	}
	printf("%d\n", ans);
	return 0;
}