#include <iostream>
#include <queue>
using namespace std;

int sum;
int A, B, C;
bool visited[1001][1001];

int bfs() {
	queue <pair<int, int>> q;
	q.push({ A, B });
	visited[A][B] = true;

	while (!q.empty()) {
		int ca = q.front().first;
		int cb = q.front().second;
		int cc = sum - (ca + cb);
		q.pop();

		if (ca == cb && ca == cc) return 1;

		int nx[3] = { ca, ca, cb };
		int ny[3] = { cb, cc, cc };

		for (int i = 0; i < 3; i++) {
			int na = nx[i];
			int nb = ny[i];

			if (na < nb) {
				nb -= na;
				na += na;
			}
			else if (na > nb) {
				na -= nb;
				nb += nb;
			}
			else {
				continue;
			}

			int nc = sum - (na + nb);

			int ra = min(min(na, nb), nc);
			int rb = max(max(na, nb), nc);

			if (!visited[ra][rb]) {
				q.push({ ra, rb });
				visited[ra][rb] = true;
			}
		}
	}

	return 0;
}

int main(void) {

	cin >> A >> B >> C;

	sum = A + B + C;

	int chk = bfs();

	cout << chk << "\n";

	return 0;
}

/*
인수가 3개라서 visited를 3차원배열로 사용하려 했지만 무리일 것 같아서 다른방법을 생각해봤지만 생각이 나지 않았다.
그래서 검색을 해서 풀었다.
A B C의 합은 항상 일정하기 때문에 그것을 이용해서 풀면 visited를 2차원 배열을 사용해서 풀리는 문제였다.
이런 생각을 해낼 수 있게 문제를 계속 손으로 풀어보면서 더 유심히 보고 공통점을 찾고 분석해보는 습관을 들여야겠다.
*/
