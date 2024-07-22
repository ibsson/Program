#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int Data;
    struct Node* NextNode;
} Node;

typedef struct LinkedQueue {
    Node* Front;
    Node* Rear;
    int Count;
} LinkedQueue;

void CreateQueue(LinkedQueue** Queue) {
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

Node* CreateNode(int NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    return NewNode;
}

void Push(LinkedQueue* Queue, Node* NewNode) {
    if (Queue->Front == NULL) {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
    }
    Queue->Count++;
}

int Pop(LinkedQueue* Queue) {
    if (Queue->Front == NULL) return -1;

    Node* Front = Queue->Front;
    if (Queue->Front->NextNode == NULL) {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else {
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--;

    int tmp = Front->Data;
    free(Front);

    return tmp;
}

int IsEmpty(LinkedQueue* Queue) {
    return (Queue->Front == NULL);
}

int main(void) {
    int N = 0;
    LinkedQueue* Queue;

    CreateQueue(&Queue);

    scanf("%d", &N);

    char A[6] = { 0 };
    int data = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", A, sizeof(A));

        if (strcmp(A, "push") == 0) {
            scanf("%d", &data);
            Node* node = CreateNode(data);
            Push(Queue, node);
        }
        else if (strcmp(A, "pop") == 0) {
            printf("%d\n", Pop(Queue));
        }
        else if (strcmp(A, "size") == 0) {
            printf("%d\n", Queue->Count);
        }
        else if (strcmp(A, "empty") == 0) {
            printf("%d\n", IsEmpty(Queue));
        }
        else if (strcmp(A, "front") == 0) {
            if (Queue->Front == NULL) printf("-1\n");
            else printf("%d\n", Queue->Front->Data);
        }
        else if (strcmp(A, "back") == 0) {
            if (Queue->Rear == NULL) printf("-1\n");
            else printf("%d\n", Queue->Rear->Data);
        }
    }

    return 0;
}

/*
이 문제는 링크드 큐로 구현했다.
문제에서 하라는 그대로 구현하려고 했고, 의도대로 잘 구현됐다.
큐의 기본 기능들에 대해서 상기시킬 수 있었던 큐의 기본 문제였다.
*/
