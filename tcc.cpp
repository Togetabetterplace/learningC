#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 5
#define price 0.05
//������ļ۸�
int k = 1;//ȷ�����ڵ�λ�ã���ţ�
//������Ϣ
typedef struct {
	int hour;
	int min;
	int locat;
	string name;//���ƺ�
} INF;

//ջ
typedef struct {
	INF data[MAXSIZE];
	int top;
} SeqStack, * LinkStack;

//����
typedef struct node {
	INF data;
	struct node* next;
} QNode;
typedef struct {
	QNode* front, * rear;//ͷβ�ڵ�
} LQueue;

//��ʼ������
LQueue* Init_LQueue() {
	LQueue* q = new LQueue;
	QNode* p = new QNode;
	p->next = NULL;
	q->front = p;
	q->rear = p;//ͷβָ����ڵ�����
	return q;
}

//������
void enterline(LQueue* q, int hour, int min, string name) {
	QNode* p = new QNode;

	p->data.hour = hour;//�������нڵ�
	p->data.min = min;
	p->data.name = name;
	p->data.locat = k;

	p->next = NULL;
	q->rear->next = p;//�������
	q->rear = p;
	k++;
}

//�жϱ���Ƿ�Ϊ��
int EmptyLQue(LQueue* q) {
	if (q->front == q->rear)
		return 0;
	else
		return 1;
}

//����
QNode* outline(LQueue* q) {
	QNode* p;
	p = q->front->next;
	if (q->front->next == q->rear) {//��һ���ڵ�����
		q->rear = q->front;
		return p;
	} else
		q->front->next = p->next;//���ж���ڵ㣬ֱ����������
	p->next = NULL;
	return p;
}

//��ѯ�����Ϣ
void checkline(LQueue* q) {
	LQueue* p = new LQueue;//����ָ��
	p->front = q->front;
	p->rear = q->rear;
	cout << "�����Ϣ��" << endl;
	if (EmptyLQue(q) == 0)//�ж�ջ�Ƿ�Ϊ��
		cout << "����޳���" << endl;
	else {
		p->front = p->front->next;
		cout << "���ƺ�    ����ʱ��" << endl;
		while (p->front != NULL) {
			cout << p->front->data.hour << ":" <<
			     p->front->data.min << "         " << p->front->data.name << endl;
			p->front = p->front->next;
		}
	}
}

//��ʼ��ջ
LinkStack Init_SeqStack() {
	LinkStack s = new SeqStack;
	s->top = -1;
	return s;
}

//�ж�ջ�Ƿ�Ϊ��
int FullStack(LinkStack q) {
	if (q->top == MAXSIZE - 1)
		return 0;
	else
		return 1;
}

//��ջ����ͣ������
void enterpark(LinkStack &p, int hour, int min, string name) {//����ͣ����
	p->top++;
	p->data[p->top].hour = hour;
	p->data[p->top].min = min;
	p->data[p->top].name = name;
	p->data[p->top].locat = k;
	k++;
}

// ����ͣ����
int sumprice(int inhour, int inmin, int outhour, int outmin) {
	int sum;
	sum = ((outhour - inhour) * 60 + (outmin - inmin)) * price;

	return sum;
}

//��ջ
void outpark(LinkStack p, LQueue *l, string name, int hour, int min) {
	LinkStack supp;
	QNode* q;
	supp = Init_SeqStack();
	while (p->data[p->top].name != name) {//���ζԱ�ջ�ڵĳ��ƺ�
		supp->top++;
		supp->data[supp->top] = p->data[p->top];//�����������ĳ��ƺţ��Ƚ���ʱջ
		p->top--;
	}
	while (p->data[p->top].name == name) {
		cout << p->data[p->top].name << endl;//ֱ���ҵ�������Ŀ�공����ջ
		cout << "ͣ��ʱ�乲��" << (hour - p->data[p->top].hour) * 60 + min - p->data[p->top].min << "min" << endl;//����ʱ��
		cout << "ͣ����Ϊ" << sumprice(p->data[p->top].hour, p->data[p->top].min, hour, min) << "Ԫ" << endl << endl;//�����շ�
		p->top--;
		while (supp->top > -1) {//��ʱջ�ڵĳ���������ջ
			p->top++;
			p->data[p->top] = supp->data[supp->top];
			p->data[p->top].locat = p->top + 1;
			supp->top--;//ԭ�г�����Ϣ��ջ
		}
		if (EmptyLQue(l) == 1) {//�г��뿪��ͣ������ճ�λ��
			q = outline(l);
			p->top++;
			p->data[p->top].name = q->data.name;
			p->data[p->top].hour = hour;
			p->data[p->top].min = q->data.min;
			p->data[p->top].locat = p->top + 1;
			cout << "���ƺ�Ϊ" << p->data[p->top].name << "�ĳ����Ѵӱ������ͣ����" << endl << endl;
		}//�����еĳ���ջ��
	}
}

//��ѯͣ������Ϣ
void checkpark(LinkStack &s) {
	int i;
	i = s->top;//��ʱ��һ��ջͷ
	cout << "ʱ��        ���ƺ�        λ��" << endl;
	while (s->top > -1) {
		cout << s->data[s->top].hour << ":" << s->data[s->top].min << "        " << s->data[s->top].name << "          " << s->data[s->top].locat << endl;
		s->top--;
	}
	if (s->top == MAXSIZE - 1) {
		cout << "ͣ�������������ŶӵȺ�" << endl;
	} else {
		cout << "ͣ�����г�λ������ʻ��" << endl;
	}
	s->top = i;
}

int main() {
	LinkStack L;
	LQueue *l;
	L = Init_SeqStack();
	l = Init_LQueue();
	char i = '*';
	cout << "*************��ӭʹ��ͣ��������ϵͳ*************" << endl;
	cout << "**************1. ��������ͣ����*****************" << endl;
	cout << "**************2. �����뿪ͣ����*****************" << endl;
	cout << "**************3. �鿴ͣ�����ڳ�����Ϣ***********" << endl;
	cout << "**************4. �鿴����ϵȴ��ĳ�����Ϣ*******" << endl;
	cout << "**************5. �˳�***************************" << endl << endl << endl;
	while (i != '+') {
		cout << "		������ָ�" << endl;
		cin >> i;
		switch (i) {
			case '1': {
				string name;
				int hour, min;
				cout << "���복�ƺ��Լ�����ʱ��" << endl;
				cin >> name >> hour >> min;
				if (FullStack(L) == 0) {
					cout << "ͣ�����������������Ⱥ�" << endl << endl;
					enterline(l, hour, min, name);
				} else {
					enterpark(L, hour, min, name);
					cout << "�ѳɹ�����ͣ����" << endl << endl;
				}
				break;
			}
			case '2': {
				string name;
				int hour, min;
				cout << "�����뿪ͣ�����ĳ��ƺ���ʱ��" << endl;
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
				cout << "�����������������1��5:" << endl;
				break;
		}
	}
}
