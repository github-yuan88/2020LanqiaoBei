#include <iostream>
#include <cmath>

using namespace std;

int n;
int main()
{
	scanf("%d" , &n);
	
	int first , left = 0 , right = 0;
	scanf("%d" , &first);
	
	for(int i = 0 ; i < n - 1 ; i++)
	{
		int x;
		scanf("%d" , &x);
		
		if(abs(x) < abs(first) && x > 0) right++;
		
		if(abs(x) > abs(first) && x < 0) left++;
		 
	}
	
	if((first < 0 && right == 0) || first> 0 && left == 0) puts("1");
	else printf("%d\n", left + right + 1);
	
	return 0;
} 
