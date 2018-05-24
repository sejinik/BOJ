#include <iostream>
#include <algorithm>
using namespace std;
int arr[1010][5];
int n,ans,pos;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 4; k++) {
				for (int l = k + 1; l < 5; l++) {
					int temp = (arr[i][j] + arr[i][k] + arr[i][l]) % 10;
					if (temp >= ans) {
						ans = temp; pos = i;
					}
				}
			}
		}
	}
	printf("%d\n", pos + 1);
}
