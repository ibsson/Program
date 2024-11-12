#include <iostream>
using namespace std;

int num[200001] = { 0 };

int main(void) {

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int min = num[0], result = -1;

	for (int i = 0; i < N; i++) {
		if (min > num[i]) min = num[i];

		if (result < num[i] - min) result = num[i] - min;
	}

	cout << result << endl;

	return 0;
}
