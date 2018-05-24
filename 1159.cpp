#include <iostream>
#include <string>	
using namespace std;

int arr[26];

int main() {
	int n;
	scanf("%d", &n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr[str[0]-'a'] += 1;
	}
	string ret = "";
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			ret += (i + 'a');
		}
	}
	if (!ret.size()) puts("PREDAJA");
	else cout << ret << "\n";
	return 0;
}