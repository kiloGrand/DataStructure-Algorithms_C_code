//循环队列的顺序存储结构
#include <stdlib.h>
#define MAXSIZE 100
typedef ElemType int;
typedef struct
{
	ElemType* base;	//数组存放地址
	int front;
	int rear;
}cycleQueue;

void inintQueue(cycleQueue* q)//队列的初始化
{
	q->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!q->base)	exit(0);
	q->front = q->rear = 0;
}

void InsertQueue(cycleQueue* q, ElemType e)//插入元素到队列
{
	if ((q->rear + 1) % MAXSIZE == q->front)	return;//队列已满
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

void DeleteQueue(cycleQueue* q, ElemType* e)//删除队列的元素
{
	if (q->front == q->rear)	return;//队列为空
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}