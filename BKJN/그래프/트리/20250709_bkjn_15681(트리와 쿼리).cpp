#include <iostream>
#include <vector>
using namespace std;

#define MAX 100002

vector <int> v[MAX];
int DP[MAX];
bool visited[MAX];

void DFS(int vertex, int parent) {
	if (visited[vertex]) return;

	visited[vertex] = true;

	for (int i = 0; i < v[vertex].size(); i++) {
		DFS(v[vertex][i], vertex);
	}

	DP[parent] += DP[vertex];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;

	int U, V;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		v[U].push_back(V);
		v[V].push_back(U);
	}
	for (int i = 0; i < MAX; i++) {
		DP[i] = 1;
	}

	DFS(R, 0);

	for (int i = 0; i < Q; i++) {
		cin >> U;

		cout << DP[U] << '\n';
	}

	return 0;
}
