#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
double a, b, c;
double ans;
int main() {
	scanf(" %lf %lf %lf", &a, &b, &c);
	ans = max((a*b / c), (a / b*c));
	printf("%lld\n", (ll)ans);
}