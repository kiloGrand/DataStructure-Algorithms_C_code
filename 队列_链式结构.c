//���е���ʽ�ṹ��β�����룬ͷ��ɾ��
#include <stdlib.h>
typedef int ElemType;
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode,*QueuePrt;
typedef struct {
	QueuePrt front, rear;//��ͷ��βָ��
}LinkQueue;

void initQueue(LinkQueue* q)//��ʼ������
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)	exit(0);
	q->front->next = NULL;
}

void InsertQueue(LinkQueue* q, ElemType e)//����Ԫ�ص�����
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (!p)	exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void DeleteQueue(LinkQueue* q, ElemType* e)//ɾ������Ԫ��
{
	QueuePrt p;
	if (q->front == q->rear)	return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)	q->rear = q->front;
	free(p);
}

void DestroyQueue(LinkQueue* q)//���ٶ���
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}