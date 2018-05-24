#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct circle {
	int x;
	int y;
	int r;
	circle(int x, int y, int r) : x(x), y(y), r(r) {
	}
};
double Dist(circle &a, circle&b) {
	return (double)sqrt((pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2)));
}
double R_dist(circle &a, circle&b) {
	return (double)( a.r + b.r);
}
int main() {
	int t; 
	scanf("%d", &t);
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		circle Jo(x1, y1, r1);
		circle Back(x2, y2, r2);
		double dist = Dist(Jo, Back);
		double r_dist = R_dist(Jo, Back);
		int min_r = min(Jo.r, Back.r);
		int max_r = max(Jo.r, Back.r);
		if ((dist == 0) && (Jo.r == Back.r)) puts("-1");
		else if (dist > r_dist) puts("0");
		else if (dist == r_dist) puts("1");
		else {
			if (dist == (double)(max_r - min_r)) puts("1");
			else if (dist < (double)(max_r - min_r)) puts("0");
			else puts("2");
		}	
	}
	return 0;
}
