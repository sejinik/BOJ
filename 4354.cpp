#include <iostream>
#include <string>	
#include <algorithm>
#include <vector>
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
int main() {
	while (true) {
		string p;
		getline(cin, p);
		if (p == ".") return 0;
		vector<int> vt = preprocessing(p);
		int s = p.size();
		int ans = s / (s - vt[s - 1]);
		printf("%d\n", ans);
	}
}