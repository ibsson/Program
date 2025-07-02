#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char word;
}Node;

typedef struct ArrayStack {
	int Top;
	int Capacity;
	Node* Nodes;
}ArrayStack;

void CreateStack(ArrayStack** Stack) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * 100001);

	(*Stack)->Top = -1;
	(*Stack)->Capacity = 100001;
}

void DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}

void Push(ArrayStack* Stack, char str) {

	Stack->Top++;

	Stack->Nodes[Stack->Top].word = str;
}

char Pop(ArrayStack* Stack) {

	int Position = Stack->Top;

	Stack->Top--;

	return Stack->Nodes[Position].word;
}

int main(void) {
    int cnt = 0;
    ArrayStack* Stack = NULL;

    char* arr = (char*)malloc(sizeof(char) * 100001);
    char* str = (char*)malloc(sizeof(char) * 100001);

    fgets(arr, 100001, stdin);

    int len = strlen(arr);

    while (cnt < len) {
        int check = cnt;
        CreateStack(&Stack);

        while (cnt < len && arr[cnt] != ' ' && arr[cnt] != '<' && arr[cnt] != '\n') {
            Push(Stack, arr[cnt]);
            cnt++;
        }

        for (int i = check; i < cnt; i++) {
            str[i] = Pop(Stack);
        }

        DestroyStack(Stack);

        if (cnt < len && arr[cnt] == ' ') {
            str[cnt] = ' ';
            cnt++;
        }
        else if (cnt < len && arr[cnt] == '<') {
            while (cnt < len && arr[cnt] != '>') {
                str[cnt] = arr[cnt];
                cnt++;
            }

            str[cnt] = '>';

            cnt++;
        }
        else if (cnt < len && arr[cnt] == '\n') {
            str[cnt] = '\n';
            break;
        }
    }

    printf("%s", str);

    free(arr);
    free(str);

    return 0;
}

/*
보자마자 스택이 떠올라서 스택으로 풀었다.
1. 띄어쓰기 나올때까지 스택에 Push.
2. 띄어쓰기 나오면 str에 저장 후 다음 문자열로 진행

이 과정으로 진행하였다. 
처음엔 56번줄의 while문을 무한루프로 돌렸었는데 런타임에러가 나와서 배열 크기를 cnt가 넘지 않을때까지로 while문의 범위를 정해주니 풀렸다.
*/
