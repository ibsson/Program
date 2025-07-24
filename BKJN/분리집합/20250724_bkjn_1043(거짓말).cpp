#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

int person[MAX];
vector <int> know;
vector <int> party[MAX];

int Find(int x) {
	if (person[x] == x) return x;
	return x = Find(person[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	person[x] = y;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		person[i] = i;
	}

	int p;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int tmp;
		cin >> tmp;
		know.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		cin >> p;

		int cur;
		for (int j = 0; j < p; j++) {
			if (j == 0) {
				cin >> cur;
			}
			else {
				int pre;
				pre = cur;
				cin >> cur;

				Union(pre, cur);
			}

			party[i].push_back(cur);
		}
	}

	int res = M;
	for (auto i : party) {
		bool chk = false;
		for (auto j : i) {
			if (chk) break;

			for (auto k : know) {
				if (Find(j) == Find(k)) {
					chk = true;
					break;
				}
			}

			if (chk) {
				res--;
				break;
			}
		}
	}

	cout << res << '\n';

	return 0;
}
