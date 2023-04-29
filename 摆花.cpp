#include<cstdio>  
int n,m,a[105],f[105][105];  
void dp()  
{  
	f[0][0]=1;  
	for(int i=1;i<=n;i++)  
		for(int j=m;j>=0;j--)  
			for(int k=1;k<=a[i]&&k<=j;k++)  
				f[i][j]+=f[i][j]+f[i-1][j-k];  
}  
int main()  
{  
	scanf("%d%d",&n,&m);  
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);  
	dp();  
	printf("%d",f[n][m]);  
} 
