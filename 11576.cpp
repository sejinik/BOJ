#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

stack<int> st;

int main() {
	int A, B,cnt;
	scanf("%d %d", &A, &B);
	scanf("%d", &cnt);



	int ans = 0;
	while (cnt--) {
		int num;
		scanf("%d", &num);
		ans += num*pow(A,cnt);
	}

	while (ans != 0) {
		int temp = ans%B;
		st.push(temp);
		ans /= B;

	}
	int size = st.size();
	for (int i = 0; i < size; i++) {
		printf("%d ", st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}