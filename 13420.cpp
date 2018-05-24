#include <iostream>
using namespace std;
#define ll long long
ll t;
int main() {
	scanf(" %lld", &t);
	while (t--) {
		ll a, b, c;
		char ch,n;
		scanf(" %lld %c %lld %c %lld", &a, &ch, &b, &n, &c);
		bool ok = false;
		if (ch == '+') {
			if (a + b == c) ok = true;
		}
		else if (ch == '-') {
			if (a - b == c) ok = true;
		}
		else if (ch == '*') {
			if (a*b == c) ok = true;
		}
		else {
			if (a / b == c) ok = true;
		}
		if (ok) puts("correct");
		else puts("wrong answer");
	}
}