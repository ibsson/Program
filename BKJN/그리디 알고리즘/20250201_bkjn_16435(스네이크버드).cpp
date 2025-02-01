#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int len[1001];

int main() {

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> len[i];
	}

	sort(len, len + N);

	for (int i = 0; i < N; i++) {
		if (L < len[i]) break;
		else L++;
	}

	cout << L << "\n";

	return 0;
}
