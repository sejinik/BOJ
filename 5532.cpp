#include <cstdio>

int L, A, B, C, D, math, korea;

int main() {
	scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);

	
	if (B%D == 0)
		math = B / D;
	else
		math = (B / D) + 1;

	if (A%C == 0)
		korea = A / C;
	else
		korea = (A / C) + 1;

	int ans = math;
	if (math < korea)
		ans = korea;

	printf("%d\n", L - ans);
	return 0;
	
}