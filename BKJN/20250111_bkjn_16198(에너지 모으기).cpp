#include <iostream>
#include <vector>
using namespace std;

int N, _max;
vector <int> v;

void dfs(int result) {

	if (v.size() == 2) {
		_max = max(_max, result);
	}

	for (int i = 1; i < v.size() - 1; i++) {
		int tmp1 = v[i];
		int tmp2 = v[i - 1] * v[i + 1];
		v.erase(v.begin() + i);
		dfs(result + tmp2);
		v.insert(v.begin() + i, tmp1);
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x = 0;
		cin >> x;
		v.push_back(x);
	}

	dfs(0);

	cout << _max << "\n";

	return 0;
}
