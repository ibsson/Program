#include <iostream>
#include <climits>
#define MAX 501
#define INF INT_MAX
using namespace std;

bool dist[MAX][MAX];

void floydFunction(int n, int m) {
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dist[a][b] = true;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] && dist[k][j]) {
					dist[i][j] = true;
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (dist[i][j] || dist[j][i]) cnt++;
		}

		if (cnt == n - 1) res++;
	}

	cout << res << '\n';
}

int main() {
	int N, M;
	cin >> N >> M;

	floydFunction(N, M);

	return 0;
}
