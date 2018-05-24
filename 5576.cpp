#include <iostream>
#include <algorithm>
using namespace std;

int arr1[10];
int arr2[10];

int main() {
	
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr1[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr2[i]);

	sort(arr1, arr1 + 10);
	sort(arr2, arr2 + 10);

	int sum1, sum2;

	sum1 = arr1[7] + arr1[8] + arr1[9];
	sum2 = arr2[7] + arr2[8] + arr2[9];

	printf("%d %d\n", sum1, sum2);
	return 0;
}