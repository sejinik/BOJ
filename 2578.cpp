#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int arr[5][5];
bool check[5][5];
map<int, pair<int, int>> mp;
int go() {
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		bool r = true, l = true;
		for (int j = 0; j < 5; j++) {
			if (!check[i][j]) r = false;
			if (!check[j][i]) l = false;
		}
		if (r) ret += 1;
		if (l) ret += 1;
	}
	bool g = true;
	bool k = true;
	for (int i = 0; i < 5; i++) {
		if (!check[i][i]) g = false;
		if (!check[i][4 - i]) k = false;
	}
	if (g) ret += 1;
	if (k) ret += 1;
	return ret;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %d", &arr[i][j]);
			mp[arr[i][j]] = { i,j };
		}
	}
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num; scanf(" %d", &num);
			cnt += 1;
			pair<int, int> n = mp[num];
			check[n.first][n.second] = true;
			if (go() >= 3) {
				printf("%d\n", cnt); return 0;
			}
		}
	}
}