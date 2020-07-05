#include <iostream>

using namespace std;

const int N = 10;

int target;
int num[N];    //保留全排列的结果 
bool used[N];  //标记全排列是否使用过 
int cnt;       // 计数 输出的结果 

// 计算数组中一段的数是多少 
int calc(int l , int r)
{
	int res = 0 ;
	for(int i = l ; i <= r ; i++)
	    res = res * 10 + num[i];
	return res; 
}
 
void dfs(int u)
{
	if(u == 9)
	{
		for(int i = 0 ; i < 7 ; i++)
		{
			for(int j = i + 1 ; j < 8 ;j++)
			{
				int a = calc(0 , i);
				int b = calc(i + 1 , j);
				int c = calc(j + 1 , 8);
				if(a * c + b == c * target) cnt++;
			}
	    }
		return;
	}
	
    // 全排列
	for(int i = 1; i <= 9; i++)
	{ 
        if(!used[i]){
            used[i] = true; //标记使用
            num[u] = i;
            dfs(u + 1);
            used[i] = false; //还原现场
        }
    } 
} 

int main()
{
	scanf("%d", &target);
	
	dfs(0);
	
	printf("%d\n", cnt);
	return 0;
}
