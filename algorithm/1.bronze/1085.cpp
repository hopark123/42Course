#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int	x, y, w, h;
	int res;

	cin >> x >> y >> w >> h;
	res = min(x, w - x);
	res = min(res, y);
	res = min(res, h - y);
	cout << res;

}