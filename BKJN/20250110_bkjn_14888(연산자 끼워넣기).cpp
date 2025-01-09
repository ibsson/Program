#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int num[12];
int visited[12];
int maxResult = INT_MIN, minResult = INT_MAX;
vector <char> v;

void backTracking(int idx, int result) {
	if (idx == N) {
		maxResult = max(maxResult, result);
		minResult = min(minResult, result);
		return;
	}

	for (int i = 0; i < (N - 1); i++) {
		if (!visited[i]) {
			visited[i] = true;

			if (v[i] == '+') {
				backTracking(idx + 1, result + num[idx]);
				visited[i] = false;
			}
			else if (v[i] == '-') {
				backTracking(idx + 1, result - num[idx]);
				visited[i] = false;
			}
			else if (v[i] == '*') {
				backTracking(idx + 1, result * num[idx]);
				visited[i] = false;
			}
			else if (v[i] == '/') {
				if (result < 0) {
					backTracking(idx + 1, -(-(result) / num[idx]));
					visited[i] = false;
				}
				else {
					backTracking(idx + 1, result / num[idx]);
					visited[i] = false;
				}
			}
		}
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int p = 0, o = 0, m = 0, d = 0;

	cin >> p >> o >> m >> d;

	for (int i = 0; i < p; i++) {
		v.push_back('+');
	}
	for (int i = 0; i < o; i++) {
		v.push_back('-');
	}
	for (int i = 0; i < m; i++) {
		v.push_back('*');
	}
	for (int i = 0; i < d; i++) {
		v.push_back('/');
	}

	backTracking(1, num[0]);

	cout << maxResult << "\n";
	cout << minResult << "\n";

	return 0;
}
