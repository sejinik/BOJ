#include <iostream>
#include <algorithm>
using namespace std;
int arr[11111];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	int cnt = 1;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			arr[cnt++] = i;
			if(i != n/i)	arr[cnt++] = n / i;
		}
	}
	sort(arr, arr + cnt);
	printf("%d\n", arr[k]);
	return 0;
}