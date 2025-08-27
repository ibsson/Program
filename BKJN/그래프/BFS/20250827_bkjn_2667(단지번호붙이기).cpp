#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

string str[MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int N;

vector <int> v;

struct Node {
	int y, x;
};

int BFS(int i, int j) {
	queue <Node> q;
	visited[i][j] = true;
	q.push({ i, j });

	int cnt = 1;
	while (!q.empty()) {
		int y = q.front().y, x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (str[ny][nx] == '0') continue;

			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (str[i][j] == '1') {
				if (!visited[i][j]) {
					v.push_back(BFS(i, j));
					num++;
				}
			}
		}
	}

	sort(v.begin(), v.end());

	cout << num << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
