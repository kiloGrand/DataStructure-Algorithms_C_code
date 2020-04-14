//ѭ�����е�˳��洢�ṹ
#include <stdlib.h>
#define MAXSIZE 100
typedef ElemType int;
typedef struct
{
	ElemType* base;	//�����ŵ�ַ
	int front;
	int rear;
}cycleQueue;

void inintQueue(cycleQueue* q)//���еĳ�ʼ��
{
	q->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!q->base)	exit(0);
	q->front = q->rear = 0;
}

void InsertQueue(cycleQueue* q, ElemType e)//����Ԫ�ص�����
{
	if ((q->rear + 1) % MAXSIZE == q->front)	return;//��������
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

void DeleteQueue(cycleQueue* q, ElemType* e)//ɾ�����е�Ԫ��
{
	if (q->front == q->rear)	return;//����Ϊ��
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}