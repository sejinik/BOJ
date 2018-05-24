#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n,cnt;
int p[100050];
int ran[100050];

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	ran[x] += ran[y];
	p[y] = x;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		map<string, int> mp;
		memset(p, 0, sizeof(p));
		memset(ran, 0, sizeof(ran));
		cnt = 1;
		for (int i = 1; i <= 100010; i++) {
			p[i] = i;
			ran[i] = 1;
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char str1[22], str2[22];
			scanf(" %s %s", &str1, &str2);
			if (!mp.count(str1)) mp[str1] = cnt++;
			if (!mp.count(str2)) mp[str2] = cnt++;
			merge(mp[str1], mp[str2]);
			printf("%d\n", ran[p[mp[str1]]]);
		}
	}
	return 0;
}