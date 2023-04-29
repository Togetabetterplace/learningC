#include <iostream>
#include <cstring>
using namespace std;
int maps[27][27], n;//�ڽӾ���
char str[26];//��¼����
int color[26];//��¼������ɫ��š�
void dfs(int x) {
	if (x == n)return;
	int cnt = 1, i, j;
	for (i = 1; cnt; i++) {
		int flag = 1;
		for (j = 0; j < n; j++) {
			if (maps[x][j] == 1 && color[j] == i) {//x��j���ŵ��Ѿ�����
				flag = 0;//i����+1
				break;
			}
		}
		if (flag) {//Ϳɫ���
			color[x] = i;
			dfs(x + 1);//����һ��������
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
				maps[a][b] = maps[b][a] = 1;//�ӱ�
			}
		}
		color[0] = 1;
		int res = 0;
		dfs(0);
		for (int i = 0; i < n; i++)if (res < color[i])res = color[i];
		if (res > 1)cout << res << " channels needed." << endl;
		else cout << res << " channel needed." << endl;//ע���Ϊ1ʱҪȥ��s
	}
	return 0;
}
