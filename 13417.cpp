#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t, n;

int main() {
	scanf(" %d", &t);
	while (t--) {
		scanf(" %d", &n);
		string ans = "";
		for (int i = 0; i < n; i++) {
			char a; scanf(" %c", &a);
			if (i == 0) ans += a;
			else {
				if (ans[0] - 'A' < a - 'A') ans += a;
				else ans = a + ans;
			}
		}
		cout << ans << "\n";
	}
}