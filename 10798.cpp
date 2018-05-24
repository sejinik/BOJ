#include <iostream>
using namespace std;

char arr[20][20];

int main() {

	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if(arr[j][i] != NULL)
			printf("%c", arr[j][i]);
		}
	}
	
	return 0;
}