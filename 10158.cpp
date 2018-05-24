#include <iostream>
using namespace std;

int main()
{
	int w, h, p, q, t,tp,tq,wp,hq;
	cin >> w >> h >> p >> q >> t;
	tp = t;
	tq = t;


	while (tp != 0)
	{
		p++;
		tp--;
		if (tp == 0)
			break;

		if (p == w)
		{
			wp = w;
			while (wp--)
			{
				p--;
				tp--;

				if (tp == 0)
					break;
			}
		}
	}
		while (tq != 0)
		{
			q++;
			tq--;
			if (tq == 0)
				break;

			if (q == h)
			{
				hq = h;
				while (hq--)
				{
					q--;
					tq--;

					if (tq == 0)
						break;
				}
			}
		}
		cout << p << " " << q << endl;
		return 0;
}