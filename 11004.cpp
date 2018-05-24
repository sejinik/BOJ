#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000011];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}

	sort(arr, arr + N);
	for (int i = 0; i < K; i++) {
		if(i == K-1)
		printf("%d\n", arr[i]);
	}
	return 0;
}