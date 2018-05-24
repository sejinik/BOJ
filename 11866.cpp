#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	queue<int> q;

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			q.push(q.front());
			q.pop();
		}

		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">" << endl;

	return 0;
}