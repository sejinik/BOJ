#include <iostream>
using namespace std;

int main() {
	double R;
	scanf("%lf", &R);

	double u;
	double t;
	u = R*R*3.1415926535897932384626;
	t = R*R * 2;

	printf("%.6lf\n", u);
	printf("%.6lf\n", t);
	
	return 0;
}