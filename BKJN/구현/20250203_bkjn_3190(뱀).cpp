#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int N, K, L;
vector <pair<int, int>> apple;
queue <pair<int, char>> dir;
deque <pair<int, int>> snake;
int status = 0; //0 오른 1 아래 2 왼 3 위

bool checkApple() {
	for (int i = 0; i < apple.size(); i++) {
		if (snake[0].first == apple[i].first && snake[0].second == apple[i].second) {
			apple.erase(apple.begin() + i, apple.begin() + (i + 1));
			return true;
		}
	}

	return false;
}

bool checkCrash(int r, int c) {
	if (r == 0 || r == (N + 1) || c == 0 || c == (N + 1)) return true;
	
	for (int i = 1; i < snake.size(); i++) {
		if (r == snake[i].first && c == snake[i].second) {
			return true;
		}
	}

	return false;
}

int playGame() {
	snake.push_front({ 1, 1 });

	int t = 0;

	while (1) {
		if (!dir.empty()) {
			if (t == dir.front().first) {
				int direction = dir.front().second;
				if (direction == 'L') {
					if (status == 0) status = 3;
					else status--;
				}
				else if (direction == 'D') {
					if (status == 3) status = 0;
					else status++;
				}

				dir.pop();
			}
		}

		int next_r = 0, next_c = 0;
		t++;

		switch (status) {
		case 0:
			next_r = snake.front().first, next_c = snake.front().second + 1;

			if (checkCrash(next_r, next_c)) return t;

			snake.push_front({ next_r, next_c });

			if (!checkApple()) {
				snake.pop_back();
			}

			break;
		case 1:
			next_r = snake.front().first + 1, next_c = snake.front().second;

			if (checkCrash(next_r, next_c)) return t;

			snake.push_front({ next_r, next_c });
		
			if (!checkApple()) {
				snake.pop_back();
			}

			break;
		case 2:
			next_r = snake.front().first, next_c = snake.front().second - 1;

			if (checkCrash(next_r, next_c)) return t;

			snake.push_front({ next_r, next_c });
			
			if (!checkApple()) {
				snake.pop_back();
			}

			break;
		case 3:
			next_r = snake.front().first - 1, next_c = snake.front().second;

			if (checkCrash(next_r, next_c)) return t;

			snake.push_front({ next_r, next_c });
		
			if (!checkApple()) {
				snake.pop_back();
			}

			break;
		}
	}
}

int main(void) {

	cin >> N;
	cin >> K;

	int r = 0, c = 0;

	for (int i = 0; i < K; i++) {
		cin >> r >> c;

		apple.push_back({ r, c });
	}

	cin >> L;

	int X = 0;
	char C = 0;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;

		dir.push({ X, C });
	}

	cout << playGame() << "\n";

	return 0;
}
