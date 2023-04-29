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
        s[i++] = n % 10 + '0';//s是char型，int型转char如果自动转型的话会
        //转化成ARSC码，取0的码值加上对应的，就成功转了对应的数字

    }while((n /= 10) > 0);//进行了n=n/10的运算，又因为n是整形，所以会向下取整
    //若3位，则会进行三次运算，如此成功转为了char数组型
    if (sign < 0)s[i] = '-';
    s[i] = '\0';
    /*char final[2000];
    for(int j = 0;j < i;j++) {
        final[j] = s[i - j];
    }//之前是从后往前存的，用reverse转回来*/
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
