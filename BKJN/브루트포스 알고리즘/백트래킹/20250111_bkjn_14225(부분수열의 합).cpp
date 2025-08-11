#include <iostream>
using namespace std;

#define MAX 21
#define MAX_SUM 2000001

int N;
int S[MAX];
int chk[MAX_SUM];

void backTracking(int cnt, int depth, int result, int startIdx) {
	if (depth == cnt) {
		if (!chk[result]) {
			chk[result] = true;
		}

		return;
	}

	if (startIdx == N) return;

	for (int i = startIdx; i < N; i++) {
		backTracking(cnt, depth + 1, result + S[i], (i + 1));
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	for (int i = 1; i <= N; i++) {
		backTracking(i, 0, 0, 0);
	}

	for (int i = 1; i <= MAX_SUM; i++) {
		if (!chk[i]) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
