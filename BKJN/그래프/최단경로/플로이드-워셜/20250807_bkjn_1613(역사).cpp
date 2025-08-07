#include <iostream>
#define MAX 401
using namespace std;

bool visited[MAX][MAX];

void floydFunction() {
	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visited[a][b] = true;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i][k] && visited[k][j]) {
					visited[i][j] = true;
				}
			}
		}
	}

	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		
		if (visited[a][b]) {
			cout << -1 << '\n';
		}
		else if (visited[b][a]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
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
