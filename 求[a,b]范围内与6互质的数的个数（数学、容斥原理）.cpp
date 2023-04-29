#include <bits/stdc++.h>
int main(){
	long k, a, b, sum;
	scanf("%ld",&k);
    for(int i=1; i<=k; i++){
    	scanf("%ld%ld",&a,&b);
    	sum=(b-b/2-b/3+b/6)-((a-1)-(a-1)/2-(a-1)/3+(a-1)/6);
    	printf("%ld\n",sum);
	}
	return 0;
}
