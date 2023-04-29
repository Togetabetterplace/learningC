#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, cnt;
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;
        while(n>=5)
        {
            cnt+=n/5;
            n/=5;
        }
		printf("%d\n",cnt);
	} 
	return 0;
}
