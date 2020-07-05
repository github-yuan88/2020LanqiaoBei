#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int , int> PII;

const int N = 5 ;

char g[N][N] , backup[N][N];

int get(int x , int y)
{
	return 4 * x + y; 
}

void turn_one(int x , int y )
{
	if(g[x][y] == '+') g[x][y] = '-';
	else g[x][y] = '+';
} 

void turn_all(int x , int y)
{
	for(int i = 0 ; i < 4 ; i++)
	{
		turn_one(x , i);
		turn_one(i , y);
	}	
	turn_one(x , y);  //翻转本身 
}

int main()
{
	for(int i = 0 ; i < 4 ; i++) cin >> g[i];
	
	vector<PII> res;
	for(int op = 0 ; op < 1 << 16 ; op++)
	{
		vector<PII> temp;  //记录当前的方案 
		memcpy(backup , g , sizeof g);   //备份
		
		//操作
		for(int i = 0 ; i < 4 ; i++)
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				if(op >> get(i , j) & 1)
				{
					temp.push_back({i , j});
					turn_all(i , j);         
				}
			}
		} 
		
		//判断灯泡是否全亮
		bool has_closed = false;
		for(int i = 0 ; i < 4 ; i++)
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				if(g[i][j] == '+')
				    has_closed = true;
			} 
		}
		
		if(has_closed == false)
		{
			if(res.empty() || res.size() > temp.size()) res = temp;   //求得最小的方案 
		}
		
		memcpy(g , backup , sizeof g);  //还原 	 
	}
	
	cout  << res.size() << endl;  //最小切换把手的次数 
	for(vector< PII >::iterator op = res.begin() ; op != res.end() ; op++)  
	    cout << op -> first + 1 << ' ' << op -> second + 1 << endl;
	return 0;
}
  
