#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;

		v.insert(v.begin() + tmp, i);
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	return 0;
}
