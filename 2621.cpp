#include <iostream>
#include <algorithm>
using namespace std;
int col[4];
int num[10];
int fs,ss,fp,sp,ccnt,ans;
int main() {
	for (int i = 0; i < 5; i++) {
		char a;  int b; scanf(" %c %d", &a, &b);
		if (a == 'R') col[0]++;
		if (a == 'B') col[1]++;
		if (a == 'G') col[2]++;
		if (a == 'Y') col[3]++;
		num[b]++;
	}

	for (int i = 1; i < 10; i++) {
		if (fs <= num[i]) {
			fs = num[i];
			fp = i;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (i == fp) continue;
		if (ss <= num[i]) {
			ss = num[i];
			sp = i;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (ccnt == 5) break;
		if (num[i] == 1) ccnt++;
		else ccnt = 0;
	}

	if (col[0] == 5 || col[1] == 5 || col[2] == 5 || col[3] == 5) {
		if (ccnt == 5) ans = fp + 900;
		else ans = fp + 600;
	}
	if (fs == 4) ans = max(ans, fp + 800);
	if (fs == 3 && ss == 2) ans = max(ans,fp * 10 + sp + 700);
	if (ccnt == 5) ans = max(ans,fp + 500);
	if (fs == 3) ans = max(ans,fp + 400);
	if (fs == 2 && ss == 2) ans = max(ans,max(fp, sp) * 10 + min(fp, sp) + 300);
	if (fs == 2) ans = max(ans,fp + 200);
	if(fs==1) ans = max(ans,fp + 100);
	printf("%d\n", ans);
}