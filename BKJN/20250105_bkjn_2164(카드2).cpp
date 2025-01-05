#include <iostream>
#include <deque>
using namespace std;

int main(void) {

	int N = 0;
	deque <int> v;

	cin >> N;

	if (N == 1) {
		cout << "1\n";
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	int tmp = 0;

	while (1) {
		v.pop_front();
		tmp = v.front();

		if (v.size() == 1) break;

		v.push_back(tmp);
		v.pop_front();
	}

	cout << tmp << "\n";

	return 0;
}
