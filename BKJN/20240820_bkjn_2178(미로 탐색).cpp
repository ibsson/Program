#include <stdio.h>
#include <stdlib.h>

char maze[102][102] = { 0 };
int visited[102][102] = { 0 };
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, -1, 0,1 };

typedef struct Node {
	int x;
	int y;
	struct Node* Next;
}Node;

typedef struct LinkedQueue {
	Node* Front;
	Node* Rear;
}LinkedQueue;

void BFS(int x, int y, int N, int M);
LinkedQueue* Create_Queue();
Node* Create_Node(int _x, int _y);
void Enqueue(LinkedQueue* Queue, Node* NewNode);
int Is_Empty(LinkedQueue* Queue);
Node* Dequeue(LinkedQueue* Queue);

int main(void) {

	int N = 0, M = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", &maze[i], 102);
	}

	BFS(0, 0, N, M);

	printf("%d\n", visited[N - 1][M - 1]);

	return 0;
}

void BFS(int x, int y, int N, int M) {

	LinkedQueue* Queue = Create_Queue();

	Enqueue(Queue, Create_Node(x, y));
	visited[y][x] = 1;

	while (Is_Empty(Queue) == 0) {
		Node* Popped = Dequeue(Queue);

		for (int i = 0; i < 4; i++) {
			int new_x = Popped->x + x_move[i];
			int new_y = Popped->y + y_move[i];

			if (maze[new_y][new_x] == '1' && visited[new_y][new_x] == 0 && new_x >= 0 && new_y >= 0 && new_x < M && new_y < N) {
				Enqueue(Queue, Create_Node(new_x, new_y));
				visited[new_y][new_x] = visited[Popped->y][Popped->x] + 1;
			}
		}
	}
}

LinkedQueue* Create_Queue() {

	LinkedQueue* Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	Queue->Front = NULL;
	Queue->Rear = NULL;

	return Queue;
}

Node* Create_Node(int _x, int _y) {

	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->x = _x;
	NewNode->y = _y;
	NewNode->Next = NULL;

	return NewNode;
}

void Enqueue(LinkedQueue* Queue, Node* NewNode) {

	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else {
		Queue->Rear->Next = NewNode;
		Queue->Rear = NewNode;
	}
}

int Is_Empty(LinkedQueue* Queue) {

	if (Queue->Front == NULL) return 1;
	else return 0;
}

Node* Dequeue(LinkedQueue* Queue) {

	Node* tmp = Queue->Front;

	Queue->Front = Queue->Front->Next;

	return tmp;
}
