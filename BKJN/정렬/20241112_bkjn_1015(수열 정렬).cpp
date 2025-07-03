#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int N = 0;

	cin >> N;

	int A[51] = { 0 };
	int B[51] = { 0 };
	int P[51] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = A[i];
	}

	sort(B, B + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (B[i] == A[j]) {
				P[j] = i;
				A[j] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}

	return 0;
}
