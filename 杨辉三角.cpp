#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAXSIZE 1000000 //队列的最大长度
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];//队列的存储空间
	int front, rear; //队列的队头指针和队尾指针
} CyQueue;

void Init_CyQueue(CyQueue *Q) {
	Q->front = Q->rear = 0;
}

int Empty_CyQueue(CyQueue *Q) {
	return Q->rear == Q->front;
}

void Out_CyQueue(CyQueue *Q, int *e) {

	if (Q->rear == Q->front) {
		return;
	}
	*e = Q->data[Q->front];
	Q->front ++;
}
void In_CyQueue(CyQueue *Q, int e) { //数据 e 进队列
	if (Q->rear == MAXSIZE) {
		return;
	}
	Q->data[Q->rear] = e;
	Q->rear ++;
}

void Front_CyQueue(CyQueue * Q, ElemType *x) {
	if (Empty_CyQueue(Q)) {
		return;
	} else {
		*x = Q->data[Q->front];
	}
}

void yanghuisanjiao(int n) { //杨辉三角实现函数
	CyQueue Q;
	int i, s, e, k;
	for (i = 1; i <= n; i++) {
		printf("   ");
	}
	printf("%-5d\n", 1);

	Init_CyQueue(&Q);
	In_CyQueue(&Q, 0);
	In_CyQueue(&Q, 1);
	In_CyQueue(&Q, 1);
	k = 1;
	while (k < n) {

		for (i = 1; i <= n - k; i++) {
			printf("   ");
		}

		In_CyQueue(&Q, 0);
		do {
			//队头元素出队列
			Out_CyQueue(&Q, &s);
			//取新的队头元素
			Front_CyQueue(&Q, &e);

			if (e) {
				printf("%-5d", e);
			} else {
				printf(" \n");
			}
			In_CyQueue(&Q, s + e);
		} while (e != 0); //一旦 e 值为 0，即做转行操作，退出循环，开始新一行的排列
		k++;
	}

	Out_CyQueue(&Q, &e);
	while (!Empty_CyQueue(&Q)) {
		Out_CyQueue(&Q, &e); 
		printf("%-5d", e); 
	}
}
int main() {
	int n;
	cin >> n;
	yanghuisanjiao(n);
	return 0;
}
