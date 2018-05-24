#include <iostream>
using namespace std;

int arr[1000010];

int fun(int n) {
	if (n == 1000000)
		return n + n / 1000000 + (n % 1000000) / 100000 + (n % 100000) / 10000 + (n % 10000) / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;
	else if (n >= 100000)
		return n + n / 100000 + (n % 100000) / 10000 + (n % 10000) / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;

	else if (n >= 10000)
		return n + n / 10000 + (n % 10000) / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;

	else if (n >= 1000)
		return n + n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;

	else if (n >= 100)
		return n + n / 100 + (n % 100) / 10 + n % 10;
	else if (n >= 10)
		return n + n / 10 + n % 10;
	else
		return 2 * n;
}
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= 1000010; i++)
		arr[i] = i;
	for (int i = 1; i <= N; i++) {
		int num = fun(i);
		
		if (arr[num] > i)
			arr[num] = i;
	}
	if (arr[N] != N)
		printf("%d\n", arr[N]);
	else
		printf("%d\n", 0);

	return 0;
}