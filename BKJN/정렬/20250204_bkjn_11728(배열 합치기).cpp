#include <iostream>
using namespace std;

#define MAX 1000001

int A[MAX];
int B[MAX];
int result[MAX];
int N, M;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	int a = 0, b = 0, k = 0;

	while (a < N && b < M) {
		if (A[a] <= B[b]) {
			result[k++] = A[a++];
		}
		else if (A[a] > B[b]) {
			result[k++] = B[b++];
		}
	}
	while (a < N) {
		result[k++] = A[a++];
	}
	while (b < M) {
		result[k++] = B[b++];
	}

	for (int i = 0; i < N + M; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
