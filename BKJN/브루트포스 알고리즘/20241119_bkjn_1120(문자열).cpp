#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string A;
	string B;

	cin >> A >> B;

	int dif = B.length() - A.length();
	int min = 100;

	for (int i = 0; i <= dif; i++) {
		int cnt = 0;
		int tmp = i;
		for (int j = 0; j < A.length(); j++) {
			if (A[j] != B[tmp]) {
				cnt++;
			}
			tmp++;
		}
		if (min > cnt) min = cnt;
	}

	cout << min << endl;

	return 0;
}
