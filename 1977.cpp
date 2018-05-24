#include <iostream>
using namespace std;

int arr[110];
int cnt;

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j*j == i)
				arr[cnt++] = i;
		}
	}

	bool flag = false;
	int sum = 0;
	for (int i = 0; i < 110; i++) {
		if (arr[i] != 0) {
			sum += arr[i];
			flag = true;
		}
	}

	if (flag) {
		printf("%d\n", sum);
		printf("%d\n", arr[0]);
	}
	else
		printf("-1\n");

	return 0;
}