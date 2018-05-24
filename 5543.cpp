#include <iostream>
using namespace std;

int main() {
	
	int buger=2000;
	int drink = 2000;

	for (int i = 0; i < 3; i++) {
		int bug;
		scanf("%d", &bug);
		if (bug <= buger)
			buger = bug;
	}
	for (int i = 0; i < 2; i++) {
		int dri;
		scanf("%d", &dri);
		if (dri <= drink)
			drink = dri;
	}
	printf("%d\n", buger + drink - 50);
	return 0;
}