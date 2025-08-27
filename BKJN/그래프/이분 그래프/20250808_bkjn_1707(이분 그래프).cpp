#include <iostream>
#include <vector>
#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

vector <int> graph[MAX];
int visited[MAX];

bool isBinGraph(int V) {
	for (int cur = 1; cur <= V; cur++) {
		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];

			if (visited[cur] == visited[next]) return false;
		}
	}

	return true;
}

void DFS(int cur) {
	if (!visited[cur]) visited[cur] = RED;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		if (!visited[next]) {
			if (visited[cur] == RED) visited[next] = BLUE;
			else if (visited[cur] == BLUE) visited[next] = RED;

			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;
	
	for (int t = 1; t <= K; t++) {
		int V, E;
		cin >> V >> E;
		
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		
		if (isBinGraph(V)) cout << "YES\n";
		else cout << "NO\n";

		for (int i = 1; i <= V; i++) {
			graph[i].clear();
			visited[i] = 0;
		}
	}

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

vector <int> graph[MAX];
int visited[MAX];

void DFS(int cur) {
	if (!visited[cur]) visited[cur] = RED;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		if (!visited[next]) {
			if (visited[cur] == RED) visited[next] = BLUE;
			else if (visited[cur] == BLUE) visited[next] = RED;

			DFS(next);
		}
	}
}

bool isBinGraph(int V) {
	for (int cur = 1; cur <= V; cur++) {
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (visited[cur] == visited[next]) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;

	for (int t = 1; t <= K; t++) {
		int V, E;
		cin >> V >> E;

		int u, v;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (!visited[i]) DFS(i);
		}

		if (isBinGraph(V)) cout << "YES\n";
		else cout << "NO\n";

		for (int i = 1; i <= V; i++) {
			graph[i].clear();
			visited[i] = false;
		}
	}

	return 0;
}
*/
