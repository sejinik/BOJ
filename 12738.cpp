#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 1000000100
using namespace std;

int n;
int arr[1000010];
int d[1000010];

int main() {
	memset(d, 0x3f, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		d[i] = INF;
	}

	for (int i = 0; i < n; i++) {
		int pos = lower_bound(d, d + n, arr[i]) - d;
		d[pos] = arr[i];
	}

	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (d[i + 1] != INF)
			if (d[i] < d[i + 1])
				cnt += 1;
	}
	printf("%d\n", cnt);
	return 0;
}