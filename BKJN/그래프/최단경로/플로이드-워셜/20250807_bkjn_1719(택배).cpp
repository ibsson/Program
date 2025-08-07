#include <iostream>
#define MAX 201
#define INF 1e9
using namespace std;

int Dist[MAX][MAX];
int Path[MAX][MAX];

void floydFunction() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else Dist[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		Dist[a][b] = c;
		Dist[b][a] = c;
		Path[a][b] = b;
		Path[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (Dist[i][j] > Dist[i][k] + Dist[k][j]) {
					Dist[i][j] = Dist[i][k] + Dist[k][j];
					Path[i][j] = Path[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Dist[i][j] == 0) cout << '-' << ' ';
			else cout << Path[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	floydFunction();

	return 0;
}
