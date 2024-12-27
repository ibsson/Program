#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100002

vector <int> v[MAX];
int num[MAX];
int arr[MAX];
bool Visited[MAX];
int cnt = 1;
bool same = true;

int BFS(int x) {
	queue <int> q;

	q.push(x);
	Visited[x] = true;

	while (!q.empty()) {
		int _x = q.front();
		arr[cnt] = _x;

		if (num[_x] != cnt) {
			return 0;
		}

		cnt++;
		q.pop();

		for (int i = 0; i < v[_x].size(); i++) {
			int next = v[_x][i];

			if (!Visited[next]) {
				q.push(next);
				Visited[next] = true;
			}
		}
	}

	return 1;
}

bool Compare(int& a, int& b) {
	return num[a] < num[b];
}

int main(void) {

	int N = 0;
	cin >> N;

	int from = 0, to = 0;

	for (int i = 0; i < (N - 1); i++) {
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		int x = 0;
		cin >> x;
		num[x] = i;
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), Compare);
	}

	cout << BFS(1) << "\n";

	return 0;
}

/*
이 문제를 통해 sort STL의 사용자지정 함수인 compare의 작동 원리를 이해하게 되었다.
인접리스트에서 노드들의 순서대로 방문한다는 것을 이용해서 내가 검사하려는 순서를 기준으로 각 노드들을 정렬하고 풀면 되는 문제였다.
정말 어려운 문제였지만 얻어가는것도 굉장히 많은 문제였던 것 같다.
앞으로 정렬을 할때 기준을 내가 원하는대로 설정 할 수 있을 것 같다.
*/
