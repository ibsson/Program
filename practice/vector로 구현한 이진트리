#include <iostream>
#include <vector>
using namespace std;

#define MAX 26

struct Node {
	char Left;
	char Right;
};

vector <Node> v(MAX);

void PreOrder(char data) {
	if (data == '.') return;

	cout << data;
	PreOrder(v[data - 'A'].Left);
	PreOrder(v[data - 'A'].Right);
}

void InOrder(char data) {
	if (data == '.') return;

	InOrder(v[data - 'A'].Left);
	cout << data;
	InOrder(v[data - 'A'].Right);
}

void PostOrder(char data) {
	if (data == '.') return;

	PostOrder(v[data - 'A'].Left);
	PostOrder(v[data - 'A'].Right);
	cout << data;
}

int main() {

	int N = 0;

	cin >> N;

	char k = 0, l = 0, r = 0;
	for (int i = 0; i < N; i++) {
		cin >> k >> l >> r;
		v[k - 'A'].Left = l;
		v[k - 'A'].Right = r;
	}

	PreOrder('A');
	cout << "\n";

	InOrder('A');
	cout << "\n";

	PostOrder('A');
	cout << "\n";

	return 0;
}

/*
이 문제를 통해서 이진트리를 vector를 이용해서 만드는 방법을 알게 되었고, 재귀함수를 이용해서 3가지 트리순회 방법을 구현 하는 방법을 알게 되었다.
*/
