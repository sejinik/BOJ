#include <cstdio>
using namespace std;

int tcase;
int s;

int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		char a[10];
		scanf("%s", &a);

		if (a[0] == 'a' && a[1] == 'd') {
			int num;
			scanf("%s", &num);
			s = s | (1 << num);
		}
		else if (a[0] == 'r') {
			int num;
			scanf("%s", &num);
			s = s & ~(1 << num);
		}

		else if (a[0] == 'c') {
			int num;
			scanf("%s", &num);

			if (s&(1 << num)) 
				printf("1\n");
			
			else
				printf("0\n");
		}

		else if (a[0] == 't') {
			int num;
			scanf("%s", &num);
			s = s ^ (1 << num);
		}

		else if (a[0] == 'a' && a[1] == 'l') {
			s = (1 << 21) - 1;
		}

		else if (a[0] == 'e') {
			s = 0;
		}
	}
	return 0;
}