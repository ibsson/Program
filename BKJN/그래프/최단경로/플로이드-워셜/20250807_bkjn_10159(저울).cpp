#include <iostream>
#define MAX 101
using namespace std;

bool visited[MAX][MAX];
int cnt[MAX];

void floydFunction(int N, int M) {
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		visited[a][b] = true;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][k] && visited[k][j])
					visited[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (!visited[i][j] && !visited[j][i]) cnt++;
		}
		cout << cnt << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;
	cin >> M;

	floydFunction(N, M);

	return 0;
}
