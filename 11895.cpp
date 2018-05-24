#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int num;
	scanf("%d", &num);

	int mini = 987654321;
	int a;
	
	scanf("%d", &a);
	int sum = a;
	mini = min(a, mini);

	for (int i = 0; i < num-1; i++) {
		int n;
		scanf("%d", &n);
		mini = min(mini, n);
		sum += n;
		a = a^n;
	}

	if (a == 0) 
		printf("%d\n", sum - mini);
	
	else
		printf("0\n");
	return 0;
}