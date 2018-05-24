#include <iostream>
using namespace std;

int main() {
	int a, b, c=0;
	scanf("%d %d", &a, &b);
	c = a * 12;
	if (c % 360 == b) puts("O");
	else puts("X");
	return 0;
}