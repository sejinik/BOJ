#include <cstdio>
#include <algorithm>
using namespace std;
int n;
double arr[101];

int main() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	arr[0] = x / y * 1000;

	scanf("%d", &n);
	for (int i = 1; i < n+1; i++) {
		scanf("%lf %lf", &x, &y);
		arr[i] = x / y * 1000;
	}

	sort(arr, arr + n+1);
	printf("%.2lf\n", arr[0]);
	return 0;
}