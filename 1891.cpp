#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
ll arr[60];
string ans;
int main() {
	arr[0] = 1LL;
	for (int i = 1; i < 60; i++) arr[i] = arr[i - 1] * 2LL;
	ll d, a, b,x=0,y=0;
	string n;
	cin >> d >> n >> a >> b;
	ll pos = d;
	ll index = 0;
	while (pos--) {
		if (n[d-pos-1] == '1') x += arr[pos],y += arr[pos];
		else if(n[d-pos-1] == '2') y += arr[pos];
		else if (n[d-pos-1] == '4') x += arr[pos];
	}
	x += a; y += b;
	if (0 <= x && x < arr[d] && 0 <= y && y < arr[d]) {
		pos = d - 1;
		while (x >= 0 || y >= 0) {
			if (ans.size() == d) break;
			if (x >= arr[pos] && y >= arr[pos]) {
				ans += '1'; x -= arr[pos]; y -= arr[pos];
			}
			else if (y >= arr[pos]) {
				ans += '2'; y -= arr[pos];
			}
			else if (x >= arr[pos]) {
				ans += '4'; x -= arr[pos];
			}
			else ans += '3';
			pos--;
		}
		cout << ans << endl;
	}
	else puts("-1");
}