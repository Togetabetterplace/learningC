#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "windows.h"
#include<cmath>
#define M 10
#define N 10
using namespace std;
void manu() {

	system("mode con cols=99 lines=50");//���ô��ڴ�С
	system("color 70");//������ɫ
	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
	cout << "**************      1,��Ϸ     ***************" << endl;
	cout << "**************      2,�˳�     ***************" << endl;
	cout << "**************    3,��Ϸ����   ***************" << endl;
	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
}
void search_win(int arr[M + 2][N + 2], int acc[M][N], int i, int j) {
	int num;
	num = arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1] + arr[i][j - 1]
	      + arr[i + 1][j + 1] + arr[i - 1][j - 1] + arr[i + 1][j - 1] + arr[i - 1][j + 1];
	acc[i - 1][j - 1] = num;
	cout << "���������������ģ�" << endl;
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
		cout << "����|||����aiugufk % % wfhkfau eiui& @@@@@ fjh   hfi***hafihdiuhfiu ahfuih";
	}
	cout << endl;
	cout << "��Ϸ����" << endl;
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
	cout << "��Ҫ�����ף��t(*�㨌��*)�s" << endl;
	cin >> n;
	int r, c;
	for (int i = 0; i < n; i++) {
		r = rand() % 10;
		c = rand() % 10;
		arr[r][c] = 1;
	}
	cout << "�õģ�������������ˡ�" << endl;
	cout << "��ʼ��Ϸ��" << endl;
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
		cout << "��������ѡ��λ�á�(i,j)" << endl;
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
				cout << "ѡ�����������ѡ�񣺩d(?��?`)o" << endl;
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
				cout << "������Ϸ��O(��_��)O" << endl;
				game();
				break;
			case 2:
				printf("�˳���Ϸ��(�ѩn��)");
				printf("\n");
				order = 0;
				break;
			case 3:
				introduse();
				break;
			default:
				cout << "ѡ�����������ѡ��(�ѩn��)" << endl;
				break;
		}
	} while (order);
}
void introduse() {
	printf("ɨ��С��Ϸ�����������x��y������ʾ��Χ�˸������ڵ�����");
	printf("�������û��ը�Ļ���(��'v'��)\n");
	printf("ף�������죡��һ������Ϸ���ܶ๦�ܲ����ƣ���л���(������)��\n");
	printf("ϣ���Ժ������ϷԽ��Խ�á�(*/�أ�*)\n");

	printf("\n\n");
	test();
}


int main() {
	test();
}
