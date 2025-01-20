#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int graph[1001][1001];
int visited[1001];

int N, M, V;

void DFS(int v);
void BFS();

int main(void) {

	cin >> N >> M >> V;

	int x = 0, y = 0;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	DFS(V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));

	BFS();

	return 0;
}

void DFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
		if (i == N) return;
	}

}

void BFS() {
	queue <int> q;
	q.push(V);

	while (!q.empty()) {
		int next = q.front();
		next = q.front();
		visited[next] = 1;
		cout << next << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[next][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}

	cout << "\n";
}

/*
#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int VElementType;

typedef struct Vertex {
	VElementType Data;
	int Visited;
	int Index;

	struct Vertex* Next;
	struct Edge* AdjacencyList;
}Vertex;


typedef struct Node {
	Vertex* A;
	struct Node* NextNode;
}Node;

typedef struct LinkedQueue {
	Node* Front;
	Node* Rear;
	int Count;
}LinkedQueue;

typedef struct Edge {
	int Weight;
	struct Edge* Next;
	Vertex* From;
	Vertex* Target;
}Edge;

typedef struct Graph {
	Vertex* Vertices;
	int VertexCount;
}Graph;

Graph* CreateGraph();
void DestroyGraph(Graph* G);

Vertex* CreateVertex(VElementType Data);
void DestroyVertex(Vertex* V);
Vertex* Find_Vertex(Graph* G, int data);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);

void DFS(Vertex* V);

void CreateQueue(LinkedQueue** Queue);
Node* CreateNode(Vertex* V);
void Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* Dequeue(LinkedQueue* Queue);
int IsEmpty(LinkedQueue* Queue);

void BFS(Vertex* V, LinkedQueue* Queue);


int main(void) {

	int N = 0, M = 0, V = 0;

	scanf_s("%d %d %d", &N, &M, &V);

	Graph* G = CreateGraph();

	for (int i = 1; i <= N; i++) {
		Vertex* V = CreateVertex(i);
		AddVertex(G, V);
	}	

	int tmp_1 = 0, tmp_2 = 0;

	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &tmp_1, &tmp_2);

		Vertex* V1 = Find_Vertex(G, tmp_1);
		Vertex* V2 = Find_Vertex(G, tmp_2);

		AddEdge(V1, CreateEdge(V1, V2, 0));
		AddEdge(V1, CreateEdge(V2, V1, 0));
	}

	DFS(Find_Vertex(G, V));

	LinkedQueue* Queue = NULL;
	CreateQueue(&Queue);
	BFS(Find_Vertex(G, V), Queue);

	return 0;
}

Graph* CreateGraph() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->Vertices = NULL;
	graph->VertexCount = 0;

	return graph;
}

void DestroyGraph(Graph* G) {

	while (G->Vertices != NULL) {
		Vertex* Vertices = G->Vertices->Next;
		DestroyVertex(G->Vertices);
		G->Vertices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(VElementType Data) {

	Vertex* V = (Vertex*)malloc(sizeof(Vertex));

	V->Data = Data;
	V->Next = NULL;
	V->AdjacencyList = NULL;
	V->Visited = NotVisited;
	V->Index = -1;

	return V;
}

void DestroyVertex(Vertex* V) {

	while (V->AdjacencyList != NULL) {
		Edge* Edge = V->AdjacencyList->Next;

		DestroyEdge(V->AdjacencyList);

		V->AdjacencyList = Edge;
	}

	free(V);
}

Vertex* Find_Vertex(Graph* G, int data) {

	Vertex* V = G->Vertices;

	while (V->Data != data) {
		V = V->Next;
	}

	return V;
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight) {

	Edge* E = (Edge*)malloc(sizeof(Edge));
	E->From = From;
	E->Target = Target;
	E->Next = NULL;
	E->Weight = Weight;

	return E;
}

void DestroyEdge(Edge* E) {
	free(E);
}

void AddVertex(Graph* G, Vertex* V) {

	Vertex* VertexList = G->Vertices;

	if (VertexList == NULL) {
		G->Vertices = V;
	}
	else {
		while (VertexList->Next != NULL) {
			VertexList = VertexList->Next;
		}

		VertexList->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E) {

	if (V->AdjacencyList == NULL) V->AdjacencyList = E;
	else {
		Edge* AdjacencyList = V->AdjacencyList;

		while (AdjacencyList->Next != NULL) {
			AdjacencyList = AdjacencyList->Next;
		}

		AdjacencyList->Next = E;
	}
}

void DFS(Vertex* V) {

	Edge* E = NULL;

	printf("%d ", V->Data);

	V->Visited = Visited;

	E = V->AdjacencyList;

	while (E != NULL) {
		if (E->Target != NULL && E->Target->Visited == NotVisited) DFS(E->Target);

		E = E->Next;
	}
}

void CreateQueue(LinkedQueue** Queue) {

	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
}

Node* CreateNode(Vertex* V) {

	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->A = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void Enqueue(LinkedQueue* Queue, Node* NewNode) {

	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}
}

Node* Dequeue(LinkedQueue* Queue) {

	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else {
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count--;

	return Front;
}

int IsEmpty(LinkedQueue* Queue) {
	return (Queue->Front == NULL);
}

void BFS(Vertex* V, LinkedQueue* Queue) {
	Edge* E = NULL;

	printf("%d ", V->Data);
	V->Visited = Visited;

	Enqueue(Queue, CreateNode(V));

	while (!IsEmpty(Queue)) {
		Node* Popped = Dequeue(Queue);
		V = Popped->A;
		E = V->AdjacencyList;

		while (E != NULL) {
			V = E->Target;

			if (V != NULL && V->Visited == NotVisited) {
				printf("%d ", V->Data);
				V->Visited = Visited;
				Enqueue(Queue, CreateNode(V));
			}

			E = E->Next;
		}
	}
}
*/
