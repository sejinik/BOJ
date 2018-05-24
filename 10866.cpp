#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif // _CONSOLE

	deque<int> de;
	string str;
	int N,X;

	cin >> N;

	while (N--)
	{
		cin >> str;
		
		if (str == "push_front") {
			cin >> X;
			de.push_front(X);
		}
		else if (str == "push_back") {
			cin >> X;
			de.push_back(X);
		}
		else if (str == "pop_front") {
			if (!de.empty()) {
				cout << de.front() << endl;
				de.pop_front();
			}
			else
				cout << "-1" << endl;
		}
		else if (str == "pop_back") {
			if (!de.empty()) {
				cout << de.back() << endl;
				de.pop_back();
			}
			else
				cout << "-1" << endl;
		}
		else if (str == "size") {
			cout << de.size() << endl;
		}
		else if (str == "empty") {
			cout << de.empty() << endl;
		}
		else if (str == "front") {
			if (!de.empty()) {
				cout << de.front() << endl;
			}
			else
				cout << "-1" << endl;
		}
		else {
			if (!de.empty()) {
				cout << de.back() << endl;
			}
			else
				cout << "-1" << endl;
		}
	}
	return 0;

}