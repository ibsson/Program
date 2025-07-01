#include <iostream>
#include <string>
using namespace std;

#define NUM 1234567891

int main() {

	long long int L;
	cin >> L;

	string str;
	cin >> str;

	long long int res = 0;

	long long int r = 1;
	for (int i = 0; i < L; i++) {
		int a = (str[i] - 'a' + 1) % NUM;
		int tmp = (a * r) % NUM;

		res = (res + tmp) % NUM;

		r = (r * (31 % NUM)) % NUM;
	}

	cout << res << "\n";

	return 0;
}

//모든 항을 modular연산을 한 후 전체를 modular연산을 하면 된다.
