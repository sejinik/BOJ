#include <iostream>
using namespace std;
bool check[1010];
int main() {
	int n; scanf("%d", &n);
	check[0] = true;
	for (int i = 1; i <= n; i++) {
		check[i] = false;
		if (i - 1 >= 0 && check[i - 1] == false) check[i] = true;
		if (i - 3 >= 0 && check[i - 3] == false) check[i] = true;
		if (i - 4 >= 0 && check[i - 4] == false) check[i] = true;
	}
	printf("%s\n", check[n] ? "SK" : "CY");
}