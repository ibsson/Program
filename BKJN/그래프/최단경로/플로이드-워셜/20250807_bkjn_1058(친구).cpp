#include <iostream>
#define MAX 51
using namespace std;

string str[MAX];
bool visited[MAX][MAX];

void floydFunction(int N) {
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		bool isFriend[MAX] = { false };

		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (str[i][j] == 'Y') {
				isFriend[j] = true;
			}
			else {
				for (int k = 0; k < N; k++) {
					if (str[i][k] == 'Y' && str[k][j] == 'Y') {
						isFriend[j] = true;
						break;
					}
				}
			}
		}

		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (isFriend[j]) cnt++;
		}

		res = max(res, cnt);
	}

	cout << res << '\n';
}

int main() {
	int N;
	cin >> N;

	floydFunction(N);

	return 0;
}
