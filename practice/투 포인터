#include <iostream>
using namespace std;

#define MAX 10001

int A[MAX];
int N, M, cnt;

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int start = 0, end = 0;
	int result = A[0];

	while (start <= end && end < N) {
		if (result < M) {
			result += A[++end];
		}
		else if (result == M) {
			cnt++;
			result += A[++end];
		}
		else if (result > M) {
			result -= A[start++];

			if (start > end) {
				end = start;
				result = A[start];
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}
