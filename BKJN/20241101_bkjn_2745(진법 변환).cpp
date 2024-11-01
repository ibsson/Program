#include <iostream>
#include <string>
using namespace std;

int main(void) {

	int B = 0;
	string N;

	cin >> N >> B;

	int sum = 0, tmp = 1;

	for (int i = (N.length() - 1); i >= 0; i--) {
		tmp = 1;

		if (N[i] >= 'A' && N[i] <= 'Z') {
			for (int j = i; j < (N.length() - 1); j++) {
				tmp *= B;
			}
			sum += (10 + N[i] - 'A') * tmp;
		}
		else if (N[i] >= '0' && N[i] <= '9') {
			for (int j = i; j < (N.length() - 1); j++) {
				tmp *= B;
			}
			sum += (N[i] - '0') * tmp;
		}
	}

	cout << sum << endl;

	return 0;
}
