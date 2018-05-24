#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	string c;
	
	scanf("%d %d", &a, &b);
	cin >> c;
	
	int num = int(c[c.size() - 1] - '0');

	if (num%2==0)
		printf("%d\n", a);
	else
		printf("%d\n", a^b);

	return 0;
}