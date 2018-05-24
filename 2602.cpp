#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string str;
string arr[2];
int d[111][2][22];
int go(int pos, int ch, int index) {
	if (pos >= arr[0].size() || index >= str.size() || index<0) return 0;
	if ((index == str.size() - 1) && (arr[ch][pos] == str[index])) return 1;
	int&ret = d[pos][ch][index];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[ch][pos] == str[index])
		for (int i = pos + 1; i < arr[0].size(); i++) {
			if (arr[(ch + 1) % 2][i] == str[index + 1])
				ret += go(i, (ch + 1) % 2, index + 1);
		}
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> str >> arr[0] >> arr[1];
	int ans = 0;
	for (int i = 0; i < arr[0].size(); i++) {
		if (arr[0][i] == str[0]) ans += go(i, 0, 0);
		if (arr[1][i] == str[0]) ans += go(i, 1, 0);
	}
	printf("%d\n", ans);
	return 0;
}