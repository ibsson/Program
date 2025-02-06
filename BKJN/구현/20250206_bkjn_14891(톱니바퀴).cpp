#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int N;
pair<int, int> status[4];
int direction[4];
bool visited[4];
deque <int> wheel[4];

void chkStatus() {
	for (int j = 0; j < 3; j++) {
		if (wheel[j][2] != wheel[j + 1][6]) {
			status[j].second = 1;
			status[j + 1].first = 1;
		}
		else {
			status[j].second = 0;
			status[j + 1].first = 0;
		}
	}
}

void dfs(int idx, int dir) {
	if (idx < 0 || idx > 3) return;
	if (visited[idx]) return;

	visited[idx] = true;
	direction[idx] = dir;

	if (status[idx].first) {
		if (dir == -1) dfs(idx - 1, 1);
		else dfs(idx - 1, -1);

	}
	if (status[idx].second) {
		if (dir == -1) dfs(idx + 1, 1);
		else dfs(idx + 1, -1);
	}
}

void turn(int idx) {
	if (direction[idx] == 0) return;
	else if (direction[idx] == 1) {
		wheel[idx].push_front(wheel[idx].back());
		wheel[idx].pop_back();
	}
	else if (direction[idx] == -1) {
		wheel[idx].push_back(wheel[idx].front());
		wheel[idx].pop_front();
	}
}

int main() {

	string tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			wheel[i].push_back(tmp[j] - '0');
		}
	}

	int K = 0;
	cin >> K;

	int num = 0, dir = 0;

	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		chkStatus();
		dfs(num - 1, dir);

		for (int j = 0; j < 4; j++) {
			turn(j);
		}

		memset(visited, false, sizeof(visited));
		memset(status, false, sizeof(status));
		memset(direction, 0, sizeof(direction));
	}

	int result = 0;

	if (wheel[0][0] == 1) result += 1;
	if (wheel[1][0] == 1) result += 2;
	if (wheel[2][0] == 1) result += 4;
	if (wheel[3][0] == 1) result += 8;

	cout << result << "\n";

	return 0;
}
