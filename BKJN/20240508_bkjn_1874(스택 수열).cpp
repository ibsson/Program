#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
}Node;

typedef struct ArrayStack {
	int capacity;
	int top;
	Node* Nodes;
};

void Create_Stack(ArrayStack** Stack, int Capacity) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->top = -1;
}

void Push(ArrayStack* Stack, int Data) {

	Stack->top++;
	Stack->Nodes[Stack->top].data = Data;
}

void Pop(ArrayStack* Stack) {

	Stack->top--;
}

void Destroy_Stack(ArrayStack* Stack) {

	free(Stack->Nodes);
	free(Stack);
}

int Check_Progression(ArrayStack* Stack, int n, int* num, char* arr) {

	int cnt = 0, i = 1, k = 0;

	while (n != cnt) {
		if (Stack->Nodes[Stack->top].data == num[cnt]) {
			Pop(Stack);

			arr[k] = 45;

			cnt++;
			k++;

			continue;
		}
		else {
			if (i > n) break;

			Push(Stack, i);

			arr[k] = 43;

			k++;
			i++;
		}
	}

	if (cnt == n) return 1;
	else return 0;
}

int main(void) {

	int n = 0, check = 0;

	ArrayStack* Stack = NULL;

	scanf("%d", &n);

	int* num = (int*)malloc(sizeof(int) * n);
	char* arr = (char*)malloc(sizeof(int) * n * 2);

	Create_Stack(&Stack, n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	check = Check_Progression(Stack, n, num, arr);

	if (check == 0) printf("NO\n");
	else if (check == 1) {
		for (int i = 0; i < n * 2; i++) {
			printf("%c\n", arr[i]);
		}
	}

	Destroy_Stack(Stack);

	return 0;
}

/*
한번에 풀어내서 기분이 좋다.
NO가 출력되는 조건을 찾기 힘들었는데, i가 n을 넘겼는데도 같은 수가 나오지 않으면 그 수열은 나올 수가 없다는 규칙을 찾아내서 쉽게 풀 수 있었다.
이제 어느정도 스택을 자유자재로 사용할 수 있을 것 같다. 이제 큐도 공부를 해야겠다.
*/
