#include <iostream>
#include <cstring>
using namespace std;
int n;
int mapp[26][26];//记录相邻
char str[26];//记录每行输入
int color[26];//记录每个结点对应的颜色编号。
void dfs(int d)
{
	if (d == n)
		return;
	int cont = 1; //终止涂色的变量
	int i, j;
	for (i = 1; cont; i++)   //在顶点d处，从颜色1开始涂起,颜色编号以i表示
	{
		int flag = 1;
		for (j = 0; j < n; j++)
		{
			if (mapp[d][j] == 1 && color[j] == i)   //若有相邻结点涂了一样的颜色i,则跳出本次循环，为d涂另一种颜色，颜色编号+1
			{
				flag = 0;
				break;
			}
		}
		if (flag)   //说明没有相邻结点涂相同颜色
		{
			color[d] = i;
			dfs(d + 1);
			cont = 0; //d处终止涂色
		}
	}
}
int main()
{
	while (cin >> n && n >= 1)
	{
		//每次新开始时要清空原来数据
		memset(mapp, 0, sizeof(mapp));
		memset(color, 0, sizeof(color));
		//输入n行数据
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int a = str[0] - 'A';
			//将相邻信息统计在map中
			for (int j = 2; j < strlen(str); j++)
			{
				int b = str[j] - 'A';
				mapp[a][b] = mapp[b][a] = 1;
			}
		}
		color[0] = 1;
		int res = 0; //结果
		//从第一个点开始深搜
		dfs(0);
		for (int i = 0; i < n; i++)res = max(res, color[i]);
		if (res > 1)cout << res << " channels needed." << endl;
		else cout << res << " channel needed." << endl;
	}
	return 0;
}



















