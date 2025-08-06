#include <iostream>
#include <climits>
#include <vector>
#define MAX 401
#define INF 1e9
using namespace std;

int dist[MAX][MAX];
bool visited[MAX];
vector <int> v[MAX];

void floydFunction(int V, int E) {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			dist[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	
	int res = INF;
	for (int i = 1; i <= V; i++) {
		res = min(res, dist[i][i]);
	}

	if (res == INF) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	int V, E;
	cin >> V >> E;

	floydFunction(V, E);

	return 0;
}
