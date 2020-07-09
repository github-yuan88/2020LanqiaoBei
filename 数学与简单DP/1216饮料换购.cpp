#include <iostream>

using namespace std;

int main()
{
	int n ;
	cin >> n;
	
	int res = n;
	while(n >= 3)
	{
		res += n/3;
		n = n / 3 + n % 3; 
	}
	
	cout << res << endl; 
	return 0;
} 
