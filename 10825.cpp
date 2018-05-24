#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

bool cmp(const student &u, const student &v) {
	return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}
int main() {
	int num;
	scanf("%d", &num);

	vector<student> vt(num);

	for (int i = 0; i < num; i++) {
		cin >> vt[i].name >> vt[i].kor >> vt[i].eng >> vt[i].math;
	}

	sort(vt.begin(), vt.end(), cmp);

	for (int i = 0; i < num; i++)
		cout << vt[i].name << "\n";

	return 0;
}