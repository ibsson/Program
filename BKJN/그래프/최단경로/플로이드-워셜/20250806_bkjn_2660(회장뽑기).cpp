#include <iostream>
#include <climits>
#include <vector>
#define INF 1e9
#define MAX 51
using namespace std;

int Dist[MAX][MAX];
int Max[MAX];

void floydFunction(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) Dist[i][j] = 0;
			else Dist[i][j] = INF;
		}
	}

	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;

		Dist[a][b] = 1;
		Dist[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}

	int _min = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Max[i] = max(Max[i], Dist[i][j]);
		}
		_min = min(_min, Max[i]);
	}

	int cnt = 0;
	vector <int> v;
	for (int i = 1; i <= N; i++) {
		if (Max[i] == _min) {
			cnt++;
			v.push_back(i);
		}
	}

	cout << _min << ' ' << cnt << '\n';
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	int N;
	cin >> N;

	floydFunction(N);

	return 0;
}
