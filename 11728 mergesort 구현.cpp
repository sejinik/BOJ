#include <cstdio>

int n, m;
int arr[2000010];
int temp[2000010];

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}

	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int i = start; i <= end; i++) {
		arr[i] = temp[i - start];
	}
}

void sort(int start, int end) {
	if (start == end)
		return;

	int mid = (start + end) / 2;

	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}



int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n + m; i++) {
		scanf("%d", &arr[i]);
	}

	sort(0, (n + m - 1));
	for (int i = 0; i < n + m; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}