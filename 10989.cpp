#include <iostream>
#include <algorithm>
using namespace std;

int cnt[10001];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int a;
		scanf("%d", &a);
		cnt[a] ++;
	}
	for (int i = 1; i <=10000; i++) {
		if (cnt[i] > 0) {
			for (int j = 0; j < cnt[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}