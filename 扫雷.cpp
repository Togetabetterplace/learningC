#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "windows.h"
#include<cmath>
#define M 10
#define N 10
using namespace std;
void manu() {

	system("mode con cols=99 lines=50");//设置窗口大小
	system("color 70");//设置颜色
	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
	cout << "**************      1,游戏     ***************" << endl;
	cout << "**************      2,退出     ***************" << endl;
	cout << "**************    3,游戏介绍   ***************" << endl;
	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
}
void search_win(int arr[M + 2][N + 2], int acc[M][N], int i, int j) {
	int num;
	num = arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1] + arr[i][j - 1]
	      + arr[i + 1][j + 1] + arr[i - 1][j - 1] + arr[i + 1][j - 1] + arr[i - 1][j + 1];
	acc[i - 1][j - 1] = num;
	cout << "现在雷区是这样的：" << endl;
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			printf("%-1d\x20", acc[m][n]);
		}
		cout << endl;
	}

}
void introduse() ;

void fail() {
	for (int i = 0; i < 10000; i++) {
		cout << "】】|||】】aiugufk % % wfhkfau eiui& @@@@@ fjh   hfi***hafihdiuhfiu ahfuih";
	}
	cout << endl;
	cout << "游戏结束" << endl;
}
void game() {
	int n, arr[M + 2][N + 2] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	cout << "你要几个雷？╰(*°▽°*)╯" << endl;
	cin >> n;
	int r, c;
	for (int i = 0; i < n; i++) {
		r = rand() % 10;
		c = rand() % 10;
		arr[r][c] = 1;
	}
	cout << "好的，你的雷区做好了。" << endl;
	cout << "开始游戏。" << endl;
	int acc[M][N] = {
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
	};
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%-1d\x20", acc[i][j]);
		}
		printf("\n");
	}
	int i;
	int j;
	int flag = 1;
	do {
		cout << "请输入你选的位置。(i,j)" << endl;
		cin >> i >> j;
		switch (arr[i][j]) {
			case 0:

				search_win(arr, acc, i, j);
				break;
			case 1:
				fail();
				flag = 0;
				break;
			default:
				cout << "选择错误，请重新选择：ヾ(?ω?`)o" << endl;
				break;
		}

	} while ((i + 1) && flag);
}
void test () {

	int order;

	do {
		order = 0;
		manu();
		cin >> order;
		switch (order) {
			case 1:
				cout << "进入游戏。O(∩_∩)O" << endl;
				game();
				break;
			case 2:
				printf("退出游戏。(⊙﹏⊙)");
				printf("\n");
				order = 0;
				break;
			case 3:
				introduse();
				break;
			default:
				cout << "选择错误，请重新选择。(⊙﹏⊙)" << endl;
				break;
		}
	} while (order);
}
void introduse() {
	printf("扫雷小游戏，进入后输入x，y坐标显示周围八个格子内的雷数");
	printf("（如果你没被炸的话）(●'v'●)\n");
	printf("祝你玩得愉快！第一次做游戏，很多功能不完善，感谢理解(￣▽￣)”\n");
	printf("希望以后这个游戏越来越好。(*/ω＼*)\n");

	printf("\n\n");
	test();
}


int main() {
	test();
}
