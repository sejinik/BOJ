#include <iostream>
using namespace std;
int arr[111], ans[111], pos[111],aft[111];
int main() {
	int n; scanf(" %d", &n);
	for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]), pos[i] = i;
	int cc = 3;
	while (cc--) {
		for (int i = 1; i <= n; i++) {
			int c = pos[i];
			aft[arr[i]] = c;
		}
		for (int i = 1; i <= n; i++) pos[i] = aft[i];
	}
	for (int i = 1; i <= n; i++) {
		int x; scanf(" %d", &x); ans[pos[i]] = x;
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}