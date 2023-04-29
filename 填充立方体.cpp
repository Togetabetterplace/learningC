//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<string>
//using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
#define ll long long
#define N 10000
char a[1000];
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}//注意，留着这个很好的求最大公约数函数（开卷考试）
int main()
{
	while (gets(a))
	{
		char b[1000];
		int i, j, len, k = 0;
		i = 0;
		len = j = strlen(a) - 1;
		for (; j >= 0; i++, j--)
		{
			b[i] = a[j];
			if (a[j] == ' ')
			{
				k++;
				for (int w = 0; w < i; w++)
				{
					//if(b[i-w-1]==' ')continue;
					printf("%c", b[i - w - 1]);
				}
				memset(b, 0, sizeof(b));
				printf(" ");
				i = 0;
			}
		}
		printf("\n");
		k += 1;
		//printf("%s\n", b);
		int n = gcd(len + 1, k);
		if (n == 1)
		{
			printf("*\n");
			continue;
		}
		int A, B, C;
		B = 1, A = C = 0;
		for (int i = 0; i < n - 1; i++)
		{
			printf(" ");
		}
		for (int i = 0; i < n; i++)
			printf("*");
		printf("\n");
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = 0; j < n - i - 2; j++)
			{
				printf(" ");
			}
			printf("*");
			for (int j = 0; j < n - 2; j++)
			{
				printf("%c", A + 'A');
				A++;
				if (A >= 26)
				{
					A %= 26;
				}
			}
			printf("*");
			for (int j = 0; j < i; j++)
			{
				printf("%d", B);
				B++;
				if (B >= 10)
				{
					B %= 10;
					B++;
				}
			}
			printf("*\n");
		}
		for (int i = 0; i < n; i++)
		{
			printf("*");
		}
		for (int i = 0; i < n - 2; i++)
		{
			printf("%d", B);
			B++;
			if (B >= 10)
			{
				B %= 10;
				B++;
			}
		}
		printf("*\n");
		for (int i = 0; i < n - 2; i++)
		{
			printf("*");
			for (int j = 0; j < n - 2; j++)
			{
				printf("%c", C + 'a');
				C++;
				if (C >= 26)
				{
					C %= 26;
				}
			}
			printf("*");
			for (int j = 0; j < n - i - 3; j++)
			{
				printf("%d", B);
				B++;
				if (B >= 10)
				{
					B %= 10;
					B++;
				}
			}
			printf("*\n");
		}
		for (int i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");

	}
	return 0;
}
/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
