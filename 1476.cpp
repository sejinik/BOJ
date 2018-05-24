#include <cstdio>
using namespace std;

int main() {
	int E, S, M;
	scanf("%d%d%d", &E, &S, &M);

	int e = 1, s = 1, m = 1;

	for (int i = 1;; i++) {
		if (e == E && s == S && m == M) {
			printf("%d\n", i);
			return 0;
		}

		e++;
		s++;
		m++;

		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
	}
}