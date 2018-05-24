#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct person {
	int age;
	string name;
	int turn;
}person;

bool cmp(person u, person v) {
	return(u.age < v.age) || (u.age == v.age && u.turn < v.turn);
}
int main() {
	int num;
	scanf("%d", &num);

	vector<person> vt(num);
	for (int i = 0; i < num; i++) {
		cin >> vt[i].age >> vt[i].name;
		vt[i].turn = i;
	}

	sort(vt.begin(), vt.end(), cmp);

	for (int i = 0; i < num; i++) {
		cout << vt[i].age << " " << vt[i].name << endl;
	}
	return 0;
}