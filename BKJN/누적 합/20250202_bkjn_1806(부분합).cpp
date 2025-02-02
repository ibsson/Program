#include <iostream>
using namespace std;

#define MAX 100001

int N, S;
int A[MAX];

int main() {

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int start = 0, end = 0, result = MAX;
	int sum = A[0];

	while (start <= end && end < N) {
		if (sum < S) {
			sum += A[++end];
		}
		else if (sum >= S) {
			result = min(result, end - start + 1);

			sum -= A[start++];

			if (start > end) {
				end = start;
				sum = A[start];
			}
		}
	}

	if (result == MAX) cout << "0\n";
	else cout << result << "\n";

	return 0;
}
