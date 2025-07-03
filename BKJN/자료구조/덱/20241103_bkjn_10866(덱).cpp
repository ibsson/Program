#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

typedef struct Node {
	Data data;
	struct Node* Pre;
	struct Node* Next;
}Node;

typedef struct LLDeque {
	Node* Head;
	Node* Tail;
}LLDeque;

void Create_Deque(LLDeque**);
int IsEmpty(LLDeque*);
void Push_Front(LLDeque*, Data);
Node* Create_Node(Data);
void Push_Back(LLDeque*, Data);
Data Pop_Front(LLDeque*);
Data Pop_Back(LLDeque*);
int Get_Size(LLDeque*);
void Print_Front(LLDeque*);
void Print_Back(LLDeque*);

int main(void) {

	int n = 0;

	scanf("%d", &n);
	getchar();
	
	char order[15] = { 0 };
	LLDeque* Deque = NULL;
	Create_Deque(&Deque);

	for (int i = 0; i < n; i++) {
		scanf("%s", order, 15);
		getchar();

		if (strcmp(order, "push_front") == 0) {
			Data X = 0;
			scanf("%d", &X);

			Push_Front(Deque, X);
		}
		else if (strcmp(order, "push_back") == 0) {
			Data X = 0;
			scanf("%d", &X);

			Push_Back(Deque, X);
		}
		else if (strcmp(order, "pop_front") == 0) {
			Data tmp = Pop_Front(Deque);
			printf("%d\n", tmp);
		}
		else if (strcmp(order, "pop_back") == 0) {
			Data tmp = Pop_Back(Deque);
			printf("%d\n", tmp);
		}
		else if (strcmp(order, "size") == 0) {
			int size = Get_Size(Deque);
			printf("%d\n", size);
		}
		else if (strcmp(order, "empty") == 0) {
			int check = IsEmpty(Deque);
			printf("%d\n", check);
		}
		else if (strcmp(order, "front") == 0) {
			Print_Front(Deque);
		}
		else if (strcmp(order, "back") == 0) {
			Print_Back(Deque);
		}
	}

	return 0;
}

void Create_Deque(LLDeque** Deque) {

	(*Deque) = (LLDeque*)malloc(sizeof(LLDeque));
	(*Deque)->Head = NULL;
	(*Deque)->Tail = NULL;
}

int IsEmpty(LLDeque* Deque) {

	if (Deque->Head == NULL) return 1;
	else return 0;
}

void Push_Front(LLDeque* Deque, Data X) {

	Node* NewNode = Create_Node(X);
	NewNode->Next = Deque->Head;

	if (IsEmpty(Deque) == 0) {
		Deque->Head->Pre = NewNode;
	}
	else {
		Deque->Tail = NewNode;
	}

	NewNode->Pre = NULL;
	Deque->Head = NewNode;
}

Node* Create_Node(Data data) {

	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->Pre = NULL;
	NewNode->Next = NULL;

	return NewNode;
}

void Push_Back(LLDeque* Deque, Data X) {

	Node* NewNode = Create_Node(X);
	NewNode->Pre = Deque->Tail;

	if (IsEmpty(Deque) == 0) {
		Deque->Tail->Next = NewNode;
	}
	else {
		Deque->Head = NewNode;
	}

	NewNode->Next = NULL;
	Deque->Tail = NewNode;
}

Data Pop_Front(LLDeque* Deque) {

	if (Deque->Head == NULL) {
		return -1;
	}
	else {
		Node* Popped = Deque->Head;
		Data tmp = Popped->data;

		Deque->Head = Deque->Head->Next;
		free(Popped);

		if (Deque->Head == NULL) {
			Deque->Tail = NULL;
		}
		else {
			Deque->Head->Pre = NULL;
		}

		return tmp;
	}
}

Data Pop_Back(LLDeque* Deque) {

	if (Deque->Tail == NULL) {
		return -1;
	}
	else {
		Node* Popped = Deque->Tail;
		Data tmp = Popped->data;

		Deque->Tail = Deque->Tail->Pre;
		free(Popped);

		if (Deque->Tail == NULL) {
			Deque->Head = NULL;
		}
		else {
			Deque->Tail->Next = NULL;
		}

		return tmp;
	}
}

int Get_Size(LLDeque* Deque) {

	Node* tmp = Deque->Head;
	int cnt = 0;
	while (tmp != NULL) {
		tmp = tmp->Next;
		cnt++;
	}

	return cnt;
}

void Print_Front(LLDeque* Deque) {

	if (Deque->Head == NULL) {
		printf("-1\n");
		return;
	}
	else printf("%d\n", Deque->Head->data);
}

void Print_Back(LLDeque* Deque) {

	if (Deque->Tail == NULL) {
		printf("-1\n");
		return;
	}
	else printf("%d\n", Deque->Tail->data);
}

/*
큐의 선입선출 특성과 스택의 선입 후출 특성을 모두 가지고 있는 덱에 대해서 공부할 수 있는 문제였다.
양방향 연결리스트를 사용해서 만들었다.
덱이 어떤 원리로 작동하는지 공부한 후 양방향 연결리스트로 나 스스로 만들어내서 좋았다.
스스로 만들어 냈기에 나중에 더 기억하기 좋을 것 같다.
덱에 대해서 이해할 수 있는 좋은 문제였다.
*/
