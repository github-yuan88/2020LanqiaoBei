#include <iostream>

using namespace std;

const int N = 16;

int n;
int st[N];  //1��ʾѡȡ  �� 2 ��ʾ��ѡȡ 

void dfs(int u)
{
	if(u > n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if(st[i] == 2)
			    printf("%d " , i);
		}
		printf("\n");
		return;
	}
	
	st[u] = 2;
	dfs(u + 1);
	st[u] = 0;
	
	st[u] = 1;
	dfs(u + 1);
	st[u] = 0; 
}

int main()
{
	cin >> n;
	dfs(1);
	
	return 0;
} 
