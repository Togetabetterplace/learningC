#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<memory>
#include<queue>
#define MVNUM 1000
#define N1 2000
#define N2 10000
#define Datasize 100
#define N 10000
#define ll long long
using namespace std;
constexpr auto N0 = 500;
/**/
//........................................................................

//并查集//高级数据结构
#define MAXN 100
int Parent[MAXN];
int Rank[MAXN];
int find_UF_set(int x) {//查找x的根节点
	if (Parent[x] == x)return x;//x就是代表元素(根节点)
	else return find_UF_set(Parent[x]);//x不是根节点，向上递归
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
	if (rx != ry){//如果不是同一个集合
		if (Rank[rx] < Rank[ry]){//rank大的集合合并rank小的集合
			swap(rx, ry);//这里进行交换是为了保证rx的rank大于ry的rank，方便下面合并
		}
		Parent[ry] = rx;//rx 合并 ry
		if (Rank[rx] == Rank[ry])//如果两个并查集的Rank相同
			Rank[rx] += 1;//Rank增加
	}
}
int UF_set() {//main
	cout << "请初始化"<<endl;
	int n = 0; cin >> n;//确定初始化的并查集元素数
	init_UF_sets(n);char ch;//初始化并查集和命令字符
	cout << "1,查询 2,按秩合并" << endl;
	do {
		cin >> ch;
		if (ch == '1') {//查询操作
			int key = 0; cin >> key;//输入要查询的值
			int ans = find_UF_set(key);//返回结果
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
//#define MAXN 100000
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



/**/
//........................................................................

//树状数组//高级数据结构
int A[10001];//A数组
int C[10001];//C数组
int set_length = 0;//数组长度
int lowbit(int x) {
	return x & (-x);//lowbit函数
	//求出2^x//即从左向右第一个1后面的0数
}
int getSum(int x) {
	int ans = 0;//求前缀和的值
	while (x > 0) {//x是数组下标
		ans += C[x];//C(x)相加就是前缀和
		x -= lowbit(x);
	}
	return ans;
}
void update(int x, int value) {
	A[x] += value;//修改A数组
	while (x <= set_length) {//控制x比数组长度小
		C[x] += value;//修改C数组的值
		x += lowbit(x);//找到下一个要修改的C
	}
}
int read(int x) {//类似getSum()
	int ans = 0;
	while (x > 0) {
		ans += C[x];
		x -= lowbit(x);//算出
	}
	return ans;
}
int nu[10001];//求逆序数数据数组
int Con_Sum() {
	int i = 0, j = 0;
	while (i < set_length) {
		if (nu[i] != 0) {
			A[nu[i]] = 1;//将nu[i]对应的A改成1
			update(nu[i], 1);//更新A数组的值
		}
		i++;
	}
	i = 0;
	int sum = 0;
	while (j < set_length) {
		i = nu[j];//数组nu[j]的值
		int num = i - read(nu[j]);//每个逆序数的值
		sum += num;//统计逆序数的值
		j++;
	}
	return sum;
}
int Tre_set() {//main
	while (scanf("%d", &set_length) != EOF) {
		memset(A, 0, sizeof(A));//A申请空间
		memset(C, 0, sizeof(C));//C申请空间
		for (int i = 1; i <= set_length; i++) {
			scanf("%d", &A[i]);//输入A的值
			update(i, A[i]);//更新树状数组的值
		}
		printf("输入前缀和范围");
		int lim; cin >> lim;//输入区间
		int ans = getSum(lim);//getSum()函数
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}
//求逆序对//树状数组
int Tree_array_() {//main
	while (scanf("%d", &set_length) != EOF) {
		memset(A, 0, sizeof(A));//A申请空间
		memset(C, 0, sizeof(C));//C申请空间
		for (int i = 1; i <= set_length; i++) {
			scanf("%d", &A[i]);//输入A的值
			update(i, A[i]);//更新树状数组的值
		}
		for (int i = 0; i < set_length; i++) {
			scanf("%d", &nu[i]);
		}
		int ans = 0;
		ans = Con_Sum();
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}


/**/
//........................................................................

//线段树//高级数据结构
#define seg_Tree a
const int inf = 0x3f3f3f3f;//inf为无穷大
const int Uinf = 0xcfcfcfcf;//Uinf为无穷小
int a[N];//存储线段树的数组
int minv[4 * N];//存储线段树叶子节点的数组
int addv[4 * N];//标记数组，当节点完成更新，addv表示它对应的minv完成了更新，但下面的孩子还需要更新
int min(int x, int y) {
	int ans = x;//取最小值
	if (y < ans)ans = y;
	return ans;
}
void pushup(int x) {
	//从叶子节点开始//选择最小的值
	minv[x] = min(minv[2 * x], minv[2 * x + 1]);
}
void pushdown(int x) { //对这个x进行检查+更新
	if (!addv[x])return;//如果没有lazy tag返回
	addv[x * 2] += addv[x]; //左标记数组孩子更新//lazy tag向下传递
	addv[x * 2 + 1] += addv[x];//右标记数组孩子更新
	minv[x * 2] += addv[x];//对左右子节点的minv进行更新操作
	minv[x * 2 + 1] += addv[x];
	addv[x] = 0;//将原节点的标记数组值置零
}
void build(int x, int left, int right) {
	memset(addv, 0, N * 4 - 1);
	int mid = 0;//数组中间点
	if (left == right) {
		//递归中止条件:到达叶子节点
		minv[x] = a[left]; return;//将a数组的值copy到minv数组//作为叶子节点
	}
	mid = (left + right) / 2;
	build(x * 2, left, mid);//向左递归建左子树
	build(x * 2 + 1, mid + 1, right);//向右递归建右子树
	pushup(x);
}
int querymin(int x, int left, int right, int ql, int qr) {
	if (ql <= left && right <= qr) 
		return minv[x];//如果搜索的区间比线段树的区间大，直接返回根节点
	int mid = (left + right) / 2;
	int ans = inf;//令最后的结果为无穷大
	pushdown(x);//查询时要将之前的lazy tag执行完再查
	if (ql <= mid)ans = min(ans, querymin(x * 2, left, mid, ql, qr));//向左递归
	if (mid < qr)ans = min(ans, querymin(x * 2 + 1, mid + 1, right, ql, qr));//向右递归
	return ans;
}
void change_segTree(int x, int left, int right, int q, int v) {
	if (left == right) {
		minv[x] += v;
		addv[x] += v;
		return;
	}
	int mid = (left + right) >> 1;
	pushdown(x);
	if (q <= mid)
		change_segTree(x * 2, left, mid, q, v);
	else change_segTree(x * 2 + 1, mid + 1, right, q, v);
	pushup(x);
}
int seg_Trees_() {//main
	memset(seg_Tree, 0, sizeof(seg_Tree));//memset用来初始化和赋值，速度快。
	int n = 0; cin >> n;//输入数组长度//seg_Tree数组就是a数组
	for (int i = 1; i <= n; i++)//从1开始，方便输入和测试，从0开始则左右孩子全是0，错误
		cin >> seg_Tree[i];
	char ch;int p = 0, q = 0;
	while (cin >> ch) {
		if (ch == '1') {
			cin >> p >> q;//输入根节点，left，right
			build(1, p, q);//建立以o为根节点，pq为最左和最右叶子的线段树
			cout << "ok." << endl;
		}
		if (ch == '2') {
			int ql = 0, qr = 0;
			cin >> ql >> qr;//输入要查询的区间数组下标
			int ans = querymin(1, p, q, ql, qr);
			cout << "min value = " << ans << endl;
		}
		if (ch == '3') {
			int key, value;
			cin >> key >> value;//输入更新节点下标(key)，更新后的值(value)
			int va = value - a[key];//计算出差值
			change_segTree(1, p, q, key, va);
			cout << "ok." << endl;
		}
		if (ch == '4') {
			return 0;
		}
	}
	system("pause");
	return 0;
}
//a数组，minv数组分别代表什么:a是线段树本身的数组，minv是存储树的数组
//build时left和right怎么设置，意义是什么:left和right代表你想要建线段树的区间。（1，1，n）
//build时根节点怎么设置:根节点为a[1]

//poj//买票问题//线段树
struct seq{
	int pos, val;
}al[200000 + 10];
int num1[800000 + 100];
int ans[200000 + 100];
void Build(int root, int left, int right){//建树建了个寂寞qwq
	num1[root] = right - left + 1;//这个是区间
	int mid = (left + right) >> 1;//这个是中点
	if (left == right)
		return;//已经到达根节点
	Build(root * 2, left, mid);
	Build(root * 2 + 1, mid + 1, right);
}
int update(int pos, int root, int left, int right){
	num1[root]--;//空位置数量-1
	int mid = (left + right) >> 1;
	if (left == right)
		return left;//到达根节点//返回数组下标即可
	if (num1[root * 2] > pos)//pos是从0开始的 而线段树是从1开始存储的 但0和1在此题中是对应存储的
		return update(pos, root * 2, left, mid);//pos小于左孩子，进入左孩子更新
	else//如果pos大于左孩子，pos进入右子树更新，同时pos减去左孩子部分
		return update(pos - num1[root * 2], root * 2 + 1, mid + 1, right);
}
int buy_tiket_(){//main
	int n, i;
	while (scanf("%d", &n) != EOF){
		for (i = 0; i < n; i++) {
			scanf("%d %d", &al[i].pos, &al[i].val);
		}//存储pi和vail
		Build(1, 1, n);//从1号节点开始建树 区间[1,n]
		for (i = n - 1; i >= 0; i--)
			ans[update(al[i].pos, 1, 1, n)] = al[i].val;//数据放入位置
		for (i = 1; i <= n; i++) 
			printf("%d%c", ans[i], i == n ? '\n' : ' ');//高级的输出方法！！
	}
	return 0;
}

//旅馆问题//线段树
/*
int room[N];
int roomlist[N * 4];
void buildroom(int root, int left, int right, int room[], int roomlist[]) {
	roomlist[root] = right - left + 1;
	int mid = (right + left) >> 1;
	if (left == right)return;
	else {
		buildroom(root * 2, left, mid, room, roomlist);
		buildroom(root * 2 + 1, mid + 1, right, room, roomlist);
	}
}
void printroom(int root, int left, int right, int room[], int roomlist[], int i) {
	cout << "room" << i << "----->" << "a[" << root << "]" << endl;
	i++;
	if (left == right)return;
	else {
		int mid = (left + right) >> 1;
		printroom(root * 2, left, mid, room, roomlist, i);
		printroom(root * 2 + 1, mid + 1, right, room, roomlist, i);
	}
}
int queryroom(int root, int left, int right, int room[], int roomlist[], int length) {
	if (left == right)return 0;
	if (roomlist[root] < length && left != right)  {
		int mid = (left + right) >> 1;
		queryroom(root * 2, left, mid, room, roomlist, length);
		queryroom(root * 2 + 1, mid + 1, right, room, roomlist, length);
	}
	else {
		cout << "查询成功！！！" << endl;
		printroom(root, root * 2, root * 2 + 1, room, roomlist, 0);
		return root;
	}
}
int bookroom(int root, int left, int right, int roomlist[], int room[], int length) {
	int pos = queryroom(root, left, right, roomlist, room, length);
	return 1;
}*/
typedef struct roomNod {
	int lsum;
	int rsum;
	int sum;
	int cover;
}rooms;
roomNod roomTree[4*N];
bool room[N];
void pushup_room(int x) {
	roomTree[x].lsum = roomTree[x * 2].sum;
	roomTree[x].rsum = roomTree[x * 2 + 1].sum;
	roomTree[x].sum = max(roomTree[x * 2].sum, roomTree[x * 2 + 1].sum);
}
void buildroom(int left, int right, int x) {
	memset(room, 1, sizeof(room));
	if (left == right) {
		roomTree[x].sum = 1;
		roomTree[x].cover = 1;
		return; 
	}
	int mid = (left + right) >> 1;
	buildroom(left, mid, x * 2);
	buildroom(mid + 1, right, x * 2 + 1);
	pushup_room(x);
}
void pushdown_room(int x) {
	if (roomTree[x].cover == 1 && roomTree[x].cover == -1) return;
	roomTree[x * 2].cover = 0; roomTree[x * 2 + 1].cover = 0;
	
}



/**/
//........................................................................

//poj//滑雪

int h, v;
int dp[110][110];
int ai[110][110];
int to[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
bool judge(int x, int y) {//判断是否可以进行搜索
	if (x >= 1 && x <= h && y >= 1 && y <= v)
		return 1;//进行判定是否数组越界
	else return 0;
}
int find(int x, int y) {
	if (dp[x][y])//如果已经搜索过，直接返回
		return dp[x][y];
	int d = 1, k, tx, ty;
	for (k = 0; k < 4; k++) {//将两个方向都搜索了一遍
		tx = x + to[k][0];//实际搜索的X坐标
		ty = y + to[k][1];//实际搜索的y坐标
		if (judge(tx, ty) && ai[x][y] > ai[tx][ty])//进行判定，1.是否可以被搜索，2.是否增加了路径长度
			d = max(find(tx, ty) + 1, d);//递归搜索，分叉，最终四个方向中找最大的
	}//for循环将四个方向都搜索了一遍，且进行了分方向的递归
	dp[x][y] = d;//将搜索后max值直接赋给dp
	return d;
}
int hua_() {//main
	while (~scanf("%d%d", &h, &v)) {//多样例输入
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		int i, j;//声明两个计数器分别表示行和列
		for (i = 1; i <= h; i++)
			for (j = 1; j <= v; j++)
				scanf("%d", &ai[i][j]);//输入矩阵
		int s = 0;//作为最大值
		for (i = 1; i <= h; i++)
			for (j = 1; j <= v; j++)
				s = max(find(i, j), s);//对每个点调用find()，同时随时更新最大值
		printf("%d\n", s);
	}
	return 0;
}



/**/
//........................................................................

//树链剖分&链式前向星//高级数据结构
//#define edge e
#define next nx
#define to v
const int maxm = 110000;
const int maxn = 1100000;

struct node{
	int nx, v;//value
};
node e[maxm];//声明边的数组
int head[maxn];//声明编号最大边
int count1, n, m, cnt;//声明点数，边数，cnt代指特定边
void add_edge(int from, int v, int cost){//
	e[cnt].v = v;//边的尾
	//edge[cnt].value = cost;//边的代价
	e[cnt].nx = head[from];//即以from为起点的所有边中编号最大的
	head[from] = cnt++;//head[from] = cnt；cnt++；head更新了
	//head[i]保存的是以i为起点的所有边中编号最大的那个
}
void show(){
	int i, t;
	for (i = 1; i <= n; i++){
		t = head[i];
		while (t != -1){//head[i]！= -1，即存在以此from为顶点的边
			cout << i << "-->" << e[t].v << endl;// " need " << edge[t].value << endl;
			t = e[t].nx;//接下来按照head-->next方法找到从编号最大边后所有以此from为顶点的边
		}
	}
}
//树链剖分//高级数据结构
int size1[N];//表示以u为根的树的节点个数
int son[N];//表示u的重儿子
int f1[N];//节点的父节点//fa[N]
int dep[N];//节点的深度//deep[N]
//int head1[N];//编号最大的边//first[N]
void dfs1(int u, int fa) {//找到轻重儿子
	size1[u] = 1;//表示刚搜到u的时候以u为根的?树?只有u?个节点
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;//连向的节点
		if (v != fa) {
			dep[v] = dep[u] + 1;//v的深度是当前节点的深度+1
			f1[v] = u;//记录?下?亲
			dfs1(v, u);//继续往下搜，?直搜到叶节点为?
			size1[u] += size1[v];//往上回溯，更新以u为根的?树的size
			if (size1[v] > size1[son[u]])son[u] = v;
		}
	}
}
int top[N];//节点u所在的链顶端
int id[N];//节点u的新编号//now
int a1[N];//在新编号(dfs)下的当前点的值//past  
int w[N];//题目中给出的节点u的值//x=u
void dfs2(int u, int t) {//将轻重儿子连链
	id[u] = ++count1;//给这个点?个新的编号
	a1[count1] = w[u];//记录这个编号下点的值
	top[u] = t;//记录u所在链的顶端为t
	if (son[u]) dfs2(son[u], t);//u的重??和u在同?条链?
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;//搜轻??
		if (v != f1[u] && v != son[u])//判断是否是轻??
			dfs2(v, v);//以轻??为顶的链
	}
}
int LCA(int x, int y) {
	int fx = top[x];//找到x的链顶
	int fy = top[y];//找到y的链顶
	while (fx != fy) {//链顶不一样//即xy不在同一链
		if (dep[fx] < dep[fy]) {//将x置换为深度小的
			swap(x, y);
			swap(fx, fy);
		}
		x = f1[fx];//x向上跳，原来的链顶赋给x
		fx = top[x];//现在的链顶变成原来链顶的链顶
	}
	return dep[x] < dep[y] ? x : y;//返回最后的深度//即LCA
}
int Star_(){//main
	//freopen("input.txt","r",stdin);
	int from, to;//起点，终点
	printf("请输入点数和边数（n，m）：");
	scanf("%d %d", &n, &m);
	memset(e, 0, sizeof(e));
	memset(head, -1, sizeof(head));
	cnt = 1;//将计数器置1
	count1 = 1;
	int p = m;
	while (p--) { //输入边，因为是无向图，所以要有来有回
		cin >> from >> to;
		add_edge(from, to,1);//正方向
		add_edge(to, from,1);//反方向
	}
	show();
	dfs1(1, 1);//找到轻重儿子
	dfs2(1, 1);//将轻重儿子连成链
	printf("想要求A和B的最近公共祖先，输入A和B\n");
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF) {
		printf("%d\n", LCA(A, B));
	}
	return 0;
}
//e结构体数组里面存放的是：
//to&v：该条边指向的下一个顶点
//value&cost：即该条边的权值
//next&nx：表示与此条边的from顶点连接的其他边
//用head[from]来记录每一个顶点连接的其他边的最大编号(除了自己)

//注意：链式前向星的结构体数组与树链剖分的结构体数组一样，正常情况只需要存储next和to即可。



/**/
//........................................................................

//高级数据结构//块状数组
#define Datasize 100
struct LinkNod {
	int data[Datasize];
	int length;
	LinkNod* next;
};
int Len;
int Nodlen;
void Div_Link(LinkNod* &p) {
	if (p->length < sqrt(Len))return;
	int mid = (p->length) >> 1;
	LinkNod* q; q = (LinkNod*)malloc(sizeof(LinkNod));
	for (int i = mid; i < p->length; i++) {
		q->data[i - mid] = p->data[i];
		p->data[i] = 0;
	}
	q->next = p->next;
	p->next = q;
	Nodlen++;
}
void Add_Link(LinkNod* &T, int value, int i, int key) {
	LinkNod* p; p = T;
	for (int j = 0; j < i; j++) {
		p = p->next;
		if (p->length > sqrt(Len)) Div_Link(p);
	}
	for (int j = sqrt(Len); j >= key; j--) {
		p->data[j] = p->data[j + 1];
	}
	p->data[key] = value;
	Len++;
}
int search_Link(LinkNod* T, int i, int key ){
	LinkNod* p; p = (LinkNod*)malloc(sizeof(LinkNod));
	p = T;
	for (int k = 0; k < i; k++) {
		p = p->next;
	}
	return p->data[key];
}
void print_Link(LinkNod* T) {
	LinkNod* p; p = (LinkNod*)malloc(sizeof(LinkNod));
	p = T;
	while (p) {
		for (int i = 0; i < p->length; p++) {
			cout << p->data[i] << " ";
		}
		p = p->next;
	}
}
void init_Link(LinkNod* &T) {
	T = (LinkNod*)malloc(sizeof(LinkNod));
}
int mian() {//Link_
	char ch;
	LinkNod* T;
	init_Link(T);
	int value, i, key;
	while (scanf("%c", &ch) != EOF) {
		if (ch == '1') {
			printf("请输入要添加的元素：(value,i,key)");
			cin >> value >> i >> key;
			Add_Link(T, value, i, key);
		}
		if (ch == '2') {
			printf("请输入要查询的位置");
			cin >> i >> key;
			printf("%d", search_Link(T, i, key));
		}
		if (ch == '3') {
			printf("当前的块状链表的元素是");
			print_Link(T);
		}
	}
	return 0;
}

/**/
//......................................................................................................
//Dinic算法//网络流
const ll Ni = 2e5 + 10;
struct Nod {
	ll to, next, w;//w是流量(权值)
} edge[Ni]; //存边
//from=x
ll num_n, num_m, s, t, u, num_v, num_w, counts = 1;
//s:源节点数组下标
//t:汇节点数组下标
//n:节点数量
//m:边的数量
//d[Ni]深度数组
int hea[Ni], maxflow, d[Ni], now[Ni];
void add_Net_Stream(int from, int to, int w)  {//链式向前星添加边
	edge[counts].to = to;
	edge[counts].next = hea[from];
	edge[counts].w = w;
	hea[from] = counts++;
}
int bfs() {
	queue<ll>q;
	memset(d, 0, sizeof(d));//初始0
	while (!q.empty())q.pop();//清空
	q.push(s), d[s] = 1, now[s] = hea[s];
	while (!q.empty()) {
		ll x = q.front();
		q.pop();//x是队头元素，bfs开始的位置
		for (ll i = hea[x]; i; i = edge[i].next) {//i是选定的一条弧，遍历时则向下一条弧遍历(同一起点)
			ll v = edge[i].to;//v作为edge[i]通向的节点数组下标,to==v
			if (edge[i].w && !d[v]) {//在dv没赋值且w不为0时
				d[v] = d[x] + 1;//将v变成x的下一层
				q.push(v);//v入队
				now[v] = hea[v];//
				if (v == t)return 1;
			}
		}
	}
	return 0;
}
ll dinic(ll x, ll flow) {
	if (x == t)return flow;//如果到了汇点，返回
	ll rest = flow, i, k;//rest剩余量
	for (i = now[x]; i && rest; i = edge[i].next) {
		ll v = edge[i].to;
		if (edge[i].w && d[v] == d[x] + 1) {//w还有且v在x下一层
			k = dinic(v, min(rest, edge[i].w));//递归找最小的流量
			if (!k)d[v] = 0;//没有就dv置零
			edge[i].w -= k;//减去流量
			edge[i ^ 1].w += k;//
			rest -= k;
		}
	}
	now[x] = i;
	return flow - rest;//返回可以加入流的值
}
int Dinic_main() { //
	printf("节点数，边数，源点，汇点 ：");
	scanf(" %lld%lld%lld%lld", &num_n, &num_m, &s, &t);
	for (ll i = 1; i <= num_m; i++) {
		printf("边的起点，终点，容量 ：");
		scanf_s(" %lld%lld%lld", &u, &num_v, &num_w), add_Net_Stream(u, num_v, num_w), add_Net_Stream(num_v, u, 0);
	}
	while (bfs())
		while (ll res = dinic(s, inf))
			maxflow += res;
	printf("汇点最大流为：%lld\n", maxflow);
	system("pause");
	return 0;
}
int buy_pig_main() {//买猪
	int rooms, buyers;//猪圈数量，顾客数量
	while (cin >> rooms >> buyers) {
		n = rooms * buyers + buyers + 2;//节点数量
		int* num; int** key; int* bu;//num：初始猪圈中的猪数//存储顾客拥有的钥匙//存储每个顾客要买猪的数量
		num = new int[rooms + 1];//初始化num//key//bu数组
		key = new int* [buyers + 1];
		bu = new int[buyers + 1];
		for (int i = 1; i < buyers + 1; i++) {//初始化二维数组//每个顾客拥有的钥匙
			key[i] = new int[1000];//分配空间
		}
		for (int i = 1; i <= rooms; i++) {
			cin >> num[i];//输入每个猪圈初始的猪的数量
		}
		for (int i = 1; i < buyers; i++) {//输入key
			cin >> key[i][0];//输入第i个客人拥有钥匙的数量
			for (int j = 1; j < key[i][0]; j++) {//输入每个钥匙对应的猪圈号
				cin >> key[i][j];
			}
			cin >> bu[i];//输入每个顾客要买的猪的数量
		}
		s = 1; t = n; int i = 0;//s是源点，t是汇点，计数器置零
		for (i = 2; i < rooms+2; i++) {//对初始猪圈进行建边
			add_Net_Stream(1, i, num[i]), add_Net_Stream(i, 1, 0);
		}//i=M+1
		int w = i; int j = 0;//存储此时计数器的大小
		for (i = 2; i <= rooms+1; i++) {//由于w不会变//通过w可知第二层猪圈建边完成后i到2M+1
			for (j = 1; j <= buyers; j++) {//建立不同顾客(时序不同)的同一猪圈之间的边//先1号，再2号...
				add_Net_Stream(i + j * rooms, i + rooms * (j - 1), 0), add_Net_Stream(i + (j - 1) * rooms, i + j * rooms, 100010);
			}//通过数学方法计算不同时序的同一猪圈的建边
		}
		for (i = rooms * buyers + 2; i <= rooms * buyers + 1 + buyers; i++)  {
			for (j = 1; j < key[i][0]; j++) {//两层循环把顾客与不同时序的猪圈建边
				add_Net_Stream(key[i][j] + 1 + (i - rooms * buyers - 2) * rooms, i, 100010), add_Net_Stream(i, key[i][j] + 1 + (i - rooms * buyers - 2) * rooms, 0);
			}
		}
		j = 0;//初始化B的计数器
		for (int i = n - 1; i > n - buyers - 1; i--) {
			add_Net_Stream(i, n, bu[j++]), add_Net_Stream(n, i, 0);//建立从顾客到源点的边(顾客要买多少头猪)
		}
		for (int i = 0; i < rooms; i++) {

		}
		while (bfs())
			while (ll res = dinic(s, inf))
				maxflow += res;
		printf("卖的猪最多为：%lld\n", maxflow);
		system("pause");
		return 0;
	}
}

//买猪问题：
//节点数，边数，源点，汇点 ：5 7 1 5
//边的起点，终点，容量 ：1 2 4
//边的起点，终点，容量 ：1 3 10
//边的起点，终点，容量 ：2 3 1000010
//边的起点，终点，容量 ：2 4 1000010
//边的起点，终点，容量 ：2 5 2
//边的起点，终点，容量 ：3 5 3
//边的起点，终点，容量 ：4 5 6
//汇点最大流为：11   只猪

//牛吃喝问题：
//节点数，边数，源点，汇点 ：16 25 1 16
//边的起点，终点，容量 ：1 10 1
//边的起点，终点，容量 ：1 11 1
//边的起点，终点，容量 ：1 12 1
//边的起点，终点，容量 ：10 2 100010
//边的起点，终点，容量 ：10 4 100010
//边的起点，终点，容量 ：10 5 100010
//边的起点，终点，容量 ：11 2 100010
//边的起点，终点，容量 ：11 3 100010
//边的起点，终点，容量 ：12 3 100010
//边的起点，终点，容量 ：12 4 100010
//边的起点，终点，容量 ：12 5 100010
//边的起点，终点，容量 ：2 6 1
//边的起点，终点，容量 ：3 7 1
//边的起点，终点，容量 ：4 8 1
//边的起点，终点，容量 ：5 9 1
//边的起点，终点，容量 ：6 13 100010
//边的起点，终点，容量 ：6 15 100010
//边的起点，终点，容量 ：7 13 100010
//边的起点，终点，容量 ：7 14 100010
//边的起点，终点，容量 ：8 13 100010
//边的起点，终点，容量 ：8 14 100010
//边的起点，终点，容量 ：9 15 100010
//边的起点，终点，容量 ：13 16 1
//边的起点，终点，容量 ：14 16 1
//边的起点，终点，容量 ：15 16 1
//汇点最大流为：3

