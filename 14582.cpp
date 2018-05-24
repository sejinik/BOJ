#include <iostream>
#include <algorithm>
using namespace std;
int a[10], b[10], as, bs;
bool check;
int main() {
	for (int i = 0; i < 9; i++) scanf(" %d", &a[i]);
	for (int i = 0; i < 9; i++) scanf(" %d", &b[i]);

	for (int i = 0; i < 9; i++) {
		if (as > bs) check = true;
		as += a[i];
		if (as > bs) check = true;
		bs += b[i];
		if (as > bs) check = true;
	}
	if (check)puts("Yes");
	else puts("No");
}