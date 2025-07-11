#include <iostream>
using namespace std;

#define MOD 1000000007

long long int solution(int N) {
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		int tmp = i;
		bool chk = true;
		while (tmp > 0) {
			if (tmp % 10 != 0 && tmp % 10 != 1 && tmp % 10 != 2) {
				chk = false;
				break;
			}
			tmp /= 10;
		}

		if (chk) {
			cnt++;
			cnt %= MOD;
		}
	}

	return cnt;
}

int main() {
	int T;
	cin >> T;

	int N;
	for (int t = 1; t <= T; t++) {
		cin >> N;
	
		cout << "Case #" << t << '\n';
		cout << solution(N) << '\n';
	}

	return 0;
}
