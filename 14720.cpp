#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[1010];
int d[1010];

int go(int index, int milk) {
	if (index >= n) return 0;
	int &ret = d[index];
	if (ret != -1) return ret;

	if (arr[index] == milk)
		return ret = go(index + 1, (milk + 1) % 3) + 1;
	return ret = go(index + 1, milk);
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", go(0, 0));
	return 0;
}