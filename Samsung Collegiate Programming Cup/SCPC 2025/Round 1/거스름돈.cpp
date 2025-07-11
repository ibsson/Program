#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> v;
int coin[2]; //500, 1000
int cnt;

void solution(int N) {
	for (int i = 0; i < N; i++) {
		if (v[i] == 500) {
			coin[0]++;
			cnt++;
		}
		else if (v[i] == 1000) {
			if (coin[0] == 0) break;
			else {
				coin[0]--;
				coin[1]++;
				cnt++;
			}
		}
		else if (v[i] == 5000) {
			if (coin[1] >= 4 && coin[0] >= 1) {
				coin[1] -= 4, coin[0] -= 1;
				cnt++;
			}
			else if (coin[1] >= 3 && coin[0] >= 3) {
				coin[1] -= 3, coin[0] -= 3;
				cnt++;
			}
			else if (coin[1] >= 2 && coin[0] >= 5) {
				coin[1] -= 2, coin[0] -= 5;
				cnt++;
			}
			else if (coin[1] >= 1 && coin[0] >= 7) {
				coin[1] -= 1, coin[0] -= 7;
				cnt++;
			}
			else if (coin[0] >= 9) {
				coin[0] -= 9;
				cnt++;
			}
			else break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int N;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		int tmp;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		cout << "Case #" << i << '\n';
		solution(N);
		cout << cnt << '\n';

		memset(coin, 0, sizeof(coin));
		v.clear();
		cnt = 0;
	}

	return 0;
}
