#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
	int *a1 = (int *)a;
	int *b1 = (int *)b;
	return *b1 - *a1;
}
int main()
{
	int n,m,i,j,k,t;
	while(scanf("%d",&n)!=EOF){
		int x[205]={0},y[205]={0},bin[1005]={0};
		j = k = 0;
		for(i=1;i<=2*n;i++){
			scanf("%d",&t);
			if(bin[t]==0){
				x[j++] = t;
				bin[t]++;
			}
			else{
				y[k++] = t;
			}
		}
		qsort(x,j,sizeof(x[0]),cmp);
		qsort(y,k,sizeof(y[0]),cmp);
		scanf("%d",&m);
		if(m==1){
			for(i=0;i<j;i++) printf("%d ",x[i]);
			printf("\n");
		}
		else{
			for(i=0;i<k;i++) printf("%d ",y[i]);
			printf("\n");
		}
	}
	return 0;
}
