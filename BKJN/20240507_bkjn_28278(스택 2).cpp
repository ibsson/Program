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

void Create_Stack(ArrayStack** Stack, int Capacity) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->capacity = Capacity;
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

	int N = 0, num = 0, data = 0;
	ArrayStack* Stack = NULL;

	scanf("%d", &N);

	Create_Stack(&Stack, (N + 1));

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		if (num == 1) {
			scanf("%d", &data);
			Push(Stack, data);
		}
		else if (num == 2) {

			if (Stack->top == -1) {
				printf("-1\n");
				continue;
			}

			printf("%d\n", Pop(Stack));
		}
		else if (num == 3) {
			printf("%d\n", (Stack->top + 1));
		}
		else if (num == 4) {
			if (Stack->top == -1) printf("1\n");
			else printf("0\n");
		}
		else if (num == 5) {
			if (Stack->top != -1) printf("%d\n", Stack->Nodes[Stack->top].data);
			else if (Stack->top == -1) printf("-1\n");
		}
	}

	Destroy_Stack(Stack);

	return 0;
}

/*
어제 푼 문제랑 비슷한 문제다. 그냥 스택 구현하는 방법을 알면 풀 수 있는 문제다.
이제 어느정도 스택을 구현하는 것은 익숙해진 것 같다.
앞으로 계속 복습해서 까먹지 않도록 해야겠다.
*/
