#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char Data;
}Node;

typedef struct ArrayStack {
	int top;
	Node* Nodes;
}ArrayStack;

void Create_Node(ArrayStack**, int);
void Push(ArrayStack*, char);
char Pop(ArrayStack*);
void Operate_L(ArrayStack*, ArrayStack*);
void Operate_D(ArrayStack*, ArrayStack*);
void Operate_B(ArrayStack*);
void Operate_P(ArrayStack*, char);
void Print_Stack(ArrayStack*, ArrayStack*);

int main(void) {

	ArrayStack *LeftStack = NULL;
	ArrayStack* RightStack = NULL;

	Create_Node(&LeftStack, 600001);
	Create_Node(&RightStack, 600001);

	char str[100001] = { 0 };
	scanf("%s", str, 100001);
	getchar();

	for (int i = 0; i < strlen(str); i++) {
		Push(LeftStack, str[i]);
	}

	int M = 0;
	scanf("%d", &M);
	getchar();

	char order = 0;

	for (int i = 0; i < M; i++) {
		scanf("%c", &order, 1);
		getchar();

		switch (order) {
		case'L':
			Operate_L(LeftStack, RightStack);
			break;
		case'D':
			Operate_D(LeftStack, RightStack);
			break;
		case'B':
			Operate_B(LeftStack);
			break;
		case'P':
			char word = 0;
			scanf("%c", &word, 1);
			getchar();

			Operate_P(LeftStack, word);
			break;
		}
	}

	Print_Stack(LeftStack, RightStack);

	return 0;
}

void Create_Node(ArrayStack** Stack, int capacity) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity);

	(*Stack)->top = -1;
}

void Push(ArrayStack* Stack, char data) {

	Stack->top++;
	Stack->Nodes[Stack->top].Data = data;
}

char Pop(ArrayStack* Stack) {

	char tmp = Stack->Nodes[Stack->top].Data;
	Stack->top--;

	return tmp;
}

void Operate_L(ArrayStack* LeftStack, ArrayStack* RightStack) {

	if (LeftStack->top != -1) {
		char tmp = Pop(LeftStack);
		Push(RightStack, tmp);
	}
}

void Operate_D(ArrayStack* LeftStack, ArrayStack* RightStack) {

	if (RightStack->top != -1) {
		char tmp = Pop(RightStack);
		Push(LeftStack, tmp);
	}
}

void Operate_B(ArrayStack* LeftStack) {

	if (LeftStack->top != -1) {
		char tmp = Pop(LeftStack);
	}
}

void Operate_P(ArrayStack* LeftStack, char New_Word) {

	Push(LeftStack, New_Word);
}

void Print_Stack(ArrayStack* LeftStack, ArrayStack* RightStack) {

	while (LeftStack->top != -1) {
		char tmp_1 = Pop(LeftStack);
		Push(RightStack, tmp_1);
	}

	while (RightStack->top != -1) {
		char tmp_2 = Pop(RightStack);
		printf("%c", tmp_2);
	}
	printf("\n");
}

/*
링크드리스트로 풀다가 너무 어려워서 다른사람의 코드를 참고했다.
커서 위치를 기준으로 스택을 두개 만든 후 스택을 이용해서 명령을 수행하는 코드다.
스택의 활용에 대해서 깊이 이해할 수 있던 문제였다.
그리고 마지막에 크기설정을 잘못 해서 시간이 엄청 걸렸는데 매번 다짐하지만 문제에서 주어진 크기 조건을 잘 확인하고 풀어야겠다.
*/
