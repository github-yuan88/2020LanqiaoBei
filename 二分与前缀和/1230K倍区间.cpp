#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n , k;
LL s[N],cnt[N];

int main()
{
	scanf("%d%d", &n , &k);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}
	
	LL res = 0;
	cnt[0] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		res += cnt[s[i] %k];
//		cout << res << endl << endl; 
		cnt[s[i] % k] ++;
//		cout << cnt[0] << " " << cnt[1] << endl << endl; 
	}
	
//	cout << cnt[0] << " " << cnt[1] << endl;
	printf("%lld\n", res);
	
	return 0; 
} 
