#include <iostream>
#include <queue>
#define MAX 52
using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1 ,-1 };

struct Node {
	int y, x;
};

void BFS(int i, int j, int w, int h) {
	queue <Node> q;
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		int y = q.front().y, x = q.front().x;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int ny = y + dy[k], nx = x + dx[k];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (arr[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					BFS(i ,j, w, h);
					cnt++;
				}
			}
		}
		
		cout << cnt << '\n';

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = false;
			}
		}
	}

	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int island[51][51] = { 0 };
int visited[51][51] = { 0 };
int move_x[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int move_y[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef struct Node {
	int x;
	int y;
	struct Node* Next;
}Node;

typedef struct LinkedQueue {
	Node* Front;
	Node* Rear;
}LinkedQueue;

void BFS(int y, int x, int w, int h);
LinkedQueue* Create_Queue();
Node* Create_Node(int _y, int _x);
void Enqueue(LinkedQueue* Queue, Node* NewNode);
int Is_Empty(LinkedQueue* Queue);
Node* Dequeue(LinkedQueue* Queue);

int main(void) {

	int w = 0, h = 0;

	while (1) {
		int cnt = 0;

		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &island[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j] == 1 && visited[i][j] == 0) {
					BFS(i, j, w, h);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		memset(island, 0, sizeof(island));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}

void BFS(int y, int x, int w, int h) {

	visited[y][x] = 1;

	LinkedQueue* Queue = Create_Queue();

	Enqueue(Queue, Create_Node(y, x));

	while (Is_Empty(Queue) == 0) {
		Node* Popped = Dequeue(Queue);

		for (int i = 0; i < 8; i++) {
			int new_x = Popped->x + move_x[i];
			int new_y = Popped->y + move_y[i];

			if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h && island[new_y][new_x] == 1 && visited[new_y][new_x] == 0) {
				Enqueue(Queue, Create_Node(new_y, new_x));
				visited[new_y][new_x] = 1;
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

Node* Create_Node(int _y, int _x) {

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

/*
이 문제는 BFS를 이용해서 풀었다.
그냥 BFS의 기본 문제라서 한번에 쉽게 풀었다.
한 점에서 상하좌우, 대각선까지 모두 고려해서 문제를 푸는것이 관건이었다.
BFS문제의 감을 잃지 않도록 BFS문제도 계속 풀어봐야겠다.
*/
*/
