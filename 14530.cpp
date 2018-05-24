#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a, b;
int arr[2];

int cnt = 0;
int main() {
	scanf("%d %d", &a, &b);
		
	int sum = 0;
	int pos = 0;
	for (int i = 1; ; i *= -2) {
		pos = (a + i);
		if (i == 1) sum = 1;
		else sum += abs(pos - (a + (i / -2)));
		if (a > b) {
			if (pos <= b) break;
		}
		else
			if (pos >= b) break;
	}

	if (b > a) {
		if (pos > b)
			sum -= (pos - b);
	}
	else {
		if (pos < b) {
			sum -= abs(pos - b);
		}
	}
	printf("%d\n", abs(sum));
	return 0;
}