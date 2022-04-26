#include <stdio.h>
#include <stdlib.h>
// Queue FIFO - First In First Out
struct Queue
{
	int Size;
	int Front;
	int Rear;
	int* Q;
};
void Create(struct Queue* Q, int Size)
{
	Q->Size = Size;
	Q->Front = Q->Rear = -1;
	Q->Q = (int*)malloc(Q->Size * sizeof(int));
}
void Enqueue(struct Queue* Q, int x)
{
	if (Q->Rear == Q->Size - 1)
		printf("Queue is Full");
	else
	{
		Q->Rear++;
		Q->Q[Q->Rear] = x;
	}
}
int Dequeue(struct Queue* Q)
{
	int x = -1;

	if (Q->Front == Q->Rear)
		printf("Queue is Empty\n");
	else
	{
		Q->Front++;
		x = Q->Q[Q->Front];
	}
	return x;
}
void Display(struct Queue Q)
{
	int i;

	for (i = Q.Front + 1; i <= Q.Rear; i++)
		printf("%d ", Q.Q[i]);

	printf("\n");
}
int main()
{
	struct Queue q;
	Create(&q, 5);

	Enqueue(&q, 10);
	Enqueue(&q, 20);
	Enqueue(&q, 30);
	Display(q);

	printf("%d ", Dequeue(&q));
	return 0;
}
