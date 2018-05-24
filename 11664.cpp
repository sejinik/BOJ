#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double dist(double x2, double y2, double z2, double x1, double y1, double z1) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
}

int main() {
	double x1, x2, x3, y1, y2, y3, z1, z2, z3, dx, dy, dz;
	scanf(" %lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	double l = 0.0, r = 1.0, m = 0;
	while (true) {
		if (fabs(r - l) < 1e-9) {
			m = (l + r) / 2; break;
		}
		double m1 = l + (r - l) / 3.0;
		double m2 = r - (r - l) / 3.0;
		double fx = x1 + dx*m1;
		double fy = y1 + dy*m1;
		double fz = z1 + dz*m1;
		double sx = x1 + dx*m2;
		double sy = y1 + dy*m2;
		double sz = z1 + dz*m2;
		double a = dist(x3, y3, z3, fx, fy, fz);
		double b = dist(x3, y3, z3, sx, sy, sz);
		if (a > b) l = m1;
		else r = m2;
	}
	double ans = dist(x3, y3, z3, x1 + dx*m, y1 + dy*m, z1 + dz*m);
	printf("%.10lf\n", ans);
}