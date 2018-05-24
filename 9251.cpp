#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1010][1010];
string str1, str2;

int func(int x, int y) {

	if (x == 0 || y == 0) return 0;

	int&ref = dp[x][y];
	if (ref != -1) return ref;

	if (str1[x - 1] == str2[y - 1])
		ref = func(x - 1, y - 1) + 1;
	else
		ref = max(func(x - 1, y), func(x, y - 1));
	
	return ref;
}
int main() {
	
	memset(dp, -1, sizeof(dp));
	cin >> str1 >> str2;

	printf("%d\n", func(str1.size(), str2.size()));
	return 0;
}