#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int N = 0, M = 0;
	int P[1001] = { 0 };

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> P[i];
	}

	sort(P, P + M);

	long long int max = -1;
	int tmp = 0;

	for (int i = 0; i < M; i++) {
		if ((M - i) <= N) {
			if (max < P[i] * (M - i)) {
				max = P[i] * (M - i);
				tmp = P[i];
			}
		}
		else if ((M - i) > N) {
			if (max < P[i] * N) {
				max = P[i] * N;
				tmp = P[i];
			}
		}
	}

	cout << tmp << " " << max << endl;

	return 0;
}
