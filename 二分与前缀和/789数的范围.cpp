#include <iostream>

using namespace std;
const int N = 1e5 + 5;
int a[N];
int n , m , p;

int main()
{
	scanf("%d %d", &n , &m);
	for(int i = 1 ; i <= n ; i++) scanf("%d" , &a[i]);
	
	while(m--)
	{
		int num;
		scanf("%d" , &num);
		
		int l = 1 , r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(a[mid] < num ) l = mid + 1;
			else r = mid ;
		}
		if(a[l] != num)  cout << "-1 -1" << endl;
		else
		{
			cout << l - 1<< " ";
			
			int l = 1 , r = n;
			while(l < r)
			{
				int mid = l + r + 1 >> 1;
				if(a[mid] > num) r = mid - 1;
				else l = mid ;
			}
			cout << l - 1<< endl;
		}
	} 
	return 0;
}
