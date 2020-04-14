//队列的链式结构，尾部插入，头部删除
#include <stdlib.h>
typedef int ElemType;
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode,*QueuePrt;
typedef struct {
	QueuePrt front, rear;//队头，尾指针
}LinkQueue;

void initQueue(LinkQueue* q)//初始化队列
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)	exit(0);
	q->front->next = NULL;
}

void InsertQueue(LinkQueue* q, ElemType e)//插入元素到队列
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (!p)	exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void DeleteQueue(LinkQueue* q, ElemType* e)//删除队列元素
{
	QueuePrt p;
	if (q->front == q->rear)	return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)	q->rear = q->front;
	free(p);
}

void DestroyQueue(LinkQueue* q)//销毁队列
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}