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
#define LL long long
#define MAX 1001
using namespace std;

LL tree[MAX]; // 线段树
LL lz[MAX]; // 延迟标记
void init()
{
	memset(tree, 0, sizeof(tree));
	memset(lz, 0, sizeof(lz));
}
// 创建线段树
void build(LL node, LL l, LL r)
{
	if (l == r)
	{
		cin >> tree[node];
		return;
	}
	LL mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
// 单点更新，n为更新值，index为更新点，lr为更新范围
void update(LL n, LL index, LL l, LL r, LL node)
{
	if (l == r)
	{
		tree[node] = n; // 更新方式，可以自由改动
		return;
	}
	LL mid = (l + r) / 2;
	// push_down(node,mid-l+1,r-mid); 若既有点更新又有区间更新，需要这句话
	if (index <= mid)
	{
		update(n, index, l, mid, node * 2);
	}
	else
	{
		update(n, index, mid + 1, r, node * 2 + 1);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void push_down(LL node, LL l, LL r)
{
	if (lz[node])
	{
		LL mid = (l + r) / 2;
		lz[node * 2] += lz[node];
		lz[node * 2 + 1] += lz[node];
		tree[node * 2] +=  (mid - l + 1) * lz[node];
		tree[node * 2 + 1] +=  (r - mid) * lz[node];
		lz[node] = 0;
	}
}
// 区间更新，lr为更新范围，LR为线段树范围，add为更新值
void update_range(LL node, LL l, LL r, LL L, LL R, LL add)
{
	if (l <= L && r >= R)
	{
		lz[node] +=  add;
		tree[node] +=  (R - L + 1) * add; // 更新方式
		return;
	}
	push_down(node, L, R);
	LL mid = (L + R) / 2;
	if (mid >= l)
	{
		update_range(node * 2, l, r, L, mid, add);
	}
	if (mid < r)
	{
		update_range(node * 2 + 1, l, r, mid + 1, R, add);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
// 区间查找
LL query_range(LL node, LL L, LL R, LL l, LL r)
{
	if (l <= L && r >= R)
	{
		return tree[node];
	}
	push_down(node, L, R);
	LL mid = (L + R) / 2;
	LL sum = 0;
	if (mid >= l)
	{
		sum += query_range(node * 2, L, mid, l, r);
	}
	if (mid < r)
	{
		sum += query_range(node * 2 + 1, mid + 1, R, l, r);
	}
	return sum;
}
int main()
{
	init();
	LL n;
	cin >> n;
	build(1, 1, n);
	return 0;
}
