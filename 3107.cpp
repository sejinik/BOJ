#include <iostream>
#include <string>
using namespace std;
string s, ans;
int n,cnt;
int abs(int x) {
	if (x < 0) return -x;
	return x;
}
int main() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) if (s[i] == ':') cnt++;
	for (int i = 0; i < n; i++) {
		string p = "";
		int j = i;
		while (s[j] != ':' && j < n) {
			p += s[j];
			j++; i++;
		}
		if (p == "") {
			ans += "0000:";
			int c = abs(7-cnt);
			while (c--) ans += "0000:";
		}
		else {
			int c = 4 - p.size();
			while (c--) ans += '0';
			ans += (p + ':');
		}
	}
	cout << ans.substr(0, 39) << endl;
}