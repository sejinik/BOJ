#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, f; 
	scanf("%d %d", &n, &f);
	int num = n - (n % 100);
	for (int i = num; i < num + 100; i++) 
		if (!(i%f)) {
			int ans = i % 100;
			if (ans < 10) printf("0%d\n", ans);
			else printf("%d\n", ans);
			return 0;
		}
	
}