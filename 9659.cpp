#include <iostream>
using namespace std;
#define ll long long
int main() {
	ll n; scanf(" %lld", &n);
	printf("%s\n", (n & 1) ? "SK" : "CY");
}