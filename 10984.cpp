#include <iostream>
using namespace std;

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int num;
		scanf("%d", &num);

		int total_cred = 0;
		double ave_cred = 0;
		for (int i = 0; i < num; i++) {
			int cre=0;
			double sco=0;
			scanf("%d %lf", &cre, &sco);
			total_cred += cre;
			ave_cred += cre*sco;
		}

		printf("%d %.1lf\n", total_cred, ave_cred/(double)total_cred);
	}
	return 0;
}

