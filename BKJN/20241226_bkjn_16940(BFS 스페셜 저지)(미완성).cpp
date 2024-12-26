#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100001

int N;
vector <int> v[MAX];
int num[MAX];
int arr[MAX];
bool Visited[MAX];
int cnt;
bool same = true;

void BFS(int x) {
	queue <int> q;

	q.push(x);
	Visited[x] = true;

	while (!q.empty()) {
		int X = q.front();
		arr[cnt] = X;
		cnt++;
		q.pop();

		if (cnt == N) {
			for (int i = 0; i < N; i++) {
				if (num[i] != arr[i]) {
					same = false;
					break;
				}
			}
			break;
		}

		for (int i = 0; i < v[X].size(); i++) {
			if (!Visited[v[X][i]]) {
				q.push(v[X][i]);
				Visited[i + 1] = true;
			}
		}
	}
}

bool Compare(int& a, int& b) {
	return num[a] < num[b];
}

int main(void) {

	cin >> N;

	int a = 0, b = 0;

	for (int i = 0; i < (N - 1); i++) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		int x = 0;
		cin >> x;
		num[x] = i;
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), Compare);
	}

	BFS(1);

	if (same) cout << "1" << "\n";
	else cout << "0" << "\n";

	return 0;
}
