#include <iostream>
using namespace std;

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int r, e, c, in;
		scanf("%d %d %d", &r, &e, &c);
		in = e - c;

		if (r > in)
			printf("do not advertise\n");
		else if (r < in)
			printf("advertise\n");
		else
			printf("does not matter\n");
	}
	return 0;
}