#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		string s = "", p = "";
		string str;
		cin >> str;
		int n = str.size();
		int a = 0;
		for (int i = 0; i < n; i++, a += 2) {
			if (s.find(str[a%n]) != s.npos) break;
			s += str[a %n];
		}
		a = 1;
		for (int i = 0; i < n; i++, a += 2) {
			if (p.find(str[a%n]) != p.npos) break;
			p += str[a %n];
		}
		cout << s << "\n";
		cout << p << "\n";
	}
}