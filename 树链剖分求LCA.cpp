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
#define IOS ios::sync_with_stdio(false)
#define maxn 500005
#define mod 99999997
#define inf 1000000007

struct edge {
	int v, nx;
} E[maxn * 2];
int head[maxn], num;

void add_edge(int from, int to) {
	E[++num].nx = head[from];
	E[num].v = to;
	head[from] = num;
}

int Tvec_num[maxn];
int dep[maxn];
int son[maxn];
int top[maxn];
int f[maxn];
void dfs1(int fa, int u) {
	Tvec_num[u] = 1;
	for (int i = head[u]; i; i = E[i].nx) {//dfs
		int v = E[i].v;//找v
		if (fa != v) {//方向
			dep[v]=dep[u]+1;//深度++
			f[v]=u;//父亲数组赋值
			dfs1(u, v);//向下dfs
			Tvec_num[u] += Tvec_num[v];//吧size加回父亲的size
			if (Tvec_num[v] > Tvec_num[son[u]]) son[u]=v;//更新重孩子
		}
	}
}
int id[maxn];
int cnt=1;
int a[maxn];
int w[maxn];
void dfs2(int u, int t) {
	id[u]=++cnt;
	a[cnt]=w[u];
	top[u] = t;//更新top数组
	if (son[u])//有重孩子dfs
		dfs2(son[u], t);//新的链
	for (int i = head[u]; i; i = E[i].nx) {//向下面孩子节点搜索
		int v = E[i].v;
		if (f[u] != v && v != son[u])
			dfs2(v, v);//新的链
	}
}
//		if (x == f[top[x]]) //特判，为整棵树的根结点，可直接返回，while的if下面
//			return x;
int Query(int x, int y) {
	while (top[x] != top[y]) {//没找到LCA则继续循环
		if (dep[f[top[x]]] < dep[f[top[y]]])//将深度浅的节点swap到x的位置
			swap(x, y);
		x = f[top[x]];
	}
	if (dep[x] < dep[y])//深度浅的就是LCA(即LCA在上面)
		return x;
	else
		return y;
}

void init() {
	memset(head, -1, sizeof(head));
	num = 0;
}

int main() {
	//IOS;
	init();
	int n, m, s;
	cin >> n >> m >> s;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		add_edge(x, y);
		add_edge(y, x);
	}
	dfs1(s, s);
	dfs2(s, s);cerr<<"begin find LCAs: "<<endl;
	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << Query(u, v) << "\n";
	}
	return 0;
}

/*
6 100
1 11
1 8
1 2
2 7
2 4
2 3
4 6
4 5
5 15
6 16
8 9
9 10
11 13
11 12
13 14
 */

/*
  int n = 0;
  while(scanf("%d",&n)!=EOF){}
 */
