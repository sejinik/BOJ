#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string str, A, B, ans;
bool check[30];
int arr[30][2];
int n, m, t;
int main() {
	memset(arr, -1, sizeof(arr));
	scanf(" %d %d", &n, &m);
	cin >> A >> B;
	for (int i = 1; i <= n; i++) {
		arr[A[i - 1] - 'A'][0] = n - i + 1;
		arr[A[i-1] - 'A'][1] = 1;
	}
	for (int i = n + 1; i <= n + m; i++) {
		arr[B[i-n-1] - 'A'][0] = i;
		arr[B[i-n-1] - 'A'][1] = 2;
	}
	scanf(" %d", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 26; i++) {
			if (arr[i][0] == -1) continue;
			for (int j = 0; j < 26; j++) {
				if (arr[j][0] == -1 || i==j || check[j]) continue;
				if ((arr[i][0] + 1 == arr[j][0]) && (arr[i][1] +1 == arr[j][1])) {
					swap(arr[i][0], arr[j][0]);
					check[i] = check[j] = true; break;
				}
			}
		}
	}
	for (int i = 1; i <= n + m; i++) {
		for (int j = 0; j < 26; j++) {
			if (i == arr[j][0]) printf("%c", j + 'A');
		}
	}
	puts("");
}
