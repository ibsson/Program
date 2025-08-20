#include <iostream>
#include <stack>
using namespace std;

stack <int> s;
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	s.push(str[0]);

	for (int i = 1; i < str.length(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (str[i - 1] == ')') {
				s.pop();
				res++;
			}
			else if (str[i - 1] == '(') {
				s.pop();
				res += s.size();
			}
		}
	}

	cout << res << '\n';

	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int Data;
}Node;

typedef struct ArrayStack {
	int top;
	Node* Nodes;
}ArrayStack;

void Create_Node(ArrayStack**);
void Push(ArrayStack*, int);
void Pop(ArrayStack*);

int main(void) {

	char str[100001] = { 0 };

	scanf("%s", str, 100001);

	int cnt = 0;

	ArrayStack* Stack = NULL;
	Create_Node(&Stack);
	
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			cnt += (Stack->top) + 1;
			i++;
		}
		else if (str[i] == '(') {
			Push(Stack, i);
		}
		else if (str[i] == ')') {
			Pop(Stack);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}

void Create_Node(ArrayStack** Stack) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * 100001);
	(*Stack)->top = -1;
}

void Push(ArrayStack* Stack, int i) {

	Stack->top++;
	Stack->Nodes[Stack->top].Data = i;
}

void Pop(ArrayStack* Stack) {
	Stack->top--;
}

/*
이 문제를 풀면서 스택을 쓰면 좋겠다는 생각은 했지만 끝내 풀지 못했다.
검색을 해서 다른사람의 코드를 참고를 해서 풀었다.
레이저가 나오면 쌓인 파이프의 개수만큼 cnt에 더해주고, 파이프가 끝나면 해당하는 파이프만 빼준 후 cnt에 1을 더해준다.
이런 생각을 나 스스로 해낼 줄 알아야 하는데 아직 너무 부족하다. 더 노력해야겠다.
*/
*/
