#include <iostream>
using namespace std;

#define MAX 22

int grid[MAX][MAX];
bool visited[MAX][MAX];

int people[5];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
		}
	}

	int res = 10000000;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					int _max = -1, _min = 10000000;

					if ((1 <= x && x < x + d1 + d2 && x + d1 + d2 <= N) && (1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= N)) {
						// 5번 선거구 경계선 그리기
						for (int i = 0; i <= d1; i++) {
							visited[x + i][y - i] = true;
							visited[x + d2 + i][y + d2 - i] = true;
						}
						for (int i = 0; i <= d2; i++) {
							visited[x + i][y + i] = true;
							visited[x + d1 + i][y - d1 + i] = true;
						}

						// 5번 선거구 내부 채우기
						for (int i = x + 1; i < x + d1 + d2; i++) {
							bool isInside = false;
							for (int j = 1; j <= N; j++) {
								if (visited[i][j]) isInside = !isInside;
								if (isInside) {
									visited[i][j] = true;
									people[4] += grid[i][j];
								}
							}
						}
						_max = max(_max, people[4]);
						_min = min(_min, people[4]);

						//1번 선거구
						for (int i = 1; i < (x + d1); i++) {
							for (int j = 1; j <= y; j++) {
								people[0] += grid[i][j];
								visited[i][j] = true;
							}
						}
						_max = max(_max, people[0]);
						_min = min(_min, people[0]);

						//2번 선거구
						for (int i = 1; i < (x + d2); i++) {
							for (int j = y + 1; j <= N; j++) {
								people[1] += grid[i][j];
								visited[i][j] = true;
							}
						}
						_max = max(_max, people[1]);
						_min = min(_min, people[1]);

						//3번 선거구
						for (int i = x + d1; i <= N; i++) {
							for (int j = 1; j < y - d1 + d2; j++) {
								people[2] += grid[i][j];
								visited[i][j] = true;
							}
						}
						_max = max(_max, people[2]);
						_min = min(_min, people[2]);

						//4번 선거구
						for (int i = (x + d2 + 1); i <= N; i++) {
							for (int j = y - d1 + d2; j <= N; j++) {
								people[3] += grid[i][j];
								visited[i][j] = true;
							}
						}
						_max = max(_max, people[3]);
						_min = min(_min, people[3]);
					}
					else break;

					res = min(res, _max - _min);

					for (int i = 1; i <= N; i++) {
						for (int j = 1; j <= N; j++) {
							visited[i][j] = false;
						}
					}

					for (int i = 0; i < 5; i++) {
						people[i] = 0;
					}
				}
			}
		}
	}

	cout << res << '\n';

	return 0;
}
