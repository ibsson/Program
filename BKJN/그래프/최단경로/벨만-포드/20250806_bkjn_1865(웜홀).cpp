#include <iostream>
#include <vector>
#include <climits>
#define MAX 501
#define INF INT_MAX
using namespace std;

struct Node {
	int S, E, T;
};

int Dist[MAX];

bool bellmanFord(vector<Node>& Edge, int N) {
	for (int i = 0; i <= N; i++) {
		Dist[i] = INF;
	}
	Dist[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Edge.size(); j++) {
			int from = Edge[j].S, to = Edge[j].E, time = Edge[j].T;
			if (Dist[from] == INF) continue;
			if (Dist[to] > Dist[from] + time) {
				Dist[to] = Dist[from] + time;
			}
		}
	}

	for (int i = 0; i < Edge.size(); i++) {
		int from = Edge[i].S, to = Edge[i].E, time = Edge[i].T;
		if (Dist[from] == INF) continue;
		if (Dist[to] > Dist[from] + time) return true;
	}

	return false;
}

int main() {
	int TC;
	cin >> TC;

	int N, M, W;
	int S, E, T;
	for (int t = 0; t < TC; t++) {
		vector<Node> Edge;

		cin >> N >> M >> W;

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			Edge.push_back({ S, E, T });
			Edge.push_back({ E, S, T });
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			Edge.push_back({ S, E, -T });
		}

		for (int i = 1; i <= N; i++) {
			Edge.push_back({ 0, i, 0 });
		}

		if (bellmanFord(Edge, N)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
