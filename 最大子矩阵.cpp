#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int colbegin1,colend1,colbegin,colend,rowbegin,rowend;
//两个列起始末尾，一个行起始末尾
//对求最大子段和的方法稍作改进，记录下最大字段的起始位置和终止位置
int Max(int a[],int n){
    int max=0,temp=a[1],begin=1,end=1;
    for(int i=2;i<=n;i++){
        if(temp>0){
            temp+=a[i];
            end=i;//刷新终止位置
        }
        else{
            temp=a[i];//不再加入新数据了
            begin=end=i;//重置起始位置和终止位置，继续执行
        }
        if(temp>max){//记录下最后的结果，也就是最大值，列序号
            max=temp;//最大字段和
            colbegin1=begin;//矩阵列开始位置
            colend1=end;//矩阵列结束位置
        }
    }
    return max;
}
int main(){
    int n,m,num[MAX][MAX],t[MAX];//t是单独的一行
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>num[i][j];//输入数据
    int sum=0,max=0;
    for(int begin=1;begin<=n;begin++){
        for(int k=1;k<=m;k++)
            t[k]=0;//t[k]重置为0
        for(int end=begin;end<=n;end++){
            for(int k=1;k<=m;k++)
                t[k]+=num[end][k];//从开始行到结束行进行压缩，压缩成一行
            sum=Max(t,m);//求出这一行数据的最大子段和
            if(sum>max){//刷新要求的结果
                max=sum;
                rowbegin=begin;
                rowend=end;
                colbegin=colbegin1;
                colend=colend1;
            }
        }
    }
	cout<<max<<endl;
    cout<<rowbegin<<rowend<<colbegin<<colend<<endl;
    return 0;
}
