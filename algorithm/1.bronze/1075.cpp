#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int	N, F, temp;

	cin >> N >> F;
	temp = N / 100 * 100;
	
	while (temp % F != 0)
		temp++;
	cout << temp % 100 / 10 << temp % 10 << endl;
	return (0);
}