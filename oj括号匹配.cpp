#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	char name;
} Node;
typedef struct Stack {
	Node *elem;
	int top;
} Stack;
void Push(Stack &S, char ch) {
	S.elem[S.top].name = ch;
	S.elem[S.top].data = S.top;
	S.top++;
}
typedef struct arr {
	int x;
	int y;
} arr;
arr X[1000000];
void Pop(Stack &S, char &ch, int &data) {
	ch = S.elem[S.top - 1].name;
	data = S.elem[S.top - 1].data;
	S.top--;
}
int main() {
	Stack S;
	char ch;
	int data;
	for (int i = 0; i < 100; i++) {
		X[i].x = 0;
		X[i].y = 0;
	}
	S.elem = (Node*)malloc(1000000 * sizeof(Node));
	S.top = 0;
	do{
		ch = getchar();
		Push(S, ch);
	}while(ch != '\n');
	while (S.top != 0) {
		Pop(S, ch, data);
		if (ch == ')') {
			int i, j = 0;
			for (j = i = S.top; j != (S.top - 1); i--) {
				if (S.elem[i].name == '(')j--;
				else j++;
			}
			X[S.top].x = S.top;
			X[S.top].y = i;
		}
	}
	for (int i = 0; X[i].x != 0 && X[i].y != 0; i++) {
		cout << X[i].x << " " << X[i].y << endl;
	}
}
