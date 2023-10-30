//원형 연결리스트

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node_s;

int main() {
    int N = 0;
	int K = 0;
	
    scanf("%d %d", &N, &K);

    // 연결 리스트 초기화
    Node_s* head = NULL;
    Node_s* tail = NULL;
	
    for (int i = 1; i <= N; i++) {
        Node_s* newNode = (Node_s*)malloc(sizeof(Node_s));
        newNode->data = i;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; // 원형 연결 리스트 생성

    printf("<");
	
    Node_s* current = head;
    Node_s* prev = NULL;
	
    while (N > 0) {
        int count = 1;
        while (count < K) {
            prev = current;
            current = current->next;
            count++;
        }
        if (prev != NULL) {
            printf("%d, ", current->data);
            prev->next = current->next;
        } else {
            printf("%d", current->data);
        }
        Node_s* temp = current;
        current = current->next;
        free(temp);
        N--;
    }
    printf(">\n");

    return 0;
}

//구조체, 동적할당

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	int next;
} node_s;

int cnt = 0;
int address_now = 0;
node_s* node;

int pop(int jump) {

	int address_previous = 0;

	for (int i = 0; i < jump; i++) {
		address_previous = address_now;
		address_now = node[address_now].next;
	}

	int return_value = node[address_now].data;

	node[address_previous].next = node[address_now].next;
	address_now = address_previous;

	return return_value;
}

int main() {

	scanf_s("%d", &cnt);

	node = (node_s*)malloc(sizeof(node_s) * cnt);

	for (int i = 0; i < cnt; i++) {
		node[i].data = i + 1;
		node[i].next = i + 1;
	}
	node[cnt - 1].next = 0;

	address_now = cnt - 1;

	int interval;
	scanf_s("%d", &interval);

	printf("<");
	for (int i = 0; i < cnt; i++) {
		printf("%d", pop(interval));
		if (i != cnt - 1)
			printf(", ");
	}
	printf(">");

	free(node);

	return 0;
}


//New solution

#include <stdio.h>

#define DATA_LEN_MAX 5000

int data[2][DATA_LEN_MAX];
int cnt = 0;
int address_now = 0;


int pop(int jump) {

	if (jump <= 0)
		return -1;

	int address_previous;

	for (int i = 0; i < jump; i++) {
		address_previous = address_now;
		address_now = data[1][address_now];
	}

	int return_value = data[0][address_now];

	data[1][address_previous] = data[1][address_now];
	address_now = address_previous;

	return return_value;
}

int main() {

	scanf("%d", &cnt);

	if (cnt < 1 || cnt >= DATA_LEN_MAX)
		cnt = DATA_LEN_MAX;

	for (int i = 0; i < cnt; i++) {
		data[0][i] = i + 1;
		data[1][i] = i + 1;
	}
	data[1][cnt - 1] = 0;

	address_now = cnt - 1;

	int interval;
	scanf("%d", &interval);

	printf("<");
	for (int i = 0; i < cnt; i++) {
		printf("%d", pop(interval));
		if (i != cnt - 1)
			printf(", ");
	}
	printf(">");

	return 0;
}


// Myself


#include <stdio.h>

int data[2][5000];
int now = 0;

int pop(int jump){
	
	int pre = 0;
	int result = 0;
	
	for(int i = 0; i < jump; i++){
		pre = now;
		now = data[1][now];
	}
	result = data[0][now];
	
	data[1][pre] = data[1][now];
	now = pre;
	
	return result;
}

int main(void){
	
	int N = 0;
	int K = 0;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		data[0][i] = i + 1;
		data[1][i] = i + 1;
	}
	data[1][N - 1] = 0;
	
	now = N - 1;
	
	scanf("%d", &K);
	
	printf("<");
	for(int i = 0; i < N; i++){
		printf("%d", pop(K));
		if(i != N - 1){
			printf(", ");
		}
	}
	printf(">\n");
	
	return 0;
}


// Old solution


#include <stdio.h>

int main(void) {

	int N = 0;
	int K = 0;
	int num[5001] = { 0 };
	int room[5001] = { 0 };

	for (int i = 1; i < sizeof(num) / sizeof(int); i++) {
		num[i] = i;
	}

	scanf("%d %d", &N, &K);

	int cnt = K;
	int tmp = 1;
	int a = 1;

	while (1) {
		for (int i = 0; i < K; i++) {

			if (tmp > N) {
				tmp = 1;
			}

			if (num[tmp] == 0) {
				while (1) {
					if (tmp > N) {
						tmp = 1;
					}
					if (num[tmp] != 0) break;
					tmp++;
				}
			}

			if (i + 1 == cnt) {
				num[tmp] = 0;
				room[a] = tmp;
				a++;
			}
			tmp++;
		}
		if (a == N + 1) break;
	}

	printf("<");

	for (int i = 1; i <= N; i++) {
		printf("%d", room[i]);
		if (i == N) break;
		printf(",");
		printf(" ");
	}

	printf(">");

	return 0;
}
