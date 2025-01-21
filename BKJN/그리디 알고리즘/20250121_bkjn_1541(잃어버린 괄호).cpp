#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
string num[51];
vector <int> x;
vector <char> v;

int main(void) {

	cin >> str;

	int idx = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num[idx] += str[i];
		}
		else {
			v.push_back(str[i]);
			x.push_back(stoi(num[idx]));
			idx++;
		}
	}
	x.push_back(stoi(num[idx]));

	bool chk = false;
	int sum = x[0];

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '-') chk = true;

		if (!chk) {
			sum += x[i + 1];
		}
		else {
			sum -= x[i + 1];
		}
	}

	cout << sum << "\n";

	return 0;
}
