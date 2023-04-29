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
/**/
//........................................................................

//并查集//高级数据结构
#define MAXN 100000
int Parent[MAXN];
int Rank[MAXN];
int find_UF_set(int x) {//查找x的根节点
	if (Parent[x] == x)return x;//x就是代表元素(根节点)
	else return find_UF_set(Parent[x]);//x不是根节点，向上递归
}
int find(int x){
	if(Parent[x]==x)return x;
	else {
		int s=Parent[x];
		while(s!=Parent[s])s=Parent[s];
		Parent[x]=s;
		return s;
	}
}
void init_UF_sets(int n) {//初始化
	for (int i = 0; i < n; i++) {
		Parent[i] = i;//初始化并查集
		Rank[i] = 1;//秩数组
	}
}
void merge(int x, int y) {//并查集按秩合并
	int rx = find_UF_set(x);//找到x的根节点
	int ry = find_UF_set(y);//找到y的根节点
	if (rx != ry) { //如果不是同一个集合
		if (Rank[rx] < Rank[ry]) { //rank大的集合合并rank小的集合
			swap(rx, ry);//这里进行交换是为了保证rx的rank大于ry的rank，方便下面合并
		}
		Parent[ry] = rx;//rx 合并 ry
		if (Rank[rx] == Rank[ry])//如果两个并查集的Rank相同
			Rank[rx] += 1;//Rank增加
	}
}
void road_mark(int x) {
	if (Parent[x] != x) { //如果祖先不是本身的话，将自身与祖先相连
		Parent[x] = find_UF_set(x);
	}
}
int main() {//UF_set
	cout << "请初始化" << endl;
	int n = 0;
	cin >> n;//确定初始化的并查集元素数
	init_UF_sets(n);
	char ch;//初始化并查集和命令字符
	cout << "1,查询 2,按秩合并" << endl;
	do {
		cin >> ch;
		if (ch == '1') {//查询操作
			int key = 0;
			cin >> key;//输入要查询的值
			int ans = find(key);//返回结果
			printf("%d", ans);
		}
		if (ch == '2') {//合并操作
			int x, y;//要合并的两个元素
			cin >> x >> y;//输入元素
			merge(x, y);//合并
		}
		if (ch == '#')break;
	} while (ch != '#');
	return 0;
}
//亲戚问题
int Ra[MAXN];
int Rfind_UF_set(int x) {//查找x的根节点
	if (Ra[x] == x)return x;//x就是代表元素(根节点)
	else return find_UF_set(Ra[x]);//x不是根节点，向上递归
}
void Rinit_UF_sets(int n) {//初始化
	for (int i = 0; i < n; i++) {
		Ra[i] = i;//初始化并查集
	}
}
void Rmerge(int x, int y) {//并查集按秩合并
	int rx = find_UF_set(x);//找到x的根节点
	int ry = find_UF_set(y);//找到y的根节点
	Ra[ry] = rx;//rx 合并 ry
}
int Find_Ralitives_() {//main
	int n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	init_UF_sets(n); //初始化并查集和命令字符
	for (int i = 0; i < m; i++) {
		int r1 = 0, r2 = 0;
		cin >> r1 >> r2;
		Rmerge(r1, r2);
	}
	for (int i = 0; i < p; i++) {
		int r1 = 0, r2 = 0;
		cin >> r1 >> r2;
		int m = Rfind_UF_set(r1);
		int n = Rfind_UF_set(r2);
		if (m == n)cout << "no" << endl;
		else cout << "yes" << endl;
	}
	system("pause");
	return 0;
}
