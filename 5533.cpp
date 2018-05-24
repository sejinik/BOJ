#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[200][3];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int j = 0; j < 3; j++) {
			bool ok = true;
			for (int k = 0; k < n; k++) {
				if (i == k) continue;
				if (arr[i][j] == arr[k][j]) ok = false;
			}
			if (ok) ans += arr[i][j];
		}
		printf("%d\n", ans);
	}
	return 0;
}