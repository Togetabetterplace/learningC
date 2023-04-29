#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 5
#define price 0.05
//方便更改价格
int k = 1;//确定车在的位置（编号）
//车辆信息
typedef struct {
	int hour;
	int min;
	int locat;
	string name;//车牌号
} INF;

//栈
typedef struct {
	INF data[MAXSIZE];
	int top;
} SeqStack, * LinkStack;

//队列
typedef struct node {
	INF data;
	struct node* next;
} QNode;
typedef struct {
	QNode* front, * rear;//头尾节点
} LQueue;

//初始化队列
LQueue* Init_LQueue() {
	LQueue* q = new LQueue;
	QNode* p = new QNode;
	p->next = NULL;
	q->front = p;
	q->rear = p;//头尾指针与节点链接
	return q;
}

//进入便道
void enterline(LQueue* q, int hour, int min, string name) {
	QNode* p = new QNode;

	p->data.hour = hour;//建立队列节点
	p->data.min = min;
	p->data.name = name;
	p->data.locat = k;

	p->next = NULL;
	q->rear->next = p;//插入队列
	q->rear = p;
	k++;
}

//判断便道是否为空
int EmptyLQue(LQueue* q) {
	if (q->front == q->rear)
		return 0;
	else
		return 1;
}

//出队
QNode* outline(LQueue* q) {
	QNode* p;
	p = q->front->next;
	if (q->front->next == q->rear) {//仅一个节点的情况
		q->rear = q->front;
		return p;
	} else
		q->front->next = p->next;//还有多个节点，直接跳过即可
	p->next = NULL;
	return p;
}

//查询便道信息
void checkline(LQueue* q) {
	LQueue* p = new LQueue;//工作指针
	p->front = q->front;
	p->rear = q->rear;
	cout << "便道信息：" << endl;
	if (EmptyLQue(q) == 0)//判断栈是否为空
		cout << "便道无车辆" << endl;
	else {
		p->front = p->front->next;
		cout << "车牌号    进入时间" << endl;
		while (p->front != NULL) {
			cout << p->front->data.hour << ":" <<
			     p->front->data.min << "         " << p->front->data.name << endl;
			p->front = p->front->next;
		}
	}
}

//初始化栈
LinkStack Init_SeqStack() {
	LinkStack s = new SeqStack;
	s->top = -1;
	return s;
}

//判断栈是否为空
int FullStack(LinkStack q) {
	if (q->top == MAXSIZE - 1)
		return 0;
	else
		return 1;
}

//入栈（入停车场）
void enterpark(LinkStack &p, int hour, int min, string name) {//进入停车场
	p->top++;
	p->data[p->top].hour = hour;
	p->data[p->top].min = min;
	p->data[p->top].name = name;
	p->data[p->top].locat = k;
	k++;
}

// 计算停车费
int sumprice(int inhour, int inmin, int outhour, int outmin) {
	int sum;
	sum = ((outhour - inhour) * 60 + (outmin - inmin)) * price;

	return sum;
}

//出栈
void outpark(LinkStack p, LQueue *l, string name, int hour, int min) {
	LinkStack supp;
	QNode* q;
	supp = Init_SeqStack();
	while (p->data[p->top].name != name) {//依次对比栈内的车牌号
		supp->top++;
		supp->data[supp->top] = p->data[p->top];//如果不是输入的车牌号，先进临时栈
		p->top--;
	}
	while (p->data[p->top].name == name) {
		cout << p->data[p->top].name << endl;//直到找到车辆后，目标车辆出栈
		cout << "停车时间共计" << (hour - p->data[p->top].hour) * 60 + min - p->data[p->top].min << "min" << endl;//计算时间
		cout << "停车费为" << sumprice(p->data[p->top].hour, p->data[p->top].min, hour, min) << "元" << endl << endl;//计算收费
		p->top--;
		while (supp->top > -1) {//临时栈内的车再依次入栈
			p->top++;
			p->data[p->top] = supp->data[supp->top];
			p->data[p->top].locat = p->top + 1;
			supp->top--;//原有车辆信息入栈
		}
		if (EmptyLQue(l) == 1) {//有车离开，停车场会空出位置
			q = outline(l);
			p->top++;
			p->data[p->top].name = q->data.name;
			p->data[p->top].hour = hour;
			p->data[p->top].min = q->data.min;
			p->data[p->top].locat = p->top + 1;
			cout << "车牌号为" << p->data[p->top].name << "的车辆已从便道进入停车场" << endl << endl;
		}//队列中的车入栈。
	}
}

//查询停车场信息
void checkpark(LinkStack &s) {
	int i;
	i = s->top;//临时存一下栈头
	cout << "时间        车牌号        位置" << endl;
	while (s->top > -1) {
		cout << s->data[s->top].hour << ":" << s->data[s->top].min << "        " << s->data[s->top].name << "          " << s->data[s->top].locat << endl;
		s->top--;
	}
	if (s->top == MAXSIZE - 1) {
		cout << "停车场已满，请排队等候" << endl;
	} else {
		cout << "停车场有车位，可以驶入" << endl;
	}
	s->top = i;
}

int main() {
	LinkStack L;
	LQueue *l;
	L = Init_SeqStack();
	l = Init_LQueue();
	char i = '*';
	cout << "*************欢迎使用停车场管理系统*************" << endl;
	cout << "**************1. 车辆进入停车场*****************" << endl;
	cout << "**************2. 车辆离开停车场*****************" << endl;
	cout << "**************3. 查看停车场内车辆信息***********" << endl;
	cout << "**************4. 查看便道上等待的车辆信息*******" << endl;
	cout << "**************5. 退出***************************" << endl << endl << endl;
	while (i != '+') {
		cout << "		请输入指令：" << endl;
		cin >> i;
		switch (i) {
			case '1': {
				string name;
				int hour, min;
				cout << "输入车牌号以及到达时间" << endl;
				cin >> name >> hour >> min;
				if (FullStack(L) == 0) {
					cout << "停车场已满，进入便道等候" << endl << endl;
					enterline(l, hour, min, name);
				} else {
					enterpark(L, hour, min, name);
					cout << "已成功进入停车场" << endl << endl;
				}
				break;
			}
			case '2': {
				string name;
				int hour, min;
				cout << "输入离开停车场的车牌号与时间" << endl;
				cin >> name >> hour >> min;
				outpark(L, l, name, hour, min);
				break;
			}
			case '3':
				checkpark(L);
				break;
			case '4':
				checkline(l);
				break;
			case '5':
				return 0;
			default:
				cout << "输入错误，请重新输入1—5:" << endl;
				break;
		}
	}
}
