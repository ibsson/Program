#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

int node_cnt = 0;

Node* Node_add(Node* now_Node, int i) {

    Node* new_Node = (Node*)malloc(sizeof(Node));

    new_Node->data = i;

    if (now_Node == NULL) {
        new_Node->next = new_Node;
    }
    else {
        new_Node->next = now_Node->next;
        now_Node->next = new_Node; //now_node의 정보가 바뀌면 now_node의 주소의 정보가 바뀌는 것이기 때문에 같은 주소를 공유하고 있던 new_Node의 정보도 같이 바뀐다.
    }

    return new_Node;
}

Node* Node_pop(Node* now_Node, int K, int* result) {

    Node* pre_Node = NULL;

    for (int i = 0; i < K; i++) {
        pre_Node = now_Node;
        now_Node = now_Node->next;
    }

    *result = now_Node->data;

    pre_Node->next = now_Node->next;

    return pre_Node;
}

int main(void) {

	int N = 0, K = 0, result = 0;

	scanf("%d %d", &N, &K);

    Node* now_Node = NULL;

    for (int i = 1; i <= N; i++) {
        now_Node = Node_add(now_Node, i);
    }

    printf("<");

    for (int i = 0; i < N; i++) {

        result = 0;

        now_Node = Node_pop(now_Node, K, &result);

        printf("%d", result);

        if (i == (N - 1)) {
            printf(">\n");
            break;
        }
        
        printf(", ");
    }

	return 0;
}
