#include <iostream>
#include <cstring>
using namespace std;
int n;
int mapp[26][26];//��¼����
char str[26];//��¼ÿ������
int color[26];//��¼ÿ������Ӧ����ɫ��š�
void dfs(int d)
{
	if (d == n)
		return;
	int cont = 1; //��ֹͿɫ�ı���
	int i, j;
	for (i = 1; cont; i++)   //�ڶ���d��������ɫ1��ʼͿ��,��ɫ�����i��ʾ
	{
		int flag = 1;
		for (j = 0; j < n; j++)
		{
			if (mapp[d][j] == 1 && color[j] == i)   //�������ڽ��Ϳ��һ������ɫi,����������ѭ����ΪdͿ��һ����ɫ����ɫ���+1
			{
				flag = 0;
				break;
			}
		}
		if (flag)   //˵��û�����ڽ��Ϳ��ͬ��ɫ
		{
			color[d] = i;
			dfs(d + 1);
			cont = 0; //d����ֹͿɫ
		}
	}
}
int main()
{
	while (cin >> n && n >= 1)
	{
		//ÿ���¿�ʼʱҪ���ԭ������
		memset(mapp, 0, sizeof(mapp));
		memset(color, 0, sizeof(color));
		//����n������
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int a = str[0] - 'A';
			//��������Ϣͳ����map��
			for (int j = 2; j < strlen(str); j++)
			{
				int b = str[j] - 'A';
				mapp[a][b] = mapp[b][a] = 1;
			}
		}
		color[0] = 1;
		int res = 0; //���
		//�ӵ�һ���㿪ʼ����
		dfs(0);
		for (int i = 0; i < n; i++)res = max(res, color[i]);
		if (res > 1)cout << res << " channels needed." << endl;
		else cout << res << " channel needed." << endl;
	}
	return 0;
}



















