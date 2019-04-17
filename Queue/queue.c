#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define OVERFLOW 100
#define ERROR 101


typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;
} LinkQueue;

int EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	
	if (!s)
		exit(OVERFLOW);
	s->data = e;
	s->next=NULL;
	Q->rear->next = s;
	Q->rear = s;
	
	return OK;
}

int DeQueue(LinkQueue *Q, QElemType *e) {
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

int main(int argc, char* argv[])
{
	LinkQueue *myQueue;
	int i, *e;
	
	for (i=0; i < 10; i++){
		EnQueue(myQueue, i);
		printf("%d is in\n", i);
	}
	
	for (i=0; i < 10; i++) {
		DeQueue(myQueue, e);
		printf("%d is out\n", *e);
	}
}


