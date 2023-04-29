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
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n = 0;
	int dp[10000] = {1};
	int a[10000];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) //i从前往后遍历
		{
			for (int j = 0; j < i; j++) //不断寻找比i小且可以加入上升子序列内的元素
			{
				if (a[i] > a[j])dp[i] = max(dp[j] + 1, dp[i]); //当a[j]小于a[i]时才可以加入，dp[i]++;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (dp[i] > res)res = dp[i]; //找到最大值
		}
		cout << res << endl;
	}

	return 0;
}
/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
