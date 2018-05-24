#include <iostream>
using namespace std;
int main() {
	int a, b, v; scanf("%d %d %d", &a, &b, &v);
	int ans = 0;
	ans += (v - a) / (a - b);
	if ((v - a) % (a - b) != 0) ans += 2;
	else ans += 1;
	printf("%d\n", ans);
}