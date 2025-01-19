#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX 21

int N;
int status[MAX][MAX];
bool visited[MAX];
int start, link, minResult = INT_MAX;
vector <int> rest;

void backTracking(int idx, int cnt) {
	if (cnt == (N / 2)) {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				rest.push_back(i);
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (visited[i] && visited[j]) {
					start += status[i][j] + status[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					link += status[i][j] + status[j][i];
				}
			}
		}

		minResult = min(minResult, abs(start - link));

		rest.clear();
		start = 0, link = 0;

		return;
	}

	for (int i = idx; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			backTracking(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> status[i][j];
		}
	}

	backTracking(1, 0);

	cout << minResult << "\n";

	return 0;
}
