#include <iostream>
#include <queue>
using namespace std;

queue <pair<int, string>> Q; //레지스터, 명령어
bool visited[10001];

void D(int res, string sequence) {
	int tmp = res;

	tmp = (tmp * 2) % 10000;
	if (visited[tmp]) return;
	else visited[tmp] = true;
	Q.push({ tmp, sequence + 'D' });
}

void S(int res, string sequence) {
	int tmp = res;

	tmp--;
	if (tmp < 0) tmp = 9999;

	if (visited[tmp]) return;
	else visited[tmp] = true;

	Q.push({ tmp, sequence + 'S' });
}

void L(int res, string sequence) {
	int tmp = ((res % 1000) * 10) + (res / 1000);
	

	if (visited[tmp]) return;
	else visited[tmp] = true;

	Q.push({ tmp, sequence + 'L' });
}

void R(int res, string sequence) {
	int tmp = ((res % 10) * 1000) + (res / 10);

	if (visited[tmp]) return;
	else visited[tmp] = true;

	Q.push({ tmp, sequence + 'R' });
}

int main() {
	int T = 0;
	cin >> T;

	int A, B;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		Q.push({ A, "" });

		int tmp_n, res;
		string sequence;
		while (!Q.empty()) {
			res = Q.front().first;
			sequence = Q.front().second;
			Q.pop();

			if (res == B) {
				cout << sequence << "\n";
				while (!Q.empty()) {
					Q.pop();
				}

				break;
			}

			D(res, sequence);
			S(res, sequence);
			L(res, sequence);
			R(res, sequence);
		}

		for (int j = 0; j < 10000; j++) {
			visited[j] = false;
		}
	}

	return 0;
}
