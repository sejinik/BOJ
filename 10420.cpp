#include <iostream>
using namespace std;
int y, d, m, n;
int main() {
	scanf("%d", &n);
	y = 2014, m = 4, d = 2;
	n -= 1;
	while (n--) {
		d += 1;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
			if (d == 32) {
				m += 1; d = 1;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d == 31) {
				m += 1; d = 1;
			}
		}
		else if (m == 12) {
			if (d == 32) {
				y += 1; m = 1; d = 1;
			}
		}
		else if(m==2){
			bool c = false;
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) c = true;
			if (d == 29 && !c) {
				m += 1; d = 1;
			}
			if (d == 30 && c) {
				m += 1; d = 1;
			}
		}
	}
		if(m<10 && d<10) printf("%d-0%d-0%d\n", y, m, d);
		if (m < 10 && d>=10) printf("%d-0%d-%d\n", y, m, d);
		if (m >= 10 && d < 10) printf("%d-%d-0%d\n", y, m, d);
		if (m >= 10 && d >= 10) printf("%d-%d-%d\n", y, m, d);
		return 0;
}