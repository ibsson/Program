//인접리스트

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
	int Data;
	int Visited;

	struct Vertex* Next;
	struct Edge* AdjacencyList;
}Vertex;

typedef struct Graph {
	Vertex* Vertices;
}Graph;

typedef struct Edge {
	struct Edge* Next;
	Vertex* From;
	Vertex* Target;
}Edge;

Graph* Create_Graph() {

	Graph* Computer = (Graph*)malloc(sizeof(Graph));

	Computer->Vertices = NULL;

	return Computer;
}

Vertex* Create_Vertex(int data) {

	Vertex* V = (Vertex*)malloc(sizeof(Vertex));

	V->Data = data;
	V->Visited = 0;
	V->Next = NULL;
	V->AdjacencyList = NULL;

	return V;
}

void Add_Vertex(Graph* Computer, Vertex* V) {

	if (Computer->Vertices == NULL) {
		Computer->Vertices = V;
	}
	else {
		Vertex* VertexList = Computer->Vertices;

		while (VertexList->Next != NULL) {
			VertexList = VertexList->Next;
		}
		VertexList->Next = V;
	}
}

Vertex* Find_Vertex(Graph* Computer, int data) {

	Vertex* V = Computer->Vertices;

	while (V != NULL) {
		if (V->Data == data) break;

		V = V->Next;
	}

	return V;
}

Edge* Create_Edge(Vertex* from, Vertex* target) {

	Edge* E = (Edge*)malloc(sizeof(Edge));

	E->From = from;
	E->Target = target;
	E->Next = NULL;

	return E;
}

void Add_Edge(Vertex* V, Edge* E) {

	if (V->AdjacencyList == NULL) {
		V->AdjacencyList = E;
	}
	else {
		Edge* tmp = V->AdjacencyList;

		while (tmp->Next != NULL) {
			tmp = tmp->Next;
		}
		tmp->Next = E;
	}
}

void DFS(Vertex* V) {

	V->Visited++;
	Edge* E = V->AdjacencyList;

	while (E != NULL) {
		if (E->Target->Visited != 1) {
			DFS(E->Target);
		}

		E = E->Next;
	}
}

int Get_Result(Graph* Computer) {

	int cnt = 0;
	Vertex* V = Computer->Vertices;

	while (V != NULL) {
		if (V->Visited == 1) {
			cnt++;
		}

		V = V->Next;
	}

	return cnt;
}

int main(void) {

	int T = 0, N = 0;

	scanf("%d", &T);

	Graph* Computer = Create_Graph();

	for (int i = 1; i <= T; i++) {
		Add_Vertex(Computer, Create_Vertex(i)); //그래프에 정점 추가
	}

	scanf("%d", &N);

	int From = 0, Target = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &From, &Target);

		Vertex* V1 = Find_Vertex(Computer, From);
		Vertex* V2 = Find_Vertex(Computer, Target);

		Add_Edge(V1, Create_Edge(V1, V2)); //그래프의 정점에 인접한 정점들 추가
		Add_Edge(V2, Create_Edge(V2, V1));
	}

	DFS(Computer->Vertices);

	printf("%d\n", Get_Result(Computer) - 1);

	return 0;
}

/*
인접행렬을 이용해서 만든 코드를 인접리스트를 이용해 만들어보았다.
인접행렬보다 인접리스트를 만드는게 훨씬 어렵고 시간도 많이 걸렸다.
처음엔 이해가 하나도 안돼서 접근조차 못했지만, 계속해서 읽어보고 분석해보다 보니 각 구조체들의 역할을 이해할 수 있었고 함수들을 어떻게 작성해나가야 할지 알게되었다.
인접행렬과 인접리스트의 차이와 특징을 알 수 있었고, 어떻게 써야하는지도 알 수 있었다.
인접리스트를 만드는데 정말 오래 걸렸다. 하지만 이번에 처음 구현해보았다.
앞으로 많이 만들어보고 사용해서 숙련도를 높여야겠다.
DFS 뿐만 아니라 BFS로도 만들어봐야겠다.
*/

//인접행렬

#include <stdio.h>
#include <stdlib.h>

void Make_Matrix(int** Computer, int y, int x) {

	Computer[y - 1][x - 1] = 1;
	Computer[x - 1][y - 1] = 1;
}

void dfs(int** Computer, int y, int T, int* Visited) {

	Visited[y] = 1;

	for (int i = 0; i < T; i++) {
		if (Computer[y][i] == 1 && Visited[i] != 1) {
			dfs(Computer, i, T, Visited);
		}
	}
}

int main(void) {

	int T = 0, N = 0;

	scanf("%d", &T);

	int** Computer = (int**)malloc(sizeof(int**) * T);
	for (int i = 0; i < T; i++) {
		Computer[i] = (int*)malloc(sizeof(int*) * T);
	}

	int* Visited = (int*)malloc(sizeof(int*) * T);

	scanf("%d", &N);

	int num1 = 0, num2 = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &num1, &num2);

		Make_Matrix(Computer, num1, num2);
	}

	dfs(Computer, 0, T, Visited);

	int cnt = 0;

	for (int i = 1; i < T; i++) {
		if (Visited[i] == 1) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 0; i < T; i++) {
		free(Computer[i]);
	}
	free(Computer);

	return 0;
}

/*
이 코드는 인접행렬과 dfs를 이용해서 풀려고 했다.
접근 방식은

1. 인접행렬을 만든다.
2. dfs로 모든 노드를 검사를 하고 이미 간 노드는 표시를 해놓는다.

이렇게 풀려고 했는데 그래도 잘 구현 된 것 같다.
시간이 굉장히 오래 걸렸는데, 계속해서 dfs 문제를 풀어보다 보면 빨라질것이라고 생각한다.
인접행렬을 이용하는게 처음이라 익숙치가 않았는데 인접행렬을 어떤식으로 이용해야 하는지 조금은 이해가 되었다.
인접행렬과 dfs를 한꺼번에 활용해서 푸는게 쉽지만은 않았다. 
하지만 이런 문제를 어떤식으로 접근하는지 조금은 알게 되었으니 앞으로 이런 문제를 보았을때 방향성을 쉽게 잡을 수 있을 것 같다.
이 문제를 인접리스트로도 풀어봐야겠다.
*/
