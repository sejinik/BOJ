#include <iostream>
#include <map>	
#include <algorithm>
#include <string>
using namespace std;
map<char, int> mp;
map<int, string > ip;

int go(string&s) {
	int ret = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		int c = mp[s[i + 1]] - mp[s[i]];
		if (c == 4 || c == 9 || c == 40 || c == 90 || c == 400 || c == 900) {
			ret += c;
			s[i + 1] = ' ';
			s[i] = ' ';
			i += 1;
		}
		else if (s[i] == s[i + 1]) {
			char A = s[i];
			for (int j = i; ; j++) {
				if (s[j] == A) {
					ret += mp[A];
					i = j;
					s[j] = ' ';
				}
				else break;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') ret += mp[s[i]];
	}
	return ret;
}

int main() {
	mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
	ip[1] = "I", ip[5] = "V", ip[10] = "X", ip[50] = "L", ip[100] = "C", ip[500] = "D", ip[1000] = "M";
	string str1, str2;
	cin >> str1 >> str2;
	int sum = go(str1) + go(str2);
	printf("%d\n", sum);

	int x = 1000;
	string str = "";
	while (x != 0) {
		int y = sum / x;
		if (y == 4) {
			if (x == 100) str += "CD";
			else if (x == 10) str += "XL";
			else str += "IV";
		}
		else if (y < 4) {
			while (y--) {
				str += ip[x];
			}
		}
		else if (y == 9) {
			if (x == 100) str += "CM";
			else if (x == 10) str += "XC";
			else str += "IX";
		}
		else {
			str += ip[5 * x];
			y -= 5;
			while (y--) str += ip[x];
		}
		sum %= x;
		x /= 10;
	}
	cout << str << endl;
	return 0;
}