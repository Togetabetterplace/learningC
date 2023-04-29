#include <bits/stdc++.h>
using namespace std;
int num[10005];
int flag[10005];
int n;
bool Input()
{
    cin>>n;
    if(!n) return false;
    for(int i=0; i<n; i++)
	    cin>>num[i];  
    return true;
}
    
void Solve()
{
    flag[0]=num[0];
    int max=flag[0];
    int end=0, begin, sum=0;
    //ºËĞÄ´úÂë 
	for(int i=1; i<n; i++)
    {
        if(flag[i-1]>=0)
            flag[i]=flag[i-1]+num[i];
        else 
            flag[i]=num[i];
        if(flag[i]>max)
        {
            max=flag[i];
            end=i;   
        }       
    }   
    
	if(max<0)
    {
        cout<<0<<" "<<num[0]<<" "<<num[n-1]<<endl;
        return ;
    }
    else 
    {
        for(int j=end; j>=0; j--)
            if((sum+=num[j])==max)
               begin=j;
               cout<<max<<" "<<num[begin]<<" "<<num[end]<<endl;
    }
}
    
int main()
{
    while(Input())
        Solve();
    return 0;
}
