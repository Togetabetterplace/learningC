#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int colbegin1,colend1,colbegin,colend,rowbegin,rowend;
//��������ʼĩβ��һ������ʼĩβ
//��������Ӷκ͵ķ��������Ľ�����¼������ֶε���ʼλ�ú���ֹλ��
int Max(int a[],int n){
    int max=0,temp=a[1],begin=1,end=1;
    for(int i=2;i<=n;i++){
        if(temp>0){
            temp+=a[i];
            end=i;//ˢ����ֹλ��
        }
        else{
            temp=a[i];//���ټ�����������
            begin=end=i;//������ʼλ�ú���ֹλ�ã�����ִ��
        }
        if(temp>max){//��¼�����Ľ����Ҳ�������ֵ�������
            max=temp;//����ֶκ�
            colbegin1=begin;//�����п�ʼλ��
            colend1=end;//�����н���λ��
        }
    }
    return max;
}
int main(){
    int n,m,num[MAX][MAX],t[MAX];//t�ǵ�����һ��
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>num[i][j];//��������
    int sum=0,max=0;
    for(int begin=1;begin<=n;begin++){
        for(int k=1;k<=m;k++)
            t[k]=0;//t[k]����Ϊ0
        for(int end=begin;end<=n;end++){
            for(int k=1;k<=m;k++)
                t[k]+=num[end][k];//�ӿ�ʼ�е������н���ѹ����ѹ����һ��
            sum=Max(t,m);//�����һ�����ݵ�����Ӷκ�
            if(sum>max){//ˢ��Ҫ��Ľ��
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
