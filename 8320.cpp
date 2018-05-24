#include <iostream>
using namespace std;

bool check[10010][10010];
int cnt;

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if(i*j <= num && check[j][i] != true)
			check[i][j] = true;
		}
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (check[i][j] == true)
				cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}