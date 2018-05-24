#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int cnt;

int main() {
	map<string, int> mp;
	map<string, int>::iterator it;

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		mp[str]++;
	}
	for (int j = 0; j < k; j++) {
		string str;
		cin >> str;
		if (mp[str] == 1) {
			cnt++;
		}
		mp[str]++;
	}
	printf("%d\n", cnt);
	for (it = mp.begin(); it != mp.end();  ++it) {
		if (it->second != 1)
			cout << it->first << "\n";
	}
	return 0;
}