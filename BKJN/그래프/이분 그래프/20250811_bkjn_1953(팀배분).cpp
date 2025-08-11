#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define RED 1
#define BLUE 2
using namespace std;

vector <int> graph[MAX];
int color[MAX];

vector <int> white;
vector <int> blue;

void DFS(int cur) {
	if (!color[cur]) color[cur] = RED;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		if (!color[next]) {
			if (color[cur] == RED) color[next] = BLUE;
			else color[next] = RED;

			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			graph[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!color[i]) DFS(i);
	}

	for (int i = 1; i <= n; i++) {
		if (color[i] == RED) white.push_back(i);
		else blue.push_back(i);
	}

	sort(white.begin(), white.end());
	sort(blue.begin(), blue.end());

	cout << white.size() << '\n';
	for (int i = 0; i < white.size(); i++) {
		cout << white[i] << ' ';
	}
	cout << '\n';

	cout << blue.size() << '\n';
	for (int i = 0; i < blue.size(); i++) {
		cout << blue[i] << ' ';
	}
	cout << '\n';

	return 0;
}
