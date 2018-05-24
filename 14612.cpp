#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<pair<int, int>> vt;

int main() {
	scanf("%d %d", &n, &m);
	vt.resize(m + 1);

	while (n--) {
		string str;
		cin >> str;

		if (str == "order") {
			int table, time;
			scanf("%d %d", &table, &time);
			vt.push_back(make_pair(time, table));

			for (int i = 0; i < vt.size(); i++) {
				if (vt[i].second)
					printf("%d ", vt[i].second);
			}
			printf("\n");
		}

		else if (str == "sort") {
			sort(vt.begin(), vt.end());
			
			bool check = true;
			for (int i = 0; i < vt.size(); i++)
				if (vt[i].second != 0)
					check = false;

			if (check)
				printf("sleep");

			else {
				for (int i = 0; i < vt.size(); i++) {
					if (vt[i].second)
						printf("%d ", vt[i].second);
				}
			}
			printf("\n");
		}

		else {
			int table;
			scanf("%d", &table);

			for (int i = 0; i < vt.size(); i++) 
				if (vt[i].second == table)
						vt[i].second = 0;
				

			bool check = true;
			for (int i = 0; i < vt.size(); i++)
				if (vt[i].second != 0)
					check = false;
			
			if (check)
				printf("sleep");
			else
				for (int i = 0; i < vt.size(); i++) {
					if (vt[i].second)
						printf("%d ", vt[i].second);
				}
			
			printf("\n");
		}

	}
	return 0;
}