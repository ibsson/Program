#include <iostream>
#include <vector>
#include <stack>
#define MAX 101
#define INF 1e9
using namespace std;

int Dist[MAX][MAX];
int Path[MAX][MAX];

void floydFunction() {
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else Dist[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (Dist[a][b] > c) {
			Dist[a][b] = c;
			Path[a][b] = a;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (Dist[i][j] > Dist[i][k] + Dist[k][j]) {
					Dist[i][j] = Dist[i][k] + Dist[k][j];
					Path[i][j] = Path[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Dist[i][j] == INF) cout << 0 << ' ';
			else cout << Dist[i][j] << ' ';
		}
		cout << '\n';
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || Dist[i][j] == INF) {
				cout << 0 << '\n';
				continue;
			}

			int cur = j;
			vector <int> v;
			while (cur != i) {
				v.push_back(cur);
				cur = Path[i][cur];
			}
			v.push_back(i);
			
			cout << v.size() << ' ';

			for (int k = v.size() - 1; k >= 0; k--) {
				cout << v[k] << ' ';
			}
			cout << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	floydFunction();

	return 0;
}
