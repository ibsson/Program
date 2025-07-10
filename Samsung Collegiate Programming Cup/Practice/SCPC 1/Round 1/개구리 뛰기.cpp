#include <iostream>
using namespace std;

#define MAX 1000002
#define INF 1000000002

int stone[MAX];
int DP[MAX];

void getResult(int N, int K) {
	int left = 0;
	for (int i = 1; i <= N; i++) {
		DP[i] = INF;

		while ((left < i) && (stone[left] + K < stone[i])) left++;

		if (left < i && DP[left] != INF) DP[i] = DP[left] + 1;
	}
}

int main() {
	int T;
	cin >> T;
	
	int N, K;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			cin >> stone[j];
		}

		cin >> K;

		getResult(N, K);
		
		cout << "Case #" << i << '\n';
		if (DP[N] == INF) cout << "-1\n";
		else cout << DP[N] << '\n';
	}

	return 0;
}
