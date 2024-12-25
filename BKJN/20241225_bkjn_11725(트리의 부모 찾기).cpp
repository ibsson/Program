#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

vector <int> v[MAX];

bool Visited[MAX];
int arr[MAX];

void DFS(int x) {

	Visited[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!Visited[next]) {
			arr[next] = x;
			DFS(next);
		}
	}
}

int main(void) {

	int N = 0;

	cin >> N;

	int a = 0, b = 0;

	for (int i = 0; i < (N - 1); i++) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}
