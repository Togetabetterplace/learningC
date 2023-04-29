#include <iostream>
#include <cstring>
using namespace std;
int maps[27][27], n;//邻接矩阵
char str[26];//记录输入
int color[26];//记录结点的颜色编号。
void dfs(int x) {
	if (x == n)return;
	int cnt = 1, i, j;
	for (i = 1; cnt; i++) {
		int flag = 1;
		for (j = 0; j < n; j++) {
			if (maps[x][j] == 1 && color[j] == i) {//x到j的信道已经用了
				flag = 0;//i继续+1
				break;
			}
		}
		if (flag) {//涂色完成
			color[x] = i;
			dfs(x + 1);//对下一个点搜素
			cnt = 0;
		}
	}
}
int main() {
	while (cin >> n && n != 0) {
		memset(maps, 0, sizeof(maps));
		memset(color, 0, sizeof(color));
		for (int i = 0; i < n; i++) {
			cin >> str;
			int a = str[0] - 'A';
			for (int j = 2; j < strlen(str); j++) {
				int b = str[j] - 'A';
				maps[a][b] = maps[b][a] = 1;//加边
			}
		}
		color[0] = 1;
		int res = 0;
		dfs(0);
		for (int i = 0; i < n; i++)if (res < color[i])res = color[i];
		if (res > 1)cout << res << " channels needed." << endl;
		else cout << res << " channel needed." << endl;//注意答案为1时要去掉s
	}
	return 0;
}
