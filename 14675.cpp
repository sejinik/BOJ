#include <iostream>
#include <algorithm>
using namespace std;
int tin[100100];
int tout[100100];

int main() {
	int n; scanf(" %d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		tout[a] += 1;
		tin[a] += 1;
		tin[b] += 1;
		tout[b] += 1;
	}

	int k; scanf(" %d", &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		if (a == 2) puts("yes");
		else {
			if (tout[b] == 1 && tin[b]==1) puts("no");
			else puts("yes");
		}
	}
}