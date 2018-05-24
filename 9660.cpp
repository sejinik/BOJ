#include <iostream>
using namespace std;
#define ll long long
int main() {
	ll n; scanf(" %lld", &n);
	if (n % 7 == 0 || n % 7 == 2) puts("CY");
	else puts("SK");
}