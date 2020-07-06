#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

int n;
int h[N];

bool check(int e)
{
	for(int i = 1 ; i <= n ; i++)
	{
		e += e - h[i];
		if(e >= 1e5) return true;  //防止能量越界 
		if(e < 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)  scanf("%d", &h[i]);
	
	int l = 0 , r = 1e5;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1; 
	}
	
	printf("%d\n", r);
	return 0;
}
