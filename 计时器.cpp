#include<iostream>
using namespace std;
int main(){
	int c,n;
	//cout<<"�����뱳��������c:";
	cin>>c;
	cout<<endl;
	//cout<<"��������Ʒ�ļ���n:";
	cin>>n;
	cout<<endl;
	int *w=new int [n];
	int *v=new int [n];
	float *p=new float[n];
	bool *s=new bool[n];
	//cout<<"������ÿ����Ʒ������w[i]:";
	for(int i=0;i<n;i++)
		cin>>w[i];
	cout<<endl;
	//cout<<"������ÿ����Ʒ�ļ�ֵv[i]:";
	for(int i=0;i<n;i++){
		cin>>v[i];
		p[i]=v[i]*1.0/w[i];
		s[i]=true; //ûװ
	}
	cout<<endl;
	float temp_p=0;
	int temp_i=0;
	float value=0;
	while(c>0){
		temp_p=0;
		for(int i=0;i<n;i++)
			if(s[i]&&p[i]>temp_p)//�ҵ�δװ�������еĵ�λ������ֵ���ֵ
			{
				temp_p=p[i];
				temp_i=i;
			}
		s[temp_i]=false; //�Ѿ�װ��
		if(c>=w[temp_i]){
			c-=w[temp_i];
			value+=v[temp_i];
		}
		else
		{
			value+=c*p[temp_i];
			w[temp_i]=c;
			c=0;
		}
	}
	//for(int i=0;i<n;i++)
	//	if(!s[i])
	//		cout<<v[i]<<w[i]<<endl;
		cout<<value<<endl;
}
