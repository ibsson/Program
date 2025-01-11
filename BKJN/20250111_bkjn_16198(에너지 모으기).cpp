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

/*
v.begin() + 0 이 첫번째 index이고, v.begin() + 1이 두번째 index이다.
만약 1 2 3에서 v.erase(v.begin() + 1)을 하면 1 3이 되고,
1 2 3에서 v.insert(v.begin() + 2, 5)를 하면 1 2 4 3이 된다.
*/
