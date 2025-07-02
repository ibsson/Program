#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
}Node;

typedef struct ArrayStack {
	int capacity;
	int top;
	Node* Nodes;
}ArrayStack;

void Create_Node(ArrayStack** Stack, int Capacity) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

	(*Stack)->top = -1;
}

void Push(ArrayStack* Stack, int Data) {

	Stack->top++;
	Stack->Nodes[Stack->top].data = Data;
}

void Destroy_Stack(ArrayStack* Stack) {
	
	free(Stack->Nodes);
	free(Stack);
}

int Get_Eyeable_Stick(ArrayStack* Stack) {

	int cnt = 1, tmp = 0;

	tmp = Stack->Nodes[Stack->top].data;

	Stack->top--;

	while (Stack->top != -1) {
		if (tmp < Stack->Nodes[Stack->top].data) {
			cnt++;
			tmp = Stack->Nodes[Stack->top].data;
		}

		Stack->top--;
	}

	return cnt;
}

int main(void) {

	int N = 0, tmp = 0, cnt = 0;
	ArrayStack* Stack = NULL;

	scanf("%d", &N);

	Create_Node(&Stack, N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		Push(Stack, tmp);
	}

	cnt = Get_Eyeable_Stick(Stack);

	printf("%d\n", cnt);

	Destroy_Stack(Stack);

	return 0;
}

/*
이 문제는 배열기반 스택을 처음으로 활용해서 풀어본 문제다.
이제 스택을 문제에 활용해보면서 익숙해지면 될 것 같다.
*/
