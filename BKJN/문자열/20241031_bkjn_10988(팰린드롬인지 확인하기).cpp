#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string str;

	cin >> str;

	int len = str.length();
	int check = 1;

	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[len - 1]) {
			check = 0;
			break;
		}

		len--;
	}

	cout << check << endl;

	return 0;
}
