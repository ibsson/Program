#include <iostream>
#include <deque>
using namespace std;

#define MAX 101

int level = 1;
int N, K;
deque <int> A;
int robot[MAX];

int main() {

	cin >> N >> K;
	
	int x = 0;
	for (int i = 0; i < N * 2; i++) {
		cin >> x;
		A.push_back(x);
	}

	int level = 0;

	while (1) {
		level++;

		A.push_front(A.back());
		A.pop_back();

		for (int i = (N - 1); i >= 0; i--) {
			robot[i] = robot[i - 1];
			robot[i - 1] = 0;

			if (i == (N - 1)) robot[i] = 0;
		}

		for (int i = (N - 1); i >= 0; i--) {
			if (robot[i - 1] == 1) {
				if (A[i] > 0 && robot[i] != 1) {
					robot[i] = robot[i - 1];
					robot[i - 1] = 0;
					A[i]--;
				}

				if (i == (N - 1)) robot[i] = 0;
			}
		}

		if (A[0] != 0) {
			robot[0] = 1;
			A[0]--;
		}

		int cnt = 0;
		for (int i = 0; i < N * 2; i++) {
			if (A[i] == 0) cnt++;

			if (cnt >= K) {
				cout << level << "\n";
				return 0;
			}
		}
	}
}
