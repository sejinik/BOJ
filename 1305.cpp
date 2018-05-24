#include <iostream>
#include <algorithm>
#include <string>
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
	string str;
	int n;
	scanf("%d ", &n);
	getline(cin,str);
	vector<int> pi = preprocessing(str);
	printf("%d\n", n - pi[n - 1]);
	return 0;
}