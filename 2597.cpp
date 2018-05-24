#include <iostream>
#include <algorithm>
using namespace std;
double n,s,e;
double arr[3][2];
int main() {
	scanf("%lf", &n);
	e = n;
	for (int i = 0; i < 3; i++) {
		double a, b; scanf(" %lf %lf", &a, &b);
		arr[i][0] = min(a, b);
		arr[i][1] = max(a, b);
	}
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1]) continue;
		double mid = (s + e) / 2.0;
		double mid_i = (arr[i][0] + arr[i][1]) / 2.0;
		bool f = true;
		if (mid >= mid_i)s = mid_i;
		else e = mid_i, f = false;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				if (f) {
					if (arr[j][k] < s) arr[j][k] += (s - arr[j][k]) * 2;
				}
				else {
					if (arr[j][k] > e) arr[j][k] -= (arr[j][k] - e) * 2;
				}
			}
		}
	}
	printf("%.1lf\n", e - s);
}