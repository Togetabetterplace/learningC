#include<iostream>
#include <algorithm>
using namespace std;
#include<cstring>
/**/
void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) n  = -n;
    i  = 0;
    do{
        s[i++] = n % 10 + '0';//s��char�ͣ�int��תchar����Զ�ת�͵Ļ���
        //ת����ARSC�룬ȡ0����ֵ���϶�Ӧ�ģ��ͳɹ�ת�˶�Ӧ������

    }while((n /= 10) > 0);//������n=n/10�����㣬����Ϊn�����Σ����Ի�����ȡ��
    //��3λ���������������㣬��˳ɹ�תΪ��char������
    if (sign < 0)s[i] = '-';
    s[i] = '\0';
    /*char final[2000];
    for(int j = 0;j < i;j++) {
        final[j] = s[i - j];
    }//֮ǰ�ǴӺ���ǰ��ģ���reverseת����*/
	reverse(s,s+i);
}
int main()
{
	int m=12343;
	char s[100000];
	itoa(m,s);
	for(int i=0;i<strlen(s);i++)
	{
		cout<<s[i];
	}
}
