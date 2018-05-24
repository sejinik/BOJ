#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a, b, c, d;
int k;

void ch(string &str) {
	str = str[7] + str;
	str = str.substr(0, 8);
}

void rch(string &str) {
	str = str + str[0];
	str = str.substr(1, 9);
}
void go(int u, int v, int pos) {
	bool prev = false, aft = false;
	if (u == 1) {
		if (pos == 0) {
			if (a[2] != b[6]) aft = true;
		}
		if (v == 1) ch(a);
		else rch(a);

		if (aft) go(2, -v,2);
	}
	else if (u == 2) {
		if (pos == 0) {
			if (a[2] != b[6]) prev = true;
			if (b[2] != c[6]) aft = true;
		}
		else if (pos == 1) {
			if (a[2] != b[6]) prev = true;
		}
		else {
			if (b[2] != c[6]) aft = true;
		}
		if (v == 1) ch(b);
		else rch(b);

		if (prev)go(1, -v,1);
		if (aft)go(3, -v,2);
	}
	else if (u == 3) {
		if (pos == 0) {
			if (b[2] != c[6]) prev = true;
			if (c[2] != d[6]) aft = true;
		}
		else if (pos == 1) {
			if (b[2] != c[6]) prev = true;
		}
		else {
			if (c[2] != d[6]) aft = true;
		}
		if (v == 1) ch(c);
		else rch(c);

		if (prev) go(2, -v,1);
		if (aft) go(4, -v,2);
	}
	else {
		if (pos == 0) {
			if (c[2] != d[6]) prev = true;
		}
		if (v == 1) ch(d);
		else rch(d);

		if (prev) go(3, -v,1);
	}
}
int main() {
	cin >> a >> b >> c >> d;

	scanf(" %d", &k);
	for (int i = 0; i < k; i++) {
		int u, v; scanf(" %d %d", &u, &v);
		go(u, v,0);
	}
	int ans = 0;
	if (a[0] == '1') ans += 1;
	if (b[0] == '1') ans += 2;
	if (c[0] == '1') ans += 4;
	if (d[0] == '1') ans += 8;
	printf("%d\n", ans);
}