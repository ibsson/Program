#include <iostream>
#include <vector>
using namespace std;

vector <int> pre;
vector <int> in;

void getPost(int start, int end, int pos) {
	for (int i = start; i < end; i++) {
		if (in[i] == pre[pos]) {
			getPost(start, i, pos + 1);
			getPost(i + 1, end, pos + 1 + (i - start));
			cout << pre[pos] << ' ';
		}
	}
}

void solve(int n) {
	getPost(0, n, 0);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int n;
	for (int t = 1; t <= T; t++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			pre.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			in.push_back(tmp);
		}

		solve(n);

		pre.clear();
		in.clear();
	}

	return 0;
}
