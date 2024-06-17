#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int Importance;
	int Index;
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

void Enqueue(CircleQueue* Queue, int data, int index) {

	int Position = Queue->Rear;

	if (Queue->Rear == Queue->Capacity) {
		Queue->Nodes[Position].Importance = data;
		Queue->Nodes[Position].Index = index;

		Queue->Rear = 0;
	}
	else {
		Queue->Nodes[Position].Importance = data;
		Queue->Nodes[Position].Index = index;

		Queue->Rear++;
	}
}

void Dequeue(CircleQueue* Queue) {

	if (Queue->Front == Queue->Capacity) {
		Queue->Front = 0;
	}
	else {
		Queue->Front++;
	}
}

int Check_Sequence(CircleQueue* Queue, int M) {

	int cnt = 0, result = 0;

	while (1) {
		int i = Queue->Front;
		int tmp = Queue->Nodes[Queue->Front].Importance;

		while (i != Queue->Rear) {
			if (tmp < Queue->Nodes[i].Importance) {
				Enqueue(Queue, tmp, Queue->Nodes[Queue->Front].Index);
				Dequeue(Queue);
				break;
			}

			if (i == Queue->Capacity) i = -1;

			i++;
		}

		if(i == Queue->Rear){
			if (M == Queue->Nodes[Queue->Front].Index) {
				cnt++;
				result = cnt;
				return result;
			}
			Dequeue(Queue);
			cnt++;
		}
	}
}

void Destroy_Queue(CircleQueue* Queue) {

	free(Queue->Nodes);
	free(Queue);
}

int main(void) {

	int T = 0, N = 0, M = 0, tmp = 0;
	CircleQueue* Queue = NULL;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		CreateQueue(&Queue, N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);

			Enqueue(Queue, tmp, j);
		}

		int result = Check_Sequence(Queue, M);

		printf("%d\n", result);

		Destroy_Queue(Queue);
	}

	return 0;
}

/*
문제 그대로 풀려고 했다.
처음에는 링크드 큐로 풀려고 했는데 잘 되지 않아서 순환큐로 바꿨다.
'나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다'
이 조건을 그대로 반영해서 구현했다.
Front와 뒤에 노드들을 비교해 가면서 중요도가 높은게 하나라도 있으면 Rear로 Enqueue, Front를 Dequeue 시키면서 구현했다.
그렇게 M이 출력되는 순서가 나오면 return 해서 순서를 출력한다.

처음에는 큐를 사용하면 쉬울 줄 알았다. 하지만 Enqueue, Dequeue하는 과정에서 전단과 후단의 index를 관리하는게 헷갈려서 조금 오래 걸렸다. 하지만 큐 자체를 이해하기에
굉장히 좋은 코드인 것 같다.
*/
