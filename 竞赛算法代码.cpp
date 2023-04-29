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

//���鼯//�߼����ݽṹ
#define MAXN 100
int Parent[MAXN];
int Rank[MAXN];
int find_UF_set(int x) {//����x�ĸ��ڵ�
	if (Parent[x] == x)return x;//x���Ǵ���Ԫ��(���ڵ�)
	else return find_UF_set(Parent[x]);//x���Ǹ��ڵ㣬���ϵݹ�
}
void init_UF_sets(int n) {//��ʼ��
	for (int i = 0; i < n; i++) {
		Parent[i] = i;//��ʼ�����鼯
		Rank[i] = 1;//������
	}
}
void merge(int x, int y) {//���鼯���Ⱥϲ�
	int rx = find_UF_set(x);//�ҵ�x�ĸ��ڵ�
	int ry = find_UF_set(y);//�ҵ�y�ĸ��ڵ�
	if (rx != ry){//�������ͬһ������
		if (Rank[rx] < Rank[ry]){//rank��ļ��Ϻϲ�rankС�ļ���
			swap(rx, ry);//������н�����Ϊ�˱�֤rx��rank����ry��rank����������ϲ�
		}
		Parent[ry] = rx;//rx �ϲ� ry
		if (Rank[rx] == Rank[ry])//����������鼯��Rank��ͬ
			Rank[rx] += 1;//Rank����
	}
}
int UF_set() {//main
	cout << "���ʼ��"<<endl;
	int n = 0; cin >> n;//ȷ����ʼ���Ĳ��鼯Ԫ����
	init_UF_sets(n);char ch;//��ʼ�����鼯�������ַ�
	cout << "1,��ѯ 2,���Ⱥϲ�" << endl;
	do {
		cin >> ch;
		if (ch == '1') {//��ѯ����
			int key = 0; cin >> key;//����Ҫ��ѯ��ֵ
			int ans = find_UF_set(key);//���ؽ��
			printf("%d", ans);
		}
		if (ch == '2') {//�ϲ�����
			int x, y;//Ҫ�ϲ�������Ԫ��
			cin >> x >> y;//����Ԫ��
			merge(x, y);//�ϲ�
		}
		if (ch == '#')break;
	} while (ch != '#');
	return 0;
}
//��������
//#define MAXN 100000
int Ra[MAXN];
int Rfind_UF_set(int x) {//����x�ĸ��ڵ�
	if (Ra[x] == x)return x;//x���Ǵ���Ԫ��(���ڵ�)
	else return find_UF_set(Ra[x]);//x���Ǹ��ڵ㣬���ϵݹ�
}
void Rinit_UF_sets(int n) {//��ʼ��
	for (int i = 0; i < n; i++) {
		Ra[i] = i;//��ʼ�����鼯
	}
}
void Rmerge(int x, int y) {//���鼯���Ⱥϲ�
	int rx = find_UF_set(x);//�ҵ�x�ĸ��ڵ�
	int ry = find_UF_set(y);//�ҵ�y�ĸ��ڵ�
	Ra[ry] = rx;//rx �ϲ� ry
}
int Find_Ralitives_() {//main
	int n = 0, m = 0, p = 0; 
	cin >> n >> m >> p;
	init_UF_sets(n); //��ʼ�����鼯�������ַ�
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

//��״����//�߼����ݽṹ
int A[10001];//A����
int C[10001];//C����
int set_length = 0;//���鳤��
int lowbit(int x) {
	return x & (-x);//lowbit����
	//���2^x//���������ҵ�һ��1�����0��
}
int getSum(int x) {
	int ans = 0;//��ǰ׺�͵�ֵ
	while (x > 0) {//x�������±�
		ans += C[x];//C(x)��Ӿ���ǰ׺��
		x -= lowbit(x);
	}
	return ans;
}
void update(int x, int value) {
	A[x] += value;//�޸�A����
	while (x <= set_length) {//����x�����鳤��С
		C[x] += value;//�޸�C�����ֵ
		x += lowbit(x);//�ҵ���һ��Ҫ�޸ĵ�C
	}
}
int read(int x) {//����getSum()
	int ans = 0;
	while (x > 0) {
		ans += C[x];
		x -= lowbit(x);//���
	}
	return ans;
}
int nu[10001];//����������������
int Con_Sum() {
	int i = 0, j = 0;
	while (i < set_length) {
		if (nu[i] != 0) {
			A[nu[i]] = 1;//��nu[i]��Ӧ��A�ĳ�1
			update(nu[i], 1);//����A�����ֵ
		}
		i++;
	}
	i = 0;
	int sum = 0;
	while (j < set_length) {
		i = nu[j];//����nu[j]��ֵ
		int num = i - read(nu[j]);//ÿ����������ֵ
		sum += num;//ͳ����������ֵ
		j++;
	}
	return sum;
}
int Tre_set() {//main
	while (scanf("%d", &set_length) != EOF) {
		memset(A, 0, sizeof(A));//A����ռ�
		memset(C, 0, sizeof(C));//C����ռ�
		for (int i = 1; i <= set_length; i++) {
			scanf("%d", &A[i]);//����A��ֵ
			update(i, A[i]);//������״�����ֵ
		}
		printf("����ǰ׺�ͷ�Χ");
		int lim; cin >> lim;//��������
		int ans = getSum(lim);//getSum()����
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}
//�������//��״����
int Tree_array_() {//main
	while (scanf("%d", &set_length) != EOF) {
		memset(A, 0, sizeof(A));//A����ռ�
		memset(C, 0, sizeof(C));//C����ռ�
		for (int i = 1; i <= set_length; i++) {
			scanf("%d", &A[i]);//����A��ֵ
			update(i, A[i]);//������״�����ֵ
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

//�߶���//�߼����ݽṹ
#define seg_Tree a
const int inf = 0x3f3f3f3f;//infΪ�����
const int Uinf = 0xcfcfcfcf;//UinfΪ����С
int a[N];//�洢�߶���������
int minv[4 * N];//�洢�߶���Ҷ�ӽڵ������
int addv[4 * N];//������飬���ڵ���ɸ��£�addv��ʾ����Ӧ��minv����˸��£�������ĺ��ӻ���Ҫ����
int min(int x, int y) {
	int ans = x;//ȡ��Сֵ
	if (y < ans)ans = y;
	return ans;
}
void pushup(int x) {
	//��Ҷ�ӽڵ㿪ʼ//ѡ����С��ֵ
	minv[x] = min(minv[2 * x], minv[2 * x + 1]);
}
void pushdown(int x) { //�����x���м��+����
	if (!addv[x])return;//���û��lazy tag����
	addv[x * 2] += addv[x]; //�������麢�Ӹ���//lazy tag���´���
	addv[x * 2 + 1] += addv[x];//�ұ�����麢�Ӹ���
	minv[x * 2] += addv[x];//�������ӽڵ��minv���и��²���
	minv[x * 2 + 1] += addv[x];
	addv[x] = 0;//��ԭ�ڵ�ı������ֵ����
}
void build(int x, int left, int right) {
	memset(addv, 0, N * 4 - 1);
	int mid = 0;//�����м��
	if (left == right) {
		//�ݹ���ֹ����:����Ҷ�ӽڵ�
		minv[x] = a[left]; return;//��a�����ֵcopy��minv����//��ΪҶ�ӽڵ�
	}
	mid = (left + right) / 2;
	build(x * 2, left, mid);//����ݹ齨������
	build(x * 2 + 1, mid + 1, right);//���ҵݹ齨������
	pushup(x);
}
int querymin(int x, int left, int right, int ql, int qr) {
	if (ql <= left && right <= qr) 
		return minv[x];//���������������߶����������ֱ�ӷ��ظ��ڵ�
	int mid = (left + right) / 2;
	int ans = inf;//�����Ľ��Ϊ�����
	pushdown(x);//��ѯʱҪ��֮ǰ��lazy tagִ�����ٲ�
	if (ql <= mid)ans = min(ans, querymin(x * 2, left, mid, ql, qr));//����ݹ�
	if (mid < qr)ans = min(ans, querymin(x * 2 + 1, mid + 1, right, ql, qr));//���ҵݹ�
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
	memset(seg_Tree, 0, sizeof(seg_Tree));//memset������ʼ���͸�ֵ���ٶȿ졣
	int n = 0; cin >> n;//�������鳤��//seg_Tree�������a����
	for (int i = 1; i <= n; i++)//��1��ʼ����������Ͳ��ԣ���0��ʼ�����Һ���ȫ��0������
		cin >> seg_Tree[i];
	char ch;int p = 0, q = 0;
	while (cin >> ch) {
		if (ch == '1') {
			cin >> p >> q;//������ڵ㣬left��right
			build(1, p, q);//������oΪ���ڵ㣬pqΪ���������Ҷ�ӵ��߶���
			cout << "ok." << endl;
		}
		if (ch == '2') {
			int ql = 0, qr = 0;
			cin >> ql >> qr;//����Ҫ��ѯ�����������±�
			int ans = querymin(1, p, q, ql, qr);
			cout << "min value = " << ans << endl;
		}
		if (ch == '3') {
			int key, value;
			cin >> key >> value;//������½ڵ��±�(key)�����º��ֵ(value)
			int va = value - a[key];//�������ֵ
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
//a���飬minv����ֱ����ʲô:a���߶�����������飬minv�Ǵ洢��������
//buildʱleft��right��ô���ã�������ʲô:left��right��������Ҫ���߶��������䡣��1��1��n��
//buildʱ���ڵ���ô����:���ڵ�Ϊa[1]

//poj//��Ʊ����//�߶���
struct seq{
	int pos, val;
}al[200000 + 10];
int num1[800000 + 100];
int ans[200000 + 100];
void Build(int root, int left, int right){//�������˸���įqwq
	num1[root] = right - left + 1;//���������
	int mid = (left + right) >> 1;//������е�
	if (left == right)
		return;//�Ѿ�������ڵ�
	Build(root * 2, left, mid);
	Build(root * 2 + 1, mid + 1, right);
}
int update(int pos, int root, int left, int right){
	num1[root]--;//��λ������-1
	int mid = (left + right) >> 1;
	if (left == right)
		return left;//������ڵ�//���������±꼴��
	if (num1[root * 2] > pos)//pos�Ǵ�0��ʼ�� ���߶����Ǵ�1��ʼ�洢�� ��0��1�ڴ������Ƕ�Ӧ�洢��
		return update(pos, root * 2, left, mid);//posС�����ӣ��������Ӹ���
	else//���pos�������ӣ�pos�������������£�ͬʱpos��ȥ���Ӳ���
		return update(pos - num1[root * 2], root * 2 + 1, mid + 1, right);
}
int buy_tiket_(){//main
	int n, i;
	while (scanf("%d", &n) != EOF){
		for (i = 0; i < n; i++) {
			scanf("%d %d", &al[i].pos, &al[i].val);
		}//�洢pi��vail
		Build(1, 1, n);//��1�Žڵ㿪ʼ���� ����[1,n]
		for (i = n - 1; i >= 0; i--)
			ans[update(al[i].pos, 1, 1, n)] = al[i].val;//���ݷ���λ��
		for (i = 1; i <= n; i++) 
			printf("%d%c", ans[i], i == n ? '\n' : ' ');//�߼��������������
	}
	return 0;
}

//�ù�����//�߶���
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
		cout << "��ѯ�ɹ�������" << endl;
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

//poj//��ѩ

int h, v;
int dp[110][110];
int ai[110][110];
int to[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
bool judge(int x, int y) {//�ж��Ƿ���Խ�������
	if (x >= 1 && x <= h && y >= 1 && y <= v)
		return 1;//�����ж��Ƿ�����Խ��
	else return 0;
}
int find(int x, int y) {
	if (dp[x][y])//����Ѿ���������ֱ�ӷ���
		return dp[x][y];
	int d = 1, k, tx, ty;
	for (k = 0; k < 4; k++) {//����������������һ��
		tx = x + to[k][0];//ʵ��������X����
		ty = y + to[k][1];//ʵ��������y����
		if (judge(tx, ty) && ai[x][y] > ai[tx][ty])//�����ж���1.�Ƿ���Ա�������2.�Ƿ�������·������
			d = max(find(tx, ty) + 1, d);//�ݹ��������ֲ棬�����ĸ�������������
	}//forѭ�����ĸ�����������һ�飬�ҽ����˷ַ���ĵݹ�
	dp[x][y] = d;//��������maxֱֵ�Ӹ���dp
	return d;
}
int hua_() {//main
	while (~scanf("%d%d", &h, &v)) {//����������
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		int i, j;//���������������ֱ��ʾ�к���
		for (i = 1; i <= h; i++)
			for (j = 1; j <= v; j++)
				scanf("%d", &ai[i][j]);//�������
		int s = 0;//��Ϊ���ֵ
		for (i = 1; i <= h; i++)
			for (j = 1; j <= v; j++)
				s = max(find(i, j), s);//��ÿ�������find()��ͬʱ��ʱ�������ֵ
		printf("%d\n", s);
	}
	return 0;
}



/**/
//........................................................................

//�����ʷ�&��ʽǰ����//�߼����ݽṹ
//#define edge e
#define next nx
#define to v
const int maxm = 110000;
const int maxn = 1100000;

struct node{
	int nx, v;//value
};
node e[maxm];//�����ߵ�����
int head[maxn];//�����������
int count1, n, m, cnt;//����������������cnt��ָ�ض���
void add_edge(int from, int v, int cost){//
	e[cnt].v = v;//�ߵ�β
	//edge[cnt].value = cost;//�ߵĴ���
	e[cnt].nx = head[from];//����fromΪ�������б��б������
	head[from] = cnt++;//head[from] = cnt��cnt++��head������
	//head[i]���������iΪ�������б��б�������Ǹ�
}
void show(){
	int i, t;
	for (i = 1; i <= n; i++){
		t = head[i];
		while (t != -1){//head[i]��= -1���������Դ�fromΪ����ı�
			cout << i << "-->" << e[t].v << endl;// " need " << edge[t].value << endl;
			t = e[t].nx;//����������head-->next�����ҵ��ӱ�����ߺ������Դ�fromΪ����ı�
		}
	}
}
//�����ʷ�//�߼����ݽṹ
int size1[N];//��ʾ��uΪ�������Ľڵ����
int son[N];//��ʾu���ض���
int f1[N];//�ڵ�ĸ��ڵ�//fa[N]
int dep[N];//�ڵ�����//deep[N]
//int head1[N];//������ı�//first[N]
void dfs1(int u, int fa) {//�ҵ����ض���
	size1[u] = 1;//��ʾ���ѵ�u��ʱ����uΪ����?��?ֻ��u?���ڵ�
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;//����Ľڵ�
		if (v != fa) {
			dep[v] = dep[u] + 1;//v������ǵ�ǰ�ڵ�����+1
			f1[v] = u;//��¼?��?��
			dfs1(v, u);//���������ѣ�?ֱ�ѵ�Ҷ�ڵ�Ϊ?
			size1[u] += size1[v];//���ϻ��ݣ�������uΪ����?����size
			if (size1[v] > size1[son[u]])son[u] = v;
		}
	}
}
int top[N];//�ڵ�u���ڵ�������
int id[N];//�ڵ�u���±��//now
int a1[N];//���±��(dfs)�µĵ�ǰ���ֵ//past  
int w[N];//��Ŀ�и����Ľڵ�u��ֵ//x=u
void dfs2(int u, int t) {//�����ض�������
	id[u] = ++count1;//�������?���µı��
	a1[count1] = w[u];//��¼�������µ��ֵ
	top[u] = t;//��¼u�������Ķ���Ϊt
	if (son[u]) dfs2(son[u], t);//u����??��u��ͬ?����?
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;//����??
		if (v != f1[u] && v != son[u])//�ж��Ƿ�����??
			dfs2(v, v);//����??Ϊ������
	}
}
int LCA(int x, int y) {
	int fx = top[x];//�ҵ�x������
	int fy = top[y];//�ҵ�y������
	while (fx != fy) {//������һ��//��xy����ͬһ��
		if (dep[fx] < dep[fy]) {//��x�û�Ϊ���С��
			swap(x, y);
			swap(fx, fy);
		}
		x = f1[fx];//x��������ԭ������������x
		fx = top[x];//���ڵ��������ԭ������������
	}
	return dep[x] < dep[y] ? x : y;//�����������//��LCA
}
int Star_(){//main
	//freopen("input.txt","r",stdin);
	int from, to;//��㣬�յ�
	printf("����������ͱ�����n��m����");
	scanf("%d %d", &n, &m);
	memset(e, 0, sizeof(e));
	memset(head, -1, sizeof(head));
	cnt = 1;//����������1
	count1 = 1;
	int p = m;
	while (p--) { //����ߣ���Ϊ������ͼ������Ҫ�����л�
		cin >> from >> to;
		add_edge(from, to,1);//������
		add_edge(to, from,1);//������
	}
	show();
	dfs1(1, 1);//�ҵ����ض���
	dfs2(1, 1);//�����ض���������
	printf("��Ҫ��A��B������������ȣ�����A��B\n");
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF) {
		printf("%d\n", LCA(A, B));
	}
	return 0;
}
//e�ṹ�����������ŵ��ǣ�
//to&v��������ָ�����һ������
//value&cost���������ߵ�Ȩֵ
//next&nx����ʾ������ߵ�from�������ӵ�������
//��head[from]����¼ÿһ���������ӵ������ߵ������(�����Լ�)

//ע�⣺��ʽǰ���ǵĽṹ�������������ʷֵĽṹ������һ�����������ֻ��Ҫ�洢next��to���ɡ�



/**/
//........................................................................

//�߼����ݽṹ//��״����
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
			printf("������Ҫ��ӵ�Ԫ�أ�(value,i,key)");
			cin >> value >> i >> key;
			Add_Link(T, value, i, key);
		}
		if (ch == '2') {
			printf("������Ҫ��ѯ��λ��");
			cin >> i >> key;
			printf("%d", search_Link(T, i, key));
		}
		if (ch == '3') {
			printf("��ǰ�Ŀ�״�����Ԫ����");
			print_Link(T);
		}
	}
	return 0;
}

/**/
//......................................................................................................
//Dinic�㷨//������
const ll Ni = 2e5 + 10;
struct Nod {
	ll to, next, w;//w������(Ȩֵ)
} edge[Ni]; //���
//from=x
ll num_n, num_m, s, t, u, num_v, num_w, counts = 1;
//s:Դ�ڵ������±�
//t:��ڵ������±�
//n:�ڵ�����
//m:�ߵ�����
//d[Ni]�������
int hea[Ni], maxflow, d[Ni], now[Ni];
void add_Net_Stream(int from, int to, int w)  {//��ʽ��ǰ����ӱ�
	edge[counts].to = to;
	edge[counts].next = hea[from];
	edge[counts].w = w;
	hea[from] = counts++;
}
int bfs() {
	queue<ll>q;
	memset(d, 0, sizeof(d));//��ʼ0
	while (!q.empty())q.pop();//���
	q.push(s), d[s] = 1, now[s] = hea[s];
	while (!q.empty()) {
		ll x = q.front();
		q.pop();//x�Ƕ�ͷԪ�أ�bfs��ʼ��λ��
		for (ll i = hea[x]; i; i = edge[i].next) {//i��ѡ����һ����������ʱ������һ��������(ͬһ���)
			ll v = edge[i].to;//v��Ϊedge[i]ͨ��Ľڵ������±�,to==v
			if (edge[i].w && !d[v]) {//��dvû��ֵ��w��Ϊ0ʱ
				d[v] = d[x] + 1;//��v���x����һ��
				q.push(v);//v���
				now[v] = hea[v];//
				if (v == t)return 1;
			}
		}
	}
	return 0;
}
ll dinic(ll x, ll flow) {
	if (x == t)return flow;//������˻�㣬����
	ll rest = flow, i, k;//restʣ����
	for (i = now[x]; i && rest; i = edge[i].next) {
		ll v = edge[i].to;
		if (edge[i].w && d[v] == d[x] + 1) {//w������v��x��һ��
			k = dinic(v, min(rest, edge[i].w));//�ݹ�����С������
			if (!k)d[v] = 0;//û�о�dv����
			edge[i].w -= k;//��ȥ����
			edge[i ^ 1].w += k;//
			rest -= k;
		}
	}
	now[x] = i;
	return flow - rest;//���ؿ��Լ�������ֵ
}
int Dinic_main() { //
	printf("�ڵ�����������Դ�㣬��� ��");
	scanf(" %lld%lld%lld%lld", &num_n, &num_m, &s, &t);
	for (ll i = 1; i <= num_m; i++) {
		printf("�ߵ���㣬�յ㣬���� ��");
		scanf_s(" %lld%lld%lld", &u, &num_v, &num_w), add_Net_Stream(u, num_v, num_w), add_Net_Stream(num_v, u, 0);
	}
	while (bfs())
		while (ll res = dinic(s, inf))
			maxflow += res;
	printf("��������Ϊ��%lld\n", maxflow);
	system("pause");
	return 0;
}
int buy_pig_main() {//����
	int rooms, buyers;//��Ȧ�������˿�����
	while (cin >> rooms >> buyers) {
		n = rooms * buyers + buyers + 2;//�ڵ�����
		int* num; int** key; int* bu;//num����ʼ��Ȧ�е�����//�洢�˿�ӵ�е�Կ��//�洢ÿ���˿�Ҫ���������
		num = new int[rooms + 1];//��ʼ��num//key//bu����
		key = new int* [buyers + 1];
		bu = new int[buyers + 1];
		for (int i = 1; i < buyers + 1; i++) {//��ʼ����ά����//ÿ���˿�ӵ�е�Կ��
			key[i] = new int[1000];//����ռ�
		}
		for (int i = 1; i <= rooms; i++) {
			cin >> num[i];//����ÿ����Ȧ��ʼ���������
		}
		for (int i = 1; i < buyers; i++) {//����key
			cin >> key[i][0];//�����i������ӵ��Կ�׵�����
			for (int j = 1; j < key[i][0]; j++) {//����ÿ��Կ�׶�Ӧ����Ȧ��
				cin >> key[i][j];
			}
			cin >> bu[i];//����ÿ���˿�Ҫ����������
		}
		s = 1; t = n; int i = 0;//s��Դ�㣬t�ǻ�㣬����������
		for (i = 2; i < rooms+2; i++) {//�Գ�ʼ��Ȧ���н���
			add_Net_Stream(1, i, num[i]), add_Net_Stream(i, 1, 0);
		}//i=M+1
		int w = i; int j = 0;//�洢��ʱ�������Ĵ�С
		for (i = 2; i <= rooms+1; i++) {//����w�����//ͨ��w��֪�ڶ�����Ȧ������ɺ�i��2M+1
			for (j = 1; j <= buyers; j++) {//������ͬ�˿�(ʱ��ͬ)��ͬһ��Ȧ֮��ı�//��1�ţ���2��...
				add_Net_Stream(i + j * rooms, i + rooms * (j - 1), 0), add_Net_Stream(i + (j - 1) * rooms, i + j * rooms, 100010);
			}//ͨ����ѧ�������㲻ͬʱ���ͬһ��Ȧ�Ľ���
		}
		for (i = rooms * buyers + 2; i <= rooms * buyers + 1 + buyers; i++)  {
			for (j = 1; j < key[i][0]; j++) {//����ѭ���ѹ˿��벻ͬʱ�����Ȧ����
				add_Net_Stream(key[i][j] + 1 + (i - rooms * buyers - 2) * rooms, i, 100010), add_Net_Stream(i, key[i][j] + 1 + (i - rooms * buyers - 2) * rooms, 0);
			}
		}
		j = 0;//��ʼ��B�ļ�����
		for (int i = n - 1; i > n - buyers - 1; i--) {
			add_Net_Stream(i, n, bu[j++]), add_Net_Stream(n, i, 0);//�����ӹ˿͵�Դ��ı�(�˿�Ҫ�����ͷ��)
		}
		for (int i = 0; i < rooms; i++) {

		}
		while (bfs())
			while (ll res = dinic(s, inf))
				maxflow += res;
		printf("���������Ϊ��%lld\n", maxflow);
		system("pause");
		return 0;
	}
}

//�������⣺
//�ڵ�����������Դ�㣬��� ��5 7 1 5
//�ߵ���㣬�յ㣬���� ��1 2 4
//�ߵ���㣬�յ㣬���� ��1 3 10
//�ߵ���㣬�յ㣬���� ��2 3 1000010
//�ߵ���㣬�յ㣬���� ��2 4 1000010
//�ߵ���㣬�յ㣬���� ��2 5 2
//�ߵ���㣬�յ㣬���� ��3 5 3
//�ߵ���㣬�յ㣬���� ��4 5 6
//��������Ϊ��11   ֻ��

//ţ�Ժ����⣺
//�ڵ�����������Դ�㣬��� ��16 25 1 16
//�ߵ���㣬�յ㣬���� ��1 10 1
//�ߵ���㣬�յ㣬���� ��1 11 1
//�ߵ���㣬�յ㣬���� ��1 12 1
//�ߵ���㣬�յ㣬���� ��10 2 100010
//�ߵ���㣬�յ㣬���� ��10 4 100010
//�ߵ���㣬�յ㣬���� ��10 5 100010
//�ߵ���㣬�յ㣬���� ��11 2 100010
//�ߵ���㣬�յ㣬���� ��11 3 100010
//�ߵ���㣬�յ㣬���� ��12 3 100010
//�ߵ���㣬�յ㣬���� ��12 4 100010
//�ߵ���㣬�յ㣬���� ��12 5 100010
//�ߵ���㣬�յ㣬���� ��2 6 1
//�ߵ���㣬�յ㣬���� ��3 7 1
//�ߵ���㣬�յ㣬���� ��4 8 1
//�ߵ���㣬�յ㣬���� ��5 9 1
//�ߵ���㣬�յ㣬���� ��6 13 100010
//�ߵ���㣬�յ㣬���� ��6 15 100010
//�ߵ���㣬�յ㣬���� ��7 13 100010
//�ߵ���㣬�յ㣬���� ��7 14 100010
//�ߵ���㣬�յ㣬���� ��8 13 100010
//�ߵ���㣬�յ㣬���� ��8 14 100010
//�ߵ���㣬�յ㣬���� ��9 15 100010
//�ߵ���㣬�յ㣬���� ��13 16 1
//�ߵ���㣬�յ㣬���� ��14 16 1
//�ߵ���㣬�յ㣬���� ��15 16 1
//��������Ϊ��3

