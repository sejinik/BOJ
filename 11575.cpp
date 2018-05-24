#include <iostream>
#include <string>
using namespace std;

char abc[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

string temp;

string fun(string str,int a,int b) {
	temp = "";
	int num;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == abc[j])
				num = j;
		}
		temp += abc[(num * a + b) % 26];
	}

	return temp;
}

int main() {
	int Tcase;
	string str;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int a, b;
		scanf("%d %d", &a, &b);

		cin >> str;
		string ans = fun(str, a, b);
		cout << ans << endl;
	}
	return 0;
}