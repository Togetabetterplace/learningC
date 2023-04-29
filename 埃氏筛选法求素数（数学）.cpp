#include <bits/stdc++.h>
using namespace std;
//埃氏筛选法求素数
#define NUM 12997
int main()
{
	int prime[NUM+1];
	int count=0;
	memset(prime,1,sizeof(prime));
	for(int i=2;i*i<=NUM;i++){
		if(prime[i]){
			for(int j=i+i;j<=NUM;j+=i){
				prime[j]=0;
			}
		}
	}
	for(int i=2;i<=NUM;i++){
		if(prime[i]){
			count++;
			printf("%d\n",i);
		}
	}
	printf("%d\n",count);
	return 0;
}
