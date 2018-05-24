#include <iostream>
#include <string>
using namespace std;
int n, arr[30], ans;
void go(int pos, int state) {
	if (pos == n) {
		if (state == (1 << 26) - 1) ans++;
		return;
	}
	go(pos + 1, state | arr[pos]);
	go(pos + 1, state);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i] |= 1 << (str[j] - 'a');
		}
	}
	go(0, 0);
	printf("%d\n", ans);
	return 0;
}