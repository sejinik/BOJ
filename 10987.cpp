#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	string str;
	cin >> str;
	int l = str.size();
	for (int i = 0; i < l; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') 
			ans += 1;
	}
	cout << ans << "\n";
	return 0;
}