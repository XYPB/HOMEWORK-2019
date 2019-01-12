#include<iostream>
using namespace std;

int main()
{
	int a = -1, b = -1, c = -1;
	bool ans = (a = 0) && (b = 2) || (c = 3);
	cout << ans << endl;
	cout << a << b << c << endl;
	return 0;
}