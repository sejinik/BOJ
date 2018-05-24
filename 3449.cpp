#include <iostream>
#include <string>
using namespace std;

int main()
{
	int Tcase,num=0;
	string str1, str2;

	cin >> Tcase;

	while (Tcase--)
	{
		cin >> str1 >> str2;
		num = 0;
		for (int i = 0; i < str1.length(); i++)
			if (str1[i] != str2[i])
				num++;
		
		cout << "Hamming distance is " << num <<"."<< endl;
	}
}