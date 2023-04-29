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
#define ll long long
#define N 10000
#include <queue>
#include <stack>
#include <map>
#define MAXN 5050
#define INF 0x3f3f3f3f
using namespace std;

int n, m, s, t;//graph的参数
int u, v, c, w;//加边的参数

int maxFlow, minCost;//最大流量，最小费用

struct Edge
{
	int from, to, flow, cap, cost;
};

bool vis[MAXN];
int p[MAXN], a[MAXN], d[MAXN];

vector<int> g[MAXN];
vector<Edge> edges;

void init(int n)//capacity
{
	for (int i = 0; i <= n; i++)
	{
		g[i].clear();
	}
	edges.clear();
}
void addedge(int from, int to, int cap, int cost)
{
	Edge temp1 = { from, to, 0, cap, cost };
	Edge temp2 = { to, from, 0, 0, -cost };//允许反向增广
	edges.push_back(temp1);
	edges.push_back(temp2);

	int len = edges.size();
	g[from].push_back(len - 2);
	g[to].push_back(len - 1);
}

//贝尔曼-福特算法实现
bool bellmanford(int s, int t)
{
	for (int i = 0; i < MAXN; i++)
	{
		d[i] = INF;
	}

	d[s] = 0;//从s到s的距离为0，后面通过不断松弛来更新s到每个点的距离

	memset(vis, false, sizeof(vis));
	memset(p, -1, sizeof(p));

	p[s] = -1, a[s] = INF;//
	queue<int> Q;
	Q.push(s);
	vis[s] = true;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = false;//下一次找路还用
		for (int i = 0; i < g[u].size(); i++)//这里用的是bfs，从u开始每次访问与u相连的一条边
		{
			Edge& e = edges[g[u][i]];//e是从u到i的一条可行边
			if (e.cap > e.flow && d[e.to] > d[u] + e.cost) //进行松弛，寻找最短路径也就是最小费用
			{
				d[e.to] = d[u] + e.cost;
				p[e.to] = g[u][i];
				a[e.to] = min(a[u], e.cap - e.flow);
				if (!vis[e.to])
				{
					Q.push(e.to);
					vis[e.to] = true;
				}
			}
		}
	}
	if (d[t] == INF)
	{
		return false;//已经没有路可以到汇点了
	}

	maxFlow += a[t];
	minCost += d[t] * a[t];//计算出费用和流量的增加量

	for (int i = t; i != s; i = edges[p[i]].from)
	{
		edges[p[i]].flow += a[t];//正向边流量
		edges[p[i] ^ 1].flow -= a[t];//反向边减流量
	}
	return true;
}
void MCMF()
{
	while (bellmanford(s, t))
	{
		continue;
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	int data[MAXN], sum = 0;
	memset(data, 0, sizeof(data));
	for (int i = 1; i <= n; i++)
	{
		cin >> data[i];
		sum += data[i];
	}
	sum /= n;
	vector<int>a;
	vector<int>b;
	int ms = 0;
	for (int i = 1; i <= n; i++)
	{
		if (data[i] < sum)
		{
			a.push_back(i);
			//ms++;
		}
		if (data[i] >= sum)
		{
			b.push_back(i);
			//ms++;
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		addedge(a[i], n + 1, sum - data[a[i]], 0);
		ms++;
	}
	for (int i = 0; i < b.size(); i++)
	{
		addedge(0, b[i], data[b[i]] - sum, 0);
		ms++;
	}
	for (int i = 1; i < n; i++)
	{
		addedge(i, i + 1, INF, 1);
		addedge(i + 1, i, INF, 1);
		ms += 2;
	}
	addedge(1, n, INF, 1);
	addedge(n, 1, INF, 1);
	ms += 2;
	n = n + 1, m = ms, s = 0, t = n + 1;
	MCMF();
	cout << minCost << endl;
	return 0;
}
//int main()
//{
//	cout << "节点数为：  ";cin >> n;
//	cout << "边数为：    ";cin >> m;
//	cout << "源点编号为：";cin >> s;
//	cout << "汇点编号为：";cin >> t;
//
//	cout << "输入 " << m << " 条边的信息：" << endl;
//	while (m--)
//	{
//		cout << "起点：";cin >> u;
//		cout << "终点：";cin >> v;
//		cout << "容量：";cin >> c;
//		cout << "费用：";cin >> w;
//		cout << "-----------------" << endl;
//		addedge(u, v, c, w);
//	}
//
//	MCMF();
//	cout << "最大流为：" << maxFlow << endl;
//	cout << "最小费用为" << minCost << endl;
//	cout << endl;
//
//	return 0;
//
//}

