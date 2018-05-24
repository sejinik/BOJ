#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1010];
int n;

int choosepivot(int low, int high) {
	return (low + high) / 2;
}
int partition(int low, int high) {
	int pivot = choosepivot(low, high);
	int pivotValue = arr[pivot];
	swap(arr[pivot], arr[high]);
	int storeindex = low;
	for (int i = low; i < high; i++) {
		if (arr[i] < pivotValue) {
			swap(arr[i], arr[storeindex]);
			storeindex += 1;
		}
	}
	swap(arr[storeindex], arr[high]);
	return storeindex;
}
void quicksort(int low, int high) {
	if (low < high) {
		int pivot = partition(low, high);
		quicksort(low, pivot);
		quicksort(pivot + 1, high);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quicksort(0, n - 1);
	
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}