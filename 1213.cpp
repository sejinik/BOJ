#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[26];
string str,ans;


int main() {
	cin >> str;
	int m = str.size();
	for (int i = 0; i < m; i++) {
		arr[str[i] - 'A'] += 1;
	}
	int cnt = 0;
	for (int i = 0; i < 26; i ++ ) {
		if (arr[i] % 2 == 1) cnt += 1;
	}
	if (cnt > 1) {
		puts("I'm Sorry Hansoo"); return 0;
	}
	
	if (cnt % 2 == 0) {
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 0) continue;
			arr[i] /= 2;
			while (arr[i]--) {
				ans += (char)(i + 'A');
			}
		}
		string temp = ans;
		reverse(temp.begin(), temp.end());
		ans += temp;
		cout << ans << "\n";
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 0) continue;
			if (arr[i] % 2 == 1) {
				if (arr[i] == 1) continue;
				arr[i] /= 2;
				while (arr[i]--) ans += (char)(i + 'A');
				arr[i] = 1;
			}
			else {
				arr[i] /= 2;
				while (arr[i]--) {
					ans += (char)(i + 'A');
				}
			}
		}
		string temp = ans;
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 1)
				while (arr[i]--)
					ans += (char)(i + 'A');
		}

		ans += temp;
		cout << ans << "\n";
	}
	return 0;
}