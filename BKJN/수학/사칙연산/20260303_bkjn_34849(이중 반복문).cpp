#include <iostream>
using namespace std;

int main(void) {
	long long N;
	cin >> N;

	if (N * N > 100000000) cout << "Time limit exceeded\n";
	else cout << "Accepted\n";

	return 0;
}
