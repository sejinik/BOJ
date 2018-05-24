#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,ans;
int arr[111];
bool par[111], chd[111];
set<int> s;
set<int> f;
vector<int> vt;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		memset(par, 0, sizeof(par));
		memset(chd, 0, sizeof(chd));
		s.clear(); f.clear();

		int pos = i;
		int pos_child = arr[i];

		while (true) {
			par[pos] = true;
			chd[pos_child] = true;
			s.insert(pos);
			f.insert(pos_child);

			pos = pos_child;
			pos_child = arr[pos];
			if (par[pos])break;
		}


		bool ok = true;
		if (s.size() != f.size()) ok = false;
		else {
			for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
				if (!f.count(*it)) ok = false;
			}
		}
		if (ok) {
			vt.push_back(i); ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < vt.size(); i++) printf("%d\n", vt[i]);
	return 0;
}