#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n, k, cnt;
map<int, int> s;
map<int, int> f;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int c; scanf(" %d", &c);
		if (f.count(c)) s[f[c]] = -1;
		f[c] = i;
		s[i] = c;
	}
	for (int i = 0;i<k ; i++) {
		if (s[i] == -1) continue;
		printf("%08d\n", s[i]); cnt++;
		if (cnt == n || cnt==k) break;
	}
}