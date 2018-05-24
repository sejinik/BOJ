#include <iostream>
using namespace std;
bool arr[1000101], check[1000101];
int n,ans;

int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &check[i]);
	for (int i = 0; i < n; i++) {
		if (arr[i] != check[i]) {
			ans += 1; 
			arr[i] = (arr[i] + 1) % 2;
			arr[i + 1] = (arr[i + 1] + 1) % 2;
			arr[i + 2] = (arr[i + 2] + 1) % 2;
		}
	}
	printf("%d\n", ans);
}