#include <cstdio>
using namespace std;

int n;

int arr[11][1];
int main() {
	for (int i = 1; i <= 10; i++) {
		arr[i][0] = -1;
	}

	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (arr[a][0] == -1) {
			arr[a][0] = b;
		}
		else if (arr[a][0] == 1) {
			if (b == 0) {
				arr[a][0] = 0;
				cnt += 1;
			}
		}
		else {
			if (b == 1) {
				arr[a][0] = 1;
				cnt += 1;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}