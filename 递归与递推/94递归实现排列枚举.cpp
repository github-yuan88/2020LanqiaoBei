#include <iostream>

using namespace std;

const int N = 10;
int state[N];
bool vis[N];
int n;
void dfs(int u)
{
	if(u > n)
	{
		for(int i = 1 ; i <= n ; i++) printf("%d ", state[i]);
		puts("");
		return ;
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		if(!vis[i])
		{
		    state[u] = i;
			vis[i] = true;
			dfs(u + 1);
			
			state[u] = 0;
			vis[i] = false;	
		}
	}
}

int main()
{
	scanf("%d" , &n);
	
	dfs(1);
	return 0;
}
