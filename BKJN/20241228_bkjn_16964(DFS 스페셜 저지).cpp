#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100002

int N, cnt;
vector <int> v[MAX];
int num[MAX];
bool Visited[MAX];
bool same = true;

void DFS(int X) {
	if (!same) return;

	Visited[X] = true;
	cnt++;

	if (num[X] != cnt) {
		same = false;
		return;
	}

	for (int i = 0; i < v[X].size(); i++) {
		int next = v[X][i];

		if (!Visited[next]) {
			DFS(next);
		}
	}
}

bool Compare(int a, int b) {
	return num[a] < num[b];
}

int main(void) {

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

	DFS(1);

	cout << same << "\n";

	return 0;
}
