#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 0,num=0;
	bool prev = true;
	for (int i = 0; i < str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num *= 10;
			num += str[i] - '0';
		}
		else if (str[i] == '+') {
			if (prev) ans += num;
			else 	ans -= num;
			num = 0;
		}
		else {
			if (prev) ans += num;
			else 	ans -= num;
			prev = false;
			num = 0;
		}
	}
	if (!prev) ans -= num;
	else ans += num;
	printf("%d\n", ans);
	return 0;
}