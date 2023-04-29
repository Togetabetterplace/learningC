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
int v[100000];
int w[100000];
int dp[100000];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n, W;
	cin >> n >> W;//物品数量及背包容量
	for (int i = 0; i < n; i++)  //输入每个物品的重量和价值
	{
		cin >> w[i] >> v[i];
	}
	for (int i = 0; i < n; i++)  //从前向后遍历所有物品
	{
		for (int j = W; w[i] <= j; j--)  //将j作为判断能不能装的标准，w[i]<j表示能装，否则不能装
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);//找到最大值
		}
	}
	cout << dp[n] << endl;
	return 0;
}
/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
