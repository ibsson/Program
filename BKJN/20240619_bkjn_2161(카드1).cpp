#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int Data;
}Node;

typedef struct CircleQueue {
	int Front;
	int Rear;
	int Capacity;

	Node* Nodes;
}CircleQueue;

void CreateQueue(CircleQueue** Queue, int capacity) {

	(*Queue) = (CircleQueue*)malloc(sizeof(CircleQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (capacity + 1));

	(*Queue)->Capacity = capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void Enqueue(CircleQueue* Queue, int data) {

	int Position = Queue->Rear;

	if (Queue->Rear == Queue->Capacity) {
		Queue->Nodes[Position].Data = data;
		Queue->Rear = 0;
	}
	else {
		Queue->Nodes[Position].Data = data;
		Queue->Rear++;
	}
}

int Dequeue_Connect(CircleQueue* Queue) {

	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity) {
		Queue->Front = 0;

		if (Queue->Front == Queue->Rear) return Queue->Nodes[Position].Data;

		Enqueue(Queue, Queue->Nodes[Queue->Front].Data);

		Queue->Front++;
		
		return Queue->Nodes[Position].Data;
	}
	else {
		Queue->Front++;

		if (Queue->Front == Queue->Rear) return Queue->Nodes[Position].Data;

		Enqueue(Queue, Queue->Nodes[Queue->Front].Data);

		if (Queue->Front == Queue->Capacity) Queue->Front = 0;
		else Queue->Front++;
		
		return Queue->Nodes[Position].Data;
	}
}

void Get_Result(CircleQueue* Queue, int N) {

	int i = 0;
	int* result = (int*)malloc(sizeof(int) * N);

	while (Queue->Front != Queue->Rear) {
		int tmp = Dequeue_Connect(Queue);

		result[i] = tmp;

		i++;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

int main(void) {

	int N = 0;
	CircleQueue* Queue = NULL;

	scanf("%d", &N);

	CreateQueue(&Queue, N);

	for (int i = 1; i <= N; i++) {
		Enqueue(Queue, i);
	}

	Get_Result(Queue, N);

	return 0;
}

/*
보자마자 큐 문제라고 생각했다.
이 문제는 그냥 문제 그대로 구현하려고 했다. 전단 dequeue후, 전단을 후단에 연결하는 방식 그대로 했다.
순환 큐 문제는 전단과 후단 인덱스들이 배열 끝에 도달 했을 때 관리만 잘 해주면 쉽게 풀 수 있을 것 같다.
*/
