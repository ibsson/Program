#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
}Node;

typedef struct ArrayStack {
	int capacity;
	int top;
	Node* Nodes;
};

void Create_Node(ArrayStack** Stack, int Capacity) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->top = -1;
}

void Push(ArrayStack* Stack, int Data) {

	Stack->top++;
	Stack->Nodes[Stack->top].data = Data;
}

int Pop(ArrayStack* Stack) {

	int tmp = 0;

	tmp = Stack->Nodes[Stack->top].data;

	Stack->top--;

	return tmp;
}

void Destroy_Stack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}

int main(void) {

	int N = 0, num = 0;
	char* str = (char*)malloc(sizeof(char) * 6);
	ArrayStack* Stack = NULL;

	scanf("%d", &N);

	Create_Node(&Stack, N);

	for (int i = 0; i < N; i++) {
		scanf("%s", str, sizeof(str));

		if (strcmp(str, "push") == 0) {

			scanf("%d", &num);
			Push(Stack, num);

		}
		else if (strcmp(str, "top") == 0) {

			if (Stack->top == -1) printf("-1\n");
			else printf("%d\n", Stack->Nodes[Stack->top].data);

		}
		else if (strcmp(str, "size") == 0) {

			printf("%d\n", (Stack->top + 1));

		}
		else if (strcmp(str, "empty") == 0) {

			if (Stack->top == -1) printf("1\n");
			else printf("0\n");

		}
		else if (strcmp(str, "pop") == 0) {

			if (Stack->top == -1) printf("-1\n");
			else printf("%d\n", Pop(Stack));

		}

		for (int i = 0; i < sizeof(str); i++) {
			str[i] = 0;
		}
	}

	Destroy_Stack(Stack);

	return 0;
}

/*
이제 배열기반 스택에 필요한 함수들은 웬만하면 만들 수 있을 것 같다.
까먹지 않게 계속 복습하면서 리마인드 시켜야겠다.
*/
