#include <iostream>
#include <stack>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 100001

int N, K;
bool Visited[MAX];

stack<tuple<int, int, int>> s;
queue<tuple<int, int, int>> q;

void Find_Pre() {
	stack<int> stk;

	int _X = get<0>(s.top());
	int _Pre = get<1>(s.top());
	int _time = get<2>(s.top());
	s.pop();
	stk.push(_X);

	while (!s.empty()) {
		int tmp_1 = get<0>(s.top());
		int tmp_2 = get<2>(s.top());

		if (tmp_1 == _Pre && tmp_2 == _time - 1) {
			_X = get<0>(s.top());
			_Pre = get<1>(s.top());
			_time = get<2>(s.top());

			stk.push(_X);
			s.pop();
		}
		else s.pop();
	}

	while (!stk.empty()) {
		int tmp = stk.top();
		stk.pop();
		cout << tmp << " ";
	}
	cout << "\n";
}

void BFS() {
	q.push(make_tuple(N, 0, 0));

	while (!q.empty()) {
		int X = get<0>(q.front());
		int Pre = get<1>(q.front());
		int time = get<2>(q.front());

		s.push(make_tuple(X, Pre, time));
		q.pop();
		Visited[X] = true;

		if (X == K) {
			cout << time << "\n";
			while (!q.empty()) {
				q.pop();
			}
			
			Find_Pre();

			break;
		}

		if ((X - 1) >= 0 && (X - 1) <= 100000) {
			if (!Visited[X - 1]) {
				q.push(make_tuple(X - 1, X, time + 1));
			}
		}
		if ((X + 1) >= 0 && (X + 1) <= 100000) {
			if (!Visited[X + 1]) {
				q.push(make_tuple(X + 1, X, time + 1));
			}
		}
		if ((X * 2) >= 0 && (X * 2) <= 100000) {
			if (!Visited[X * 2]) {
				q.push(make_tuple(X * 2, X, time + 1));
			}
		}
	}
}

int main(void) {

	cin >> N >> K;

	BFS();

	return 0;
}

/*
BFS와 stack을 이용해서 구현했다.
*/
