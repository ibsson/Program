#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char map[26][26];
int visited[26][26];
int N, cnt;
int Move[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

void DFS(int x, int y);

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	vector <int> result;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt++;
				DFS(j, i);
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}

void DFS(int x, int y) {

	for (int i = 0; i < 4; i++) {
		if (map[y + Move[i][0]][x + Move[i][1]] == '1' && visited[y + Move[i][0]][x + Move[i][1]] == 0) {
			visited[y + Move[i][0]][x + Move[i][1]] = 1;
			cnt++;
			DFS(x + Move[i][1], y + Move[i][0]);
		}
	}
}

/*
이 문제는 상하좌우 움직이는 행동을 할때 방향별로 움직이는 만큼 상하좌우 배열에다가 넣어놓고 사용하면 편하다는것을 깨닫게 해준 문제였다.
또한 DFS의 사용법을 잘 이해할 수 있던 문제였던 것 같다.
*/
