#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
#define ll long long
#define N 10000
int prime(int p)
{
	if(p==1)return 0;
	if (p == 2 || p == 3)
	{
		return 1;
	}
	if (p % 6 != 1 && p % 6 != 5)
	{
		return 0;
	}
	for (int i = 5; i <= floor(sqrt(p)); i += 6)
	{
		if (p % i == 0 || p % (i + 2) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	char s[10000];
	while (scanf("%s", &s) != EOF)
	{
		int m = 0, da[4][1000] = {0};
		scanf("%d", &m);
		int len = strlen(s), sum, flag1, flag2, k1 = 0, k2 = 0, k3 = 0, k4 = 0;
		for (int i = 0; i < len; )
		{
			sum = 0, flag1 = 0, flag2 = 0;
			for (int j = 0; j + i < len; j++)
			{
				if (j == m)break;
				if (sum == 0)
				{
					sum += s[j + i] - '0';
					if (prime(s[j + i] - '0'))flag1 = 1;
					flag2 += s[j + i] - '0';
				}
				else
				{
					sum = sum * 10 + s[j + i] - '0';
					if (prime(s[j + i] - '0'))flag1 = 1;
					flag2 += s[j + i]   - '0';
				}
			}
			i += m;
			if (prime(sum))
			{
				da[0][k1++] = sum;
				continue;
			}
			if (prime(flag2))
			{
				da[1][k2++] = sum;
				continue;
			}
			if (flag1)
			{
				da[2][k3++] = sum;
				continue;
			}
			da[3][k4++] = sum;
		}
		printf("%d %d %d %d", k1, k2, k3, k4);
	}
	return 0;
}
/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
