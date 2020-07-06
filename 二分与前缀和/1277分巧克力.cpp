#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e5 + 5;

int n , k;
int h[N], w[N];

bool checkd(int x)
{
	int res = 0;
	for(int i = 0 ; i < n ; i++)
	{
		res += (h[i] / x) * (w[i] / x);
		if(res >= k ) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n , &k);
	
	for(int i = 0 ; i < n ; i ++) scanf("%d%d", &h[i] , &w[i]);
	
	int l = 1 , r = 1e5;
	while(l < r)
	{
		int mid = l + r + 1 >> 1;
		if(checkd(mid)) l = mid;
		else r = mid - 1;
	}
	
	printf("%d\n", r);
}
