#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define MAX 501
#define INF LLONG_MAX
using namespace std;

struct Node {
	int start, dest, cost;
};

long long int Dist[MAX];
vector <Node> Edge;
int N, M;

void bellmanFord() {
	Dist[1] = 0;

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < Edge.size(); j++) {
			int from = Edge[j].start, to = Edge[j].dest, cost = Edge[j].cost;

			if (Dist[from] == INF) continue;
			if (Dist[to] > Dist[from] + cost) Dist[to] = Dist[from] + cost;
		}
	}

	for (int i = 0; i < Edge.size(); i++) {
		int from = Edge[i].start, to = Edge[i].dest, cost = Edge[i].cost;

		if (Dist[from] == INF) continue;
		if (Dist[to] > Dist[from] + cost) {
			cout << -1 << '\n';
			return;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (Dist[i] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << Dist[i] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		Dist[i] = INF;
	}

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;

		Edge.push_back({ A, B, C });
	}

	bellmanFord();

	return 0;
}
