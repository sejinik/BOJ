#include <iostream>
using namespace std;
#define ll long long
int arr[500050], temp[500050], n;

ll merge(int s, int e) {
	ll ret = 0;
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = 0;
	while (i <= mid && j <= e) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			ret += (ll)(mid - i + 1);
		}
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= e) temp[k++] = arr[j++];
	for (int i = s; i <= e; i++) arr[i] = temp[i - s];
	return ret;
}
ll sort(int s, int e) {
	if (s == e) return 0;
	ll ret = 0;
	return ret = sort(s, (s + e) / 2) + sort((s + e) / 2 + 1, e) + merge(s, e);
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	printf("%lld\n", sort(0, n - 1));
}