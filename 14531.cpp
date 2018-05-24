#include <string>
#include <iostream>
#include <cstring>
using namespace std;

bool alpha[26];
string arr[300];
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * 2; i++) {
		cin >> arr[i];
	}
	
	int ans = 0;
	for (int i = 0; i < m; i++) {
		memset(alpha, 0, sizeof(alpha));
		bool go = true;
		for (int j = 0; j < n; j++) {
			alpha[arr[j][i]-'A'] = true;
		}

		for (int j = n; j < n * 2; j++) {
			if (alpha[arr[j][i]-'A']) {
				go = false;
				break;
			}
		}
		if (go) ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}