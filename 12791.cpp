#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<pair<int, string>> vt(25);

int main() {
	vt[0].first = 1967; vt[0].second = "DavidBowie";
	vt[1].first = 1969; vt[1].second = "SpaceOddity";
	vt[2].first = 1970; vt[2].second ="TheManWhoSoldTheWorld";
	vt[3].first = 1971; vt[3].second = "HunkyDory";
	vt[4].first = 1972; vt[4].second = "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars";
	vt[5].first = 1973; vt[5].second = "AladdinSane";
	vt[6].first = 1973; vt[6].second = "PinUps";
	vt[7].first = 1974; vt[7].second = "DiamondDogs";
	vt[8].first = 1975; vt[8].second = "YoungAmericans";
	vt[9].first = 1976; vt[9].second = "StationToStation";
	vt[10].first = 1977; vt[10].second = "Low";
	vt[11].first = 1977; vt[11].second = "Heroes";
	vt[12].first = 1979; vt[12].second = "Lodger";
	vt[13].first = 1980; vt[13].second = "ScaryMonstersAndSuperCreeps";
	vt[14].first = 1983; vt[14].second = "LetsDance";
	vt[15].first = 1984; vt[15].second = "Tonight";
	vt[16].first = 1987; vt[16].second = "NeverLetMeDown";
	vt[17].first = 1993; vt[17].second = "BlackTieWhiteNoise";
	vt[18].first = 1995; vt[18].second = "1.Outside";
	vt[19].first = 1997; vt[19].second = "Earthling";
	vt[20].first = 1999; vt[20].second = "Hours";
	vt[21].first = 2002; vt[21].second = "Heathen";
	vt[22].first = 2003; vt[22].second = "Reality";
	vt[23].first = 2013; vt[23].second = "TheNextDay";
	vt[24].first = 2016; vt[24].second = "BlackStar";

	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		int cnt = 0;
		for (int i = 0; i < 25; i++) {
			if (vt[i].first >= a && vt[i].first <= b)
				cnt++;
		}
		printf("%d\n", cnt);
		for (int i = 0; i < 25; i++) {
			if (vt[i].first >= a && vt[i].first <= b) {
				cout << vt[i].first << " " << vt[i].second << endl;
			}
		}
	}
	return 0;
}