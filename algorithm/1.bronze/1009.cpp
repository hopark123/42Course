#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int		a,b,T;
	int		res;
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		res = 1;
		cin >> a;
		cin >> b;
		while (b--)
			res = res * a % 10;
		if (res == 0)
			res = 10;
		cout << res << endl;
	}
}