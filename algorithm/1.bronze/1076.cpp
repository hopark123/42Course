#include <iostream>

using namespace std;

enum resistance { black = 0, brown, red, orange, yellow, green, blue, violet, grey, white };
static const char	*resistance_str[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int	getStringToEnum(string	str)
{
	for (int i = 0; i < 10; i ++)
		if (!str.compare(resistance_str[i]))
			return (i);
	return (0);
}


int main ()
{
	ios::sync_with_stdio(false);
	string	str1, str2, str3;
	long long	res;
	cin >> str1 >> str2 >> str3;
	res = getStringToEnum(str1) * 10 + getStringToEnum(str2);
	for (int i = 0; i < getStringToEnum(str3); i++)
		res *= 10;
	cout << res << endl; 
	// cout << str1 << " : " << getStringToEnum(str1);
	// cout << str1 << " " << str2 << " " << str3 << endl;
}