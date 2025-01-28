#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> v;

int main() {

	cin >> N;

	int x = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int len = 0;

	for (int i = 0; i < N; i++) {
		if ((len + 1) >= v[i]) len += v[i];
		else break;
	}

	cout << len + 1 << "\n";

	return 0;
}
