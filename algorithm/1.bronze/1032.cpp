#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int	T;
	std::string str1, str2;

	cin >> T >> str1;
	while (T-- > 1)
	{
		cin >> str2;
		for (size_t i = 0; i < str1.length(); i++)
		{
			if (str1[i] != str2[i])
				str1[i] = '?';
		}
	}
	cout << str1;
}